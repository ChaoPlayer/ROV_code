#include"rov_start_pkg/headfile.h"
#include "rov_start_pkg/init_msg.h"
#include<ros/ros.h>


#define DEVICE_NAME "servo"
LibSerial::SerialPort ser;//创建串口对象
bool servo_status[10];//每一个舵机自检情况
bool servo_sign=true;//总体情况
uint8_t checksum_cal(const std::vector<uint8_t> &data)
{
    uint16_t sum=0;
    for(auto i : data){
        sum+=i;
    }
    return sum%256;
}

bool ping_servo(uint8_t servo_id){//ping舵机。ping通了返回ture,servo_id是舵机的id
    ROS_INFO("Servo_init_node has recieved initial command\n");

    std::vector<uint8_t> cmd={0x12,0x4C,0x01,0x01,servo_id};//创建ping舵机的消息
    cmd.push_back(checksum_cal(cmd));

    ser.Write(cmd);//向串口变量中添加ping的消息
    ros::Duration(0.1).sleep();//等待舵机响应


    if(ser.GetNumberOfBytesAvailable()>=6){
        std::vector<uint8_t> response;
        response.resize(6);
        ser.Read(response,6);
        if(response[0]==0x05&&response[1]==0x1C&&response[2]==0x01){
            if(response[4]==servo_id){
                uint8_t check=checksum_cal({response.begin(),response.end()-1});
                if(check==response[5]){
                    ROS_INFO("Servo %d is online",servo_id);
                    return true;
                }
                else{
                    ROS_WARN("Checksum error");
                }
            }
        }
    }

    ROS_WARN("No response from servo %d",servo_id);
    return false;


}
void feedback(const rov_start_pkg::init_msg::ConstPtr& msg){
    ROS_INFO("%s received self_check request.",DEVICE_NAME);
}

int main(int argc,char** argv){
    ros::init(argc,argv,"servo_init_node");
    ros::NodeHandle nh;

    try{
        ser.Open("/dev/ttyACM0");
        ser.SetBaudRate(LibSerial::BaudRate::BAUD_115200);
        ser.SetCharacterSize(LibSerial::CharacterSize::CHAR_SIZE_8);
    }catch(const LibSerial::OpenFailed& e){
        ROS_ERROR("Couldn't open serial:%s",e.what());
        return 1;
    }

    ros::Publisher init_pub=nh.advertise<rov_start_pkg::init_msg>("init_check_re",10);    
    ros::Rate rate(1);

    rov_start_pkg::init_msg init_re;//创建回复消息变量init_re
    while(ros::ok()){
        std::cout<<"1"<<std::endl;
        ros::Subscriber init_sub=nh.subscribe("init_check",10,feedback);//从自检中心节点订阅请求
        for(uint8_t i=0;i<=5;i++)
        {
            servo_status[i]=ping_servo(0x01+i);
            if(servo_status[i]==false)
            servo_sign=false;
        }
        if(servo_sign){
            init_re.success=true;
            init_re.module_name=DEVICE_NAME;
            init_pub.publish(init_re);//检测到成功了再发送消息到回复话题中
            break;
        }
        else{
            init_re.module_name=DEVICE_NAME;
            init_re.success=false;
        }
        init_pub.publish(init_re);

        ros::spin();
        rate.sleep();
    }
    return 0;
}