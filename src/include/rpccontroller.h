#pragma once
#include<google/protobuf/service.h>
#include<string>


//记录一下rpc调用的状态信息
class MyRpcController:public google::protobuf::RpcController
{
public:
    MyRpcController();
    void Reset();
    bool Failed()const;
    std::string ErrorText()const;
    void SetFailed(const std::string&reason);
    
    //未重写的api
    void StartCancel();
    bool IsCanceled()const;
    void NotifyOnCancel(google::protobuf::Closure* callback);
private:
    bool m_failed;//rpc方法执行过程中的状态
    std::string m_errText;//rpc方法执行过程中的错误信息

};
