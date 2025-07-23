#include<headfile_pkg/headfile.h>
#include<control_pkg/servo_control.h>



int main(int argc,char** argv){
    ros::init(argc,argv,"control_core_node");
    ros::NodeHandle n;
    ros::ServiceClient core=n.serviceClient<control_pkg::servo_control>("servo_control");
    control_pkg::servo_control srv;

    std::string command;
    int servo_id;

    std::cout<<"Please enter control command: ";
    std::cout<<std::endl<<"Current function includes:angle,change_mode,manual_control";
    std::cin>>command;

    std::cout<<"Please enter servo_id: ";
    std::cin>>servo_id;

    srv.request.req=command;
    srv.request.servoID=static_cast<uint8_t>(servo_id);//转换成服务要求的uint8类型

    if(core.call(srv)){
        std::cout<<"Service start successfully,you are in the "<<command<<" service"<<std::endl;
    }
    else{
        std::cerr<<"ERROR!Cant connect to the server";
    }
    return 0;
}