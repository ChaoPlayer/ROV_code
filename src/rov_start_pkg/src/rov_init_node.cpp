#include "rov_start_pkg/headfile.h"
#include "rov_start_pkg/init_msg.h"
#include "rov_init_node.h"


void msg_set(rov_start_pkg::init_msg init_msg,init_status status){
    init_msg.command=true;
    init_msg.success=false;

}
void init_callback(const rov_start_pkg::init_msg::ConstPtr& msg){
    if(msg->success)
    {
        status_map[msg->module_name]=true;
        return;
    }
}
int main(int argc,char **argv){
    ros::init(argc,argv,"rov_init_node");
    ros::NodeHandle n_init;

    ros::Publisher init_pub=n_init.advertise<rov_start_pkg::init_msg>("init_check",10);
    ros::Rate rate(1);

    int module_id;

    init_status status;
    while(ros::ok()){
        rov_start_pkg::init_msg init_msg;//定义自检节点消息变量
        init_msg.module_name="center";//防止各个消息搞混，这是请求消息
        init_msg.command=true;
        init_msg.check_status=false;
        if(!init_msg.check_status)
        {
            init_pub.publish(init_msg);//循环发送自检消息
        }
        ros::Subscriber init_sub=n_init.subscribe("init_check_re",10,init_callback);

        ROS_INFO("Init message has been published");

    }
}