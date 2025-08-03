#include"img_manager.h"
#include<opencv2/opencv.hpp>
#include<onnxruntime_cxx_api.h>
/**
 * @brief 用于显示双目摄像头的原始画面，按esc退出
 * 
 * @param img_0 
 * @param width 
 * @param height 
 */
void camera_img_show(cv::Mat img_0,int width,int height){
    cv::VideoCapture cap(0,cv::CAP_V4L2);
    cap.set(cv::CAP_PROP_FRAME_WIDTH,width);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT,height);
    cap.set(cv::CAP_PROP_FPS,30);
    while(true)
    { 
        cap>>img_0;
        //cv::rotate(img_0,img_0,cv::ROTATE_90_COUNTERCLOCKWISE);
        cv::imshow("实时原始图像",img_0);
        if(cv::waitKey(1)==27){
            break;
        }
    }
}
/**
 * @brief 用于获取水下图像增强后的图像（实时传输）
 * 
 * @param img_0 
 * @param session 
 */
void image_enhance(cv::Mat img_0,Ort::Session& session){

    cv::Mat img_resize;
    cv::resize(img_0,img_resize,cv::Size(256,256));
    cv::cvtColor(img_resize,img_resize,cv::COLOR_BGR2RGB);//转化为RGB，因为opencv一般是BGR形式
    img_resize.convertTo(img_resize,CV_32F,1.0/255);//将整个张量归一化

    std::vector<float> input_tensor_value;
    for(int c=0;c<3;++c){
        for(int y=0;y<img_resize.rows;++y){
            for(int x=0;x<img_resize.cols;++x){
                input_tensor_value.push_back(img_resize.at<cv::Vec3f>(y,x)[c]);//将HWC格式转换为CHW格式
            }
        }
    }
    Ort::MemoryInfo memory_info=Ort::MemoryInfo::CreateCpu(OrtDeviceAllocator,OrtMemTypeCPU);
    std::array<int64_t,4> input_shape{1,3,256,256};
    Ort::Value input_tensor=Ort::Value::CreateTensor<float>(
        memory_info,
        input_tensor_value.data(),
        input_tensor_value.size(),
        input_shape.data(),
        input_shape.size()
    );//构建onnx张量

    const char* input_name[]={"input"};
    const char* output_name[]={"output"};

    auto output_tensors =session.Run(
        Ort::RunOptions{nullptr},
        input_name,
        &input_tensor,
        1,
        output_name,
        1
    );

    float* output_data=output_tensors[0].GetTensorMutableData<float>();
    cv::Mat output_img(256,256,CV_32FC3);

    int idx=0;
    for(int c=0;c<3;++c){
        for(int y=0;y<256;++y){
            for(int x=0;x<256;++x){
                output_img.at<cv::Vec3f>(y,x)[c]=output_data[idx++];
            }
        }
    }

    cv::cvtColor(output_img,output_img,cv::COLOR_RGB2BGR);
    output_img.convertTo(output_img,CV_8UC3,255.0);
    cv::resize(output_img,output_img,cv::Size(2048,576));
    cv::imshow("增强后图像",output_img);
}
int main(){
    cv::Mat img_0;
    cv::Mat img_enhance;


    Ort::Env env(ORT_LOGGING_LEVEL_WARNING,"ONNX");//创建onnx运行环境，只输出警告以上的信息
    Ort::SessionOptions session_options;//定义一个session的配置选项对象
    session_options.SetInterOpNumThreads(1);//设置线程数为1
    session_options.SetGraphOptimizationLevel(GraphOptimizationLevel::ORT_ENABLE_EXTENDED);
    //启用图优化为ORT_ENABLE_EXTENDED
    Ort::Session session(env,"src/vision_pkg/model/MuLA_GAN.onnx",session_options);
    //创建推理会话对象，用于执行模型
    

    //img_0=cv::imread("src/vision_pkg/test_img/1.png");
    //camera_img_show(img_0,1280,480);
    cv::VideoCapture cap1(0);
    while(true){
        cap1>>img_0;
        image_enhance(img_0,session);
        if(cv::waitKey(1)==27) break;
    }
    
}