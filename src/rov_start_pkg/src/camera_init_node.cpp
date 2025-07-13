#include"rov_start_pkg/headfile.h"
#include"rov_start_pkg/init_msg.h"
#include<opencv2/opencv.hpp>
#include"rov_init_node.h"

void feedback(const rov_start_pkg::init_msg::ConstPtr &msg){
    if(msg->command){

    }
}
void camera_check(int cam_id,std::string name){
    cv::VideoCapture cap(cam_id);
    cv::Mat frame;
    if(!cap.isOpened()){
        ROS_ERROR("%s not found or camera isn't online\n",name);
        status_map["camera"]=false;
    }
    else{
        ROS_INFO("%s has opened successfully\n");
        status_map["camera"]=true;
        cap>>frame;
        if(!frame.empty()){
            ROS_INFO("Camera h")
        }
    }

    

}
int main(int argc,char** argv){
    ros::init(argc,argv,"camera_init_node");
    ros::NodeHandle n;
    ros::Publisher pub=n.advertise<rov_start_pkg::init_msg>("init_check_re",1000);
    ros::Subscriber sub=n.subscribe("init_check",1000,feedback);



}

