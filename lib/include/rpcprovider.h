#pragma once
#include"google/protobuf/service.h"
#include<muduo/net/TcpServer.h>
#include<muduo/net/EventLoop.h>
#include<muduo/net/InetAddress.h>
#include<muduo/net/TcpConnection.h>
#include"rpcapplication.h"
#include<functional>
#include<google/protobuf/descriptor.h>
#include"rpc.pb.h"
#include"logger.h"
#include"zookeeperClient.h"
//NotifyService方法参数
//protobuf的rpc对象都是从Service这个类继承来的
//框架要接收任何rpc方法，所以参数就给Service就行
//具体哪个要发布rpc方法，把具体参数传进去就行，这就是基类指针接收派生类对象的使用

//框架提供的专门发布rpc服务的网络对象类
class RpcProvider
{
public:
    //这是框架提供给外部使用的，可以发布rpc方法的函数接口
    //Service是所有服务对象的基类，protobuf提供的
    void NotifyService(google::protobuf::Service *service);

    //启动rpc服务结点，开始提供rpc远程网络调用
    void run();
private:

    //service服务类信息
    struct ServiceInfo
    {
        google::protobuf::Service *m_service;//保存服务对象
        std::unordered_map<std::string,const google::protobuf::MethodDescriptor*>m_methodMap;//保存服务信息
    };
    //存储注册成功的服务对象和其服务方法信息
    std::unordered_map<std::string,ServiceInfo>m_serviceMap;

    //服务提供者，需要进行高并发网络传输，下面就是套用muduo的服务端标准写法
    //组合了EventLoop
    muduo::net::EventLoop m_eventLoop;

    //新的socket连接的回调
    void OnConnection(const muduo::net::TcpConnectionPtr&);

    //处理已建立连接用户的消息读写的回调
    void OnMessage(const muduo::net::TcpConnectionPtr &,//连接
                    muduo::net::Buffer *,//缓冲区
                    muduo::Timestamp );//接收到数据的时间信息

    //Closure的回调操作，用于序列化rpc响应和网络发送
    void SendRpcResponse(const muduo::net::TcpConnectionPtr &conn,
                                google::protobuf::Message*mes);
};