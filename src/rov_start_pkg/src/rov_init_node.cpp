#include "rov_start_pkg/headfile.h"
#include "rov_start_pkg/init_msg.h"
#include "rov_init_node.h"

void msg_set(rov_start_pkg::init_msg init_msg,init_status status){
    init_msg.command=true;
    init_msg.success=false;

}
int main(int argc,char **argv){
    ros::init(argc,argv,"rov_init_node");
    ros::NodeHandle n_init;

    ros::Publisher init_pub=n_init.advertise<rov_start_pkg::init_msg>("init_check",10);
    ros::Rate rate(1);
    int success_count=0;
    int module_id;

    init_status status;
    while(ros::ok()){
        rov_start_pkg::init_msg init_msg;
        

        init_pub.publish(init_msg);
        ROS_INFO("Init message has been published");

    }
}