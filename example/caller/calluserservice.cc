#include<iostream>
#include"rpcapplication.h"
#include"user.pb.h"
#include"rpccontroller.h"
#include"logger.h"


int main(int argc,char **argv)
{

    //调用框架的初始化操作
    RpcApplication::Init(argc,argv);

    //演示调用远程rpc方法Login
    User_Proto::UserServiceRpc_Stub  stub(new MyRpcChannel());
    //rpc方法的参数
    User_Proto::LoginRequest request;
    request.set_name("xiongxx");
    request.set_pwd("123456");
    //rpc方法的响应
    User_Proto::LoginResponse response;

    MyRpcController controller;
    //发起rpc方法的调用，同步rpc调用过程
    stub.Login(&controller,&request,&response,nullptr);//channel ->callmethod

    //rpc调用完成，读取结果
    if(controller.Failed())
    {
        std::cout<<controller.ErrorText()<<std::endl;
    }
    else{
        if (response.result().errcode() == 0)
        {
            std::cout << "rpc Login response successful:" << response.success() << std::endl;
        }
        else
        {
            std::cout << "rpc Login response error:" << response.result().errmsg() << std::endl;
        }
    }


    return 0;
}