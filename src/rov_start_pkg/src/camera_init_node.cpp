#include"rov_start_pkg/headfile.h"
#include"rov_start_pkg/init_msg.h"
#include<opencv2/opencv.hpp>
#include"rov_init_node.h"

#define CAMERA_ID 0//双目摄像头，但是单USB信号，传入的图像是1280*480的
#define CAMERA_NAME "camera"
bool cam_cap=false;//用于判断是否获得图像

void feedback(const rov_start_pkg::init_msg::ConstPtr &msg){
    if(msg->command&&msg->module_name=="center"){
        ROS_INFO("camera is initiliazing...\n");
        return;
    }
}
bool camera_check(int cam_id,std::string name){
    cv::VideoCapture cap(cam_id);
    cv::Mat frame;
    if(!cap.isOpened()){
        ROS_ERROR("%s camera isn't online\n",name);
        status_map["camera"]=false;
    }
    else{
        ROS_INFO("%s camera has been opened\n");
        status_map["camera"]=true;
        cap>>frame;
        cap.release();//因为有重试循环，所以每取一帧就释放一次
        if(!frame.empty()){
            ROS_INFO("camera has successfully get the image!");
            return true;
        }
        else{
            ROS_WARN("Capturing images failed");
            return false;
        }
    }
}
int main(int argc,char** argv){
    ros::init(argc,argv,"camera_init_node");
    ros::NodeHandle n;
    ros::Publisher cam_pub=n.advertise<rov_start_pkg::init_msg>("init_check_re",1000);
    ros::Subscriber cam_sub=n.subscribe("init_check",1000,feedback);

    rov_start_pkg::init_msg cam_init;//定义摄像头初始化消息变量
    cam_init.module_name=CAMERA_NAME;
    ros::Rate loop_rate(1);
    int over_time=0;
    cam_init.success=camera_check(CAMERA_ID,CAMERA_NAME);//成功连接且有图像才会反馈成功
    while(ros::ok()&&!camera_check(CAMERA_ID,CAMERA_NAME))
    {
    if(status_map["camera"]!=cam_init.success)
    {
        ROS_WARN("camera has linked,but couldn't capture images.RELOADING...");
        over_time++;
    }
    if(over_time>100)
    {
        ROS_ERROR("camera runtime error\n");
        break;
    }
    loop_rate.sleep();
    ros::spinOnce();
    }
    
    cam_pub.publish(cam_init);
    return 0;
}

