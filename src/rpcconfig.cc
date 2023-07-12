#include"rpcconfig.h"
#include<iostream>
#include<algorithm>

//加载配置文件
void RpcConfig::LoadConfig_file(const char*config_file)
{
    FILE *fp=fopen(config_file,"r");
    if(fp==nullptr){
        std::cout<<config_file<<" is open err/or not exited "<<std::endl;
        exit(EXIT_FAILURE);
    }
    //解析配置了 
    while(!feof(fp))
    {
        char buf[512]={0};
        fgets(buf,512,fp);
        //去除每行字符串前面多余空格
        std::string src_buf(buf);        
        //是否每一行以 '#' 开头或为空字符串行
        if(src_buf[0]=='#'||src_buf.empty()){
            continue;
        }
        
        int index=src_buf.find_first_not_of(' ');
        if(index!=-1){
            //找到了 ,开头 去除空格
            src_buf=src_buf.substr(index,src_buf.size()-index+1);
        }
        //去除每行字符串后面多余空格
        index=src_buf.find_last_not_of(' ');
        if(index!=-1){  
             src_buf=src_buf.substr(0,index+1);
        }

        //解析具体配置
        index=src_buf.find('=');
        if(index==-1){
            continue; 
        }
        std::string key;
        std::string value;
        key=src_buf.substr(0,index);
        value=src_buf.substr(index+1);

        //删除配置项左右跟前的空格 前面分割出来的格式可能是  xxx空格=空格xxx
        key.erase(std::remove_if(key.begin(), key.end(), ::isspace), key.end());
        value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());

        //处理value后#注释部分
        index=value.find('#');
        if(index!=std::string::npos){
            value.erase(value.begin()+index,value.end());
        }   
        //记录到map
        Config_Map.insert({key,value});   
    } 
}
//获取配置项
std::string RpcConfig::Load(const std::string& key)
{
    auto it=Config_Map.find(key);
    if(it==Config_Map.end())
    {
        return "";
    }
    return it->second;
}