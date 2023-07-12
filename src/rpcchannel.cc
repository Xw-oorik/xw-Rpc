#include "rpcchannel.h"
#include "rpc.pb.h"
#include "rpcapplication.h"

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

// header_size + service_name +method_name+args_size +args
/*
message RpcHeader
{
    bytes service_name=1;
    bytes method_name=2;
    uint32 args_size=3;
}
*/
void MyRpcChannel::CallMethod(const google::protobuf::MethodDescriptor *method,
                              google::protobuf::RpcController *controller,
                              const google::protobuf::Message *request,
                              google::protobuf::Message *response,
                              google::protobuf::Closure *done)
{

    const google::protobuf::ServiceDescriptor *ser = method->service();
    std::string service_Name = ser->name();   // 服务名
    std::string method_Name = method->name(); // 方法名

    // 获取参数，将其序列化字符串
    uint32_t args_size = 0;
    std::string args_str;
    if (request->SerializeToString(&args_str))
    {
        args_size = args_str.size();
    }
    else
    {
        RPC_LOG_ERROR(" Serialize request args_str error!");
        controller->SetFailed("Serialize request args_str error");
        return;
    }
    // 组装rpc的header请求部分
    rpc_Proto::RpcHeader rpc_header;
    rpc_header.set_service_name(service_Name);
    rpc_header.set_method_name(method_Name);
    rpc_header.set_args_size(args_size);
    // 序列化成 搞成字节流
    uint32_t header_Size = 0;
    std::string rpc_header_str;
    if (rpc_header.SerializeToString(&rpc_header_str))
    {
        header_Size = rpc_header_str.size();
        RPC_LOG_INFO(" caller SerializeToString success!");
    }
    else
    {
        RPC_LOG_ERROR(" caller SerializeToString Error!");
        controller->SetFailed("serialize rpc header error!");
        return;
    }
    // 组装rpc请求字符串
    std::string send_rpc_str;
    send_rpc_str.insert(0, std::string((char *)&header_Size,sizeof (uint32_t)));

    send_rpc_str += rpc_header_str;
    send_rpc_str += args_str;
     std::cout << "send_rpc_str: " << send_rpc_str << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "header_Size: " << header_Size << std::endl;
    std::cout << "rpc_header_str: " << rpc_header_str << std::endl;
    std::cout << "service_Name: " << service_Name << std::endl;
    std::cout << "method_Name: " << method_Name << std::endl;
    std::cout << "args_size: " << args_size << std::endl;
    std::cout << "args_str: " << args_str << std::endl;
    std::cout << "============================================" << std::endl;

    // socket 发送请求
    int clientfd = socket(AF_INET, SOCK_STREAM, 0);
    if (clientfd == -1)
    {
        RPC_LOG_ERROR("create socket error!");
        close(clientfd);
        controller->SetFailed("create socket error! errno: "+errno);  
        return;
        // 或者RPC_LOG_FATAL("create socket error! errno:%d", errno);
        //等于上面两句
    }

    // 读配置文件rpcserver的配置信息
    // std::string ip=RpcApplication::getInstance().getConfig().Load("rpcserver_ip");
    // uint16_t port=atoi(RpcApplication::getInstance().getConfig().Load("rpcserver_port").c_str());

    // 从zk注册中心读rpc提供者的信息，就不用上面上面配置文件读了，配置文件毕竟是静态的
    ZookeeperClient zkCli;
    zkCli.start();
    // 构造方法节点的路径
    std::string meth_path = "/" + service_Name + "/" + method_Name;
    // 拿ip+port数据
    std::string host_name = zkCli.get_data(meth_path.c_str());
    if (host_name == "")
    {
        RPC_LOG_ERROR("meth_path is not exist");
        controller->SetFailed(meth_path + " is not exist!");
        return;
    }
    int index = host_name.find(":");
    if (index == -1)
    {
        RPC_LOG_ERROR(" address is invalid!");
        controller->SetFailed(meth_path + " address is invalid!");
        return;
    }
    std::string ip = host_name.substr(0, index);
    uint16_t port = atoi(host_name.substr(index + 1, host_name.size() - index).c_str());

    // 拿到ip+port
    // 进行网络通信

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip.c_str());
    // 连接rpc服务结点
    if (connect(clientfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        close(clientfd);
        RPC_LOG_FATAL("connet error! errno: %d", errno);
    }
    RPC_LOG_INFO("connet success");
    // 发送rpc请求
    if (send(clientfd, send_rpc_str.c_str(), send_rpc_str.size(), 0) == -1)
    {
        RPC_LOG_ERROR("send rpc request error");
        controller->SetFailed("send error : "+errno);
        close(clientfd);
        return;
    }
     RPC_LOG_INFO("send rpc request success");
    // 接收rpc请求的响应值
    char recv_buf[1024] = {0};
    int recv_size = 0;
    if ((recv_size = recv(clientfd, recv_buf,1024, 0)) == -1)
    {
        char exesum[512]={0};
        sprintf(exesum, "recv error : %d", errno);
        close(clientfd);
        RPC_LOG_ERROR("recv  response error");
        controller->SetFailed(std::string(exesum));
        return;
    }
     RPC_LOG_INFO("recv rpc response success");
    // 反序列化rpc调用的响应数据
    if (!response->ParseFromArray(recv_buf, recv_size))
    {
        std::string recv_err_str=recv_buf;
        controller->SetFailed("parse error : "+recv_err_str);
        RPC_LOG_ERROR("parse  response error")
        close(clientfd);
        return;
    }
    RPC_LOG_INFO("parse  response success");
    close(clientfd);
}
