#include<iostream>
#include<string>
#include"user.pb.h"
#include"rpcprovider.h"
#include"rpcapplication.h"
#include"logger.h"
using namespace User_Proto;

#define PROTOBUF_NAMESPACE_ID google::protobuf


//UserService原本是一个本地服务，提供了两个进程间的本地方法login和getFriendLists
class UserService:public UserServiceRpc  //使用在rpc服务的发布者（服务提供者）
{
public:
    bool login(std::string name,std::string pwd)  //本地的业务
    {
        std::cout<<"doing local service: Login"<<std::endl;
        std::cout<<"name: "<<name<<" pwd: "<<pwd<<std::endl;
        return true;
    }

    //下面就是rpc 远程调用的api
    //重写基类UserServiceRpc的虚函数， 下面的方法都是rpc框架直接调用
    //1. caller-> Login(LoginRequest) ->muduo -> callee
    //2. callee 拿到Login(LoginRequest) -> 交到下面重写的方法上
    virtual void Login(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                       const ::User_Proto::LoginRequest* request,
                       ::User_Proto::LoginResponse* response,
                       ::google::protobuf::Closure* done)
    {
        //rpc框架接收到的请求LoginRequest，给这块应用上报，这块应用做业务处理
        std::string name=request->name();
        std::string pwd=request->pwd();

        //做本地业务
        bool ret=login(name,pwd);
        //写到响应LoginResponse，通过rpc框架 返回对端
        ErrorCode*code=response->mutable_result();
        code->set_errcode(0);
        code->set_errmsg("xx!error");
        response->set_success(ret);
        //执行回调操作Closure -》重写Run
        done->Run();
    }
};

int main(int argc,char **argv)
{
    RPC_LOG_INFO("HELLO");
    RPC_LOG_ERROR("%s,%s,%d", __FILE__, __FUNCTION__, __LINE__);
    //调用框架的初始化操作
    RpcApplication::Init(argc,argv);
    //provider是一个rpc网络服务对象，把业务对象发布到rpc结点上
    RpcProvider provider;
    provider.NotifyService(new UserService());

    //启动rpc服务结点，run之后，阻塞等着远程的rpc调用的请求发来
    //接收到了请求，不就通过一些列序列化操作，然后进到他身上的业务类UserService
    //UserService在去执行本地逻辑
    provider.run();

    return  0;
}