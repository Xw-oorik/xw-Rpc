#include"rpcapplication.h"
#include<iostream>
#include<string>
#include<unistd.h>


RpcConfig RpcApplication::rpc_config;

void ShowArgsHelp()
{
    std::cout<<"format: command -i <config_file>"<<std::endl;
}
void RpcApplication::Init(int argc,char **argv)
{
    if(argc<2){
        ShowArgsHelp();
        exit(EXIT_FAILURE);
    }
    int c=0;
    std::string config_file;
    while((c=getopt(argc,argv,"i:"))!=-1)//读取命令行参数的
    {
        switch (c)
        {
        case 'i':
            config_file=optarg;
            break;
        case '?':
            ShowArgsHelp();
            exit(EXIT_FAILURE);
        case ':':
            ShowArgsHelp();
            exit(EXIT_FAILURE);
        default:
            break;
        }
    }
    //开始加载配置文件
    //rpcserver_ip  rpcserver_port  zookeeper_ip   zookeeper_port
    rpc_config.LoadConfig_file(config_file.c_str());

  
   // std::cout<<rpc_config.Load("rpcserver_ip")<<std::endl;
    //std::cout<<rpc_config.Load("rpcserver_port")<<std::endl;
   // std::cout<<rpc_config.Load("zookeeper_ip")<<std::endl;
   // std::cout<<rpc_config.Load("zookeeper_port")<<std::endl;
}
RpcApplication& RpcApplication::getInstance()
{
    static RpcApplication instance;
    return instance;
}
RpcConfig& RpcApplication::getConfig()
{
    return rpc_config;
}