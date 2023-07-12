#pragma once
#include"rpcconfig.h"
#include"rpcchannel.h"

//rpc框架的基础类，一个就行，用单例
//负责框架的初始化操作
class RpcApplication
{
private:
    RpcApplication(){}
    RpcApplication(const RpcApplication&)=delete;
    RpcApplication (RpcApplication&&)=delete;
    RpcApplication &operator=(const RpcApplication&)=delete;
    static RpcConfig rpc_config;
public:
    static void Init(int argc,char **argv);
    static RpcApplication& getInstance();
    static RpcConfig& getConfig();
};