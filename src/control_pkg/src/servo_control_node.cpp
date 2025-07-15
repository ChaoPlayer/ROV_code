#include"rov_start_pkg/headfile.h"
#include"rov_start_pkg/init_msg.h"
#include<ros/ros.h>
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
float data_transform(const std::vector<uint32_t>& buffer){
    int t=0;//手动小端解析幂次数
    int angle=0;
    for(int i=5;i<9;i++){
        angle+=buffer[i]*pow_int(16,t);
    }
    return angle/10;//根据通信协议，实际角度要/10
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
    std::vector<uint32_t> buff;

}