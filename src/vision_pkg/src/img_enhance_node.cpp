#include<headfile_pkg/headfile.h>
#include<opencv2/opencv.hpp>
#include<onnxruntime_cxx_api.h>

int main(){
    Ort::Env env(ORT_LOGGING_LEVEL_WARNING,"ONNX");//创建onnx运行环境，只输出警告以上的信息
    Ort::SessionOptions session_options;//定义一个session的配置选项对象
    session_options.SetInterOpNumThreads(1);//设置线程数为1
    session_options.SetGraphOptimizationLevel(GraphOptimizationLevel::ORT_ENABLE_EXTENDED);
    //启用图优化为ORT_ENABLE_EXTENDED
    Ort::Session session(env,"src/vision_pkg/model/MuLA_GAN.onnx",session_options);
    //创建推理会话对象，用于执行模型

    cv::Mat img_0;//存储双目摄像头的原始数据
    cv::Mat img_0_resize;
    cv::VideoCapture cap(0,cv::CAP_V4L2);
    cap.set(cv::CAP_PROP_FRAME_WIDTH,1280);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT,480);
    cap.set(cv::CAP_PROP_FPS,30);
    while(true)
    { 
        cap>>img_0;
        //cv::rotate(img_0,img_0,cv::ROTATE_90_COUNTERCLOCKWISE);
        cv::imshow("实时原始图像",img_0);
        if(cv::waitKey(10)==27){
            break;
        }
    }
    

}