#include<headfile_pkg/headfile.h>
#include<opencv2/opencv.hpp>

extern cv::Mat img_0;//存储双目摄像头的原始数据
extern cv::Mat img_enhance;//增强后数据

class ImgManager{
    public:
    cv::Mat left_cam_param=(cv::Mat_<double>(3,3)<<
        838.7419, 1.5712, 534.4415,
        0.0, 837.5888, 238.0015,
        0.0, 0.0, 1.0
    );//左相机内参矩阵
    cv::Mat right_cam_param=(cv::Mat_<double>(3,3)<<
        837.5270, 0.5742, 521.5434,
        0.0, 836.6268, 293.3889,
        0.0, 0.0, 1.0
    );//右相机内参矩阵

    cv::Mat left_dist_param=(cv::Mat_<double>(1,5)<<
        -0.0142, 0.0424, -0.0047, 0.0026, 0.0000
    );//左相机畸变参数
    cv::Mat right_dist_param=(cv::Mat_<double>(1,5)<<
        -0.0224, 0.1021, -0.0055, 0.0041, 0.0000
    );//右相机畸变参数

    cv::Mat R=(cv::Mat_<double>(3,3)<<
        1.000, 5.0164e-04, -0.0047,
        -4.9369e-04, 1.0000, 0.0017,
        0.0047, -0.0017, 1.0000
    );//双目相机的旋转矩阵
    cv::Mat T=(cv::Mat_<double>(3,1)<<
        -60.0928,
        0.290,
        -0.5646
    );//双目相机的平移矩阵
};