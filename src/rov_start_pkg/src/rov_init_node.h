#include<iostream>
class init_status{
    bool command=false;
    bool success=false;
};

std::map<std::string, bool> status_map=
{
    {"servo",false},
    {"motor",false},
    {"rspi",false},
    {"vision",false},
    {"camera",false},//双目相机
    {"px4",false},
    {"sensor",false},
};//创建键值对，便于自检状态管理