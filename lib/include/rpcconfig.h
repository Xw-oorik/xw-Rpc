#pragma once
#include<string>
#include<unordered_map>

class RpcConfig
{
public:
    //加载配置文件
    void LoadConfig_file(const char*);
    //获取配置项
    std::string Load(const std::string&);
private:
    //存配置项  k-v
    std::unordered_map<std::string,std::string> Config_Map;

};