#include"servo_control_node.h"
#include"headfile_pkg/headfile.h"
#include<vector>
#include<control_pkg/servo_control.h>

#define SERVO_ID 0x01
#define WING_TRANS_ANGLE 5000 //机翼变结构时两侧舵机要转过的角度
#define MOTOR_TRANS_ANGLE 45  //推进器变结构时四个舵机要转过的角度
LibSerial::SerialPort ser;//全局公用的串口对象
//本节点主要实现舵机角度的监控和机翼姿态的转换


int kbhit(){
    struct termios oldt,newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO,&oldt);
    newt=oldt;
    newt.c_lflag&=~(ICANON | ECHO);//非缓冲，无回显
    tcsetattr(STDIN_FILENO,F_GETFL,0);
    fcntl(STDIN_FILENO,F_SETFL, oldf | O_NONBLOCK);
    ch=getchar();
    tcsetattr(STDIN_FILENO,TCSANOW,&oldt);

    if(ch!=EOF){
        ungetc(ch,stdin);
        return 1;
    }
    return 0;
}

/**
 * @brief 手动幂函数，返回值为整数
 * 
 * @param a 
 * @param b 
 * @return int 
 */
int pow_int(int a,int b){
    if(b==0){
        return 1;
    }
    else if(b==1){
        return a;
    }
    for(int i=1;i<b;i++){
        a*=a;
    }
    return a;
}
std::vector<uint8_t> angle_transform_inverse(int angle){
    std::vector<uint8_t> bytes;
    int32_t angle_scaled=angle*10;

    bytes.push_back(angle_scaled & 0xFF);
    bytes.push_back((angle_scaled>>8) & 0xFF);
    bytes.push_back((angle_scaled>>16) & 0xFF);
    bytes.push_back((angle_scaled>>24) & 0xFF);

    return bytes;
}
/**
 * @brief 用于转换通信协议中的小端序数为实际角度
 * 
 * @param buffer
 * @return float 
 */
float angle_transform(const std::vector<uint8_t>& buffer){
    int t=0;//手动小端解析幂次数
    int angle=0;
    for(int i=5;i<9;i++){
        angle+=buffer[i]*pow_int(16,t);
    }
    return angle/10;//根据通信协议，实际角度要/10
}
/**
 * @brief 获得当前舵机的角度
 * 
 * @param servo_id 
 * @param ser 
 */
float get_angle(int servo_id,LibSerial::SerialPort &ser){
    std::vector<uint8_t> request_buff={0x12,0x4C,0x10,0x01,SERVO_ID};
    uint8_t check_sum=0;
    for(auto val:request_buff){
        check_sum+=val;
    }
    request_buff.push_back(check_sum%256);
    ser.Write(request_buff);
    std::vector<uint8_t> receive_buff;
    receive_buff.resize(12);
    ser.Read(receive_buff,12);
    servo_angle[servo_id]=angle_transform(receive_buff);
    ROS_INFO("Current angle is %.2f°",servo_angle[servo_id]);
    return servo_angle[servo_id];
}
/**
 * @brief 用于实现机器人变结构转换，包括翼板的转换和推进器朝向的转换
 * 
 * @param ser 
 * @return true 
 * @return false 
 */
void mode_change(LibSerial::SerialPort &ser){
    uint8_t servo_now_id=0x01;//每一步要控制的舵机，这是个临时变量，初始从1号舵机开始
    uint8_t check_sum=0;
    std::vector<uint8_t> angle_tmep=angle_transform_inverse(WING_TRANS_ANGLE);//用于存储角度转换的小端序数，第一次调用翼板的角度信息
    std::vector<uint8_t> req_buff={0x12,0x4C,0x0D,0x0B,servo_now_id};

    //翼板展开

    req_buff.insert(req_buff.end(),angle_tmep.begin(),angle_tmep.end());
    for(auto i:req_buff){
        check_sum+=i;
    }
    check_sum%=256;//校验和
    req_buff.push_back(check_sum);
    check_sum=0;//清空校验和
    ser.Write(req_buff);

    //推进器变换
    req_buff.resize(5);//删除旧的角度信息
    angle_tmep=angle_transform_inverse(MOTOR_TRANS_ANGLE);
    req_buff.insert(req_buff.end(),angle_tmep.begin(),angle_tmep.end());
    for(int i=1;i<=3;i++){
        check_sum=0;//清空校验和
        servo_now_id=0x02+i;
        req_buff[4]=servo_now_id;//修改接受消息的舵机编号

        for(auto i:req_buff){//校验和
            check_sum+=i;
        }
        check_sum%=256;
        req_buff.push_back(check_sum);

        ser.Write(req_buff);
    }
}
/**
 * @brief 用于对舵机进行手动控制，通过键盘响应，同时带有角度监测
 * 
 */
void manual_control(uint8_t servo_id){
    float current_angle=get_angle(servo_id,ser);
    ROS_INFO("Current mode:Manual control mode\nCurrent servo: %d \nCurrent angle %.1f °",servo_id,current_angle);
    while(ros::ok()){
        if(kbhit()){
            char c=getchar();
            if(c=='q') break;
            else if(c=='a') current_angle+=10;
            else if(c=='d') current_angle-=10;
            else continue;
        }
    }
}
/**
 * @brief 用于分流舵机控制请求。命令：angle:获取某一个舵机的角度，消息中的servoID要写明；mode_change:变结构命令
 * 
 * @param req 
 * @param res 
 * @return true 
 * @return false 
 */
bool command_handler(control_pkg::servo_control::Request &req,
                    control_pkg::servo_control::Response &res)
{
    if(req.req=="angle"){
        res.angle=get_angle(req.servoID,ser);
    }
    else if(req.req=="change_mode"){
        mode_change(ser);
    }
    else if(req.req=="manual_control"){

    }
}
int main(int argc,char** argv){
    ros::init(argc,argv,"servo_control_node");
    ros::NodeHandle n;

    try
    {
        ser.Open("/dev/ttyACM0");
        ser.SetBaudRate(LibSerial::BaudRate::BAUD_115200);
        ser.SetCharacterSize(LibSerial::CharacterSize::CHAR_SIZE_8);
    }
    catch(const LibSerial::OpenFailed& e)
    {
        ROS_ERROR("Couldn't open serial%s",e.what());
        return 1;
    }
    ROS_INFO("Servo_control_node is running...");

    ros::ServiceServer service=n.advertiseService("servo_control",command_handler);
    ROS_INFO("Service [servo_control] is online\n");
    ros::spin();
    return 0;
}