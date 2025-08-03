#include<ros/ros.h>
#include<opencv2/opencv.hpp>
#include<headfile_pkg/headfile.h>
#include<vision_pkg/img_manager.h>

cv::Mat R1,R2,P1,P2,Q;//
cv::Size image_size(1024,576);//图像大小
img_manager::ImgManager img_manager;
cv::stereoRectify(
    img_manager.left_cam_param,
    img_manager.left_dist_param,
    img_manager.right_cam_param,
    img_manager.right_dist_param,
    image_size,
    img_manager.R,
    img_manager.T,
    R1,R2,P1,P2,Q,
    cv::CALIB_ZERO_DISPARITY,
    0,
    image_size
);//矫正变换计算

void distance_cal(){


}


int main(int argc,char** argv){
    ros::init(argc,argv,"enable_cal_node");
    ros::NodeHandle nh;

}