#include"servo_control_node.h"
#include"headfile_pkg/headfile.h"
#include<vector>

#define SERVO_ID 0x01



int pow_int(int a,int b){
    if(b==0){
        return 1;
    }
    else if(b==1){
        return a;
    }
    for(int i=2;i<=b;i++){
        a*=a;
    }
    return a;
}
float angle_transform(const std::vector<uint8_t>& buffer){
    int t=0;//手动小端解析幂次数
    int angle=0;
    for(int i=5;i<9;i++){
        angle+=buffer[i]*pow_int(16,t);
    }
    return angle/10;//根据通信协议，实际角度要/10
}
void get_angle(int servo_id,LibSerial::SerialPort ser){
    std::vector<uint8_t> request_buff={0x12,0x4C,0x10,0x01,SERVO_ID};
    uint32_t check_sum=0;
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
}
void manual_control(){

}
int main(int argc,char** argv){
    ros::init(argc,argv,"servo_control_node");
    ros::NodeHandle n;
    LibSerial::SerialPort ser;
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



}