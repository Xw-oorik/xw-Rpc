#include"rpcprovider.h"


//这是框架提供给外部使用的，可以发布rpc方法的函数接口
void RpcProvider::NotifyService(google::protobuf::Service *service)
{

    ServiceInfo service_info;
    
    //获取服务对象的描述信息
    const google::protobuf::ServiceDescriptor* pserviceDesc=service->GetDescriptor();

    //获取服务名字
    const std::string service_name=pserviceDesc->name();
   // std::cout<<"service_name:"<<service_name<<std::endl;
    RPC_LOG_INFO("service_name:%s",service_name.c_str());
    //获取注册的服务对象的service方法数量
    int methodCnt=pserviceDesc->method_count();
    //std::cout<<"methodCnt:"<<methodCnt<<std::endl;
    RPC_LOG_INFO("methodCnt:%d",methodCnt);
    for(int i=0;i<methodCnt;++i)
    {
        //获取了服务对象执行下标的服务方法的描述(抽象描述)
        const google::protobuf::MethodDescriptor* pmethodDesc=pserviceDesc->method(i);
        std::string method_name=pmethodDesc->name();
        service_info.m_methodMap.insert({method_name,pmethodDesc});
      //  std::cout<<"method_name:"<<method_name<<std::endl;
      RPC_LOG_INFO("method_name:%s",method_name.c_str());
    }
    service_info.m_service=service;
    m_serviceMap.insert({service_name,service_info});

}

//启动rpc服务结点，开始提供rpc远程网络调用
void RpcProvider::run()
{
    //muduo服务端的标准写法了
    //不懂看-Chat项目-》src-》chatserver.cpp -》main.cpp

    //读配置文件rpcserver的配置信息
    std::string ip=RpcApplication::getInstance().getConfig().Load("rpcserver_ip");
    uint16_t port=atoi(RpcApplication::getInstance().getConfig().Load("rpcserver_port").c_str());

    muduo::net::InetAddress address(ip,port);
    
    //创建TcpServer对象
    muduo::net::TcpServer server(&m_eventLoop,address,"RpcProvider");
    //绑定连接回调和消息读写的回调方法  ，分离网络代码和业务代码
    server.setConnectionCallback(std::bind(&RpcProvider::OnConnection,this,std::placeholders::_1));
    server.setMessageCallback(std::bind(&RpcProvider::OnMessage,this,std::placeholders::_1,
                                std::placeholders::_2, std::placeholders::_3));
    //设置muduo库的线程数量
    server.setThreadNum(4);

    //把当前rpc节点上要发布的服务全部注册到zk上，让rpc client可以从zk上发现服务
    // session timeout   30s     zkclient 网络I/O线程  1/3 * timeout 时间发送ping心跳消息
    ZookeeperClient zkCli;
    zkCli.start();
    // service_name为永久性节点    method_name为临时性节点
    for(auto& sp:m_serviceMap)
    {
        std::string service_path="/"+sp.first;
        zkCli.create(service_path.c_str(),nullptr,0);
        for(auto &mp:sp.second.m_methodMap)
        {
             // /service_name/method_name   /UserServiceRpc/Login 存储当前这个rpc服务节点主机的ip和port
            std::string method_path = service_path + "/" + mp.first;
            char method_path_data[128] = {0};
            sprintf(method_path_data, "%s:%d", ip.c_str(), port);
            // ZOO_EPHEMERAL表示znode是一个临时性节点
            zkCli.create(method_path.c_str(), method_path_data, strlen(method_path_data), ZOO_EPHEMERAL);
        }
    }
    // rpc服务端准备启动，打印信息
    std::cout << "RpcProvider start service at ip:" << ip << " port:" << port << std::endl;
    RPC_LOG_INFO("server RpcProvider [ip: %s][port: %d]", ip.c_str(), port);
    //启动网络服务
    server.start();
    //开启事件循环
    m_eventLoop.loop();
}
//新的socket连接回调
void RpcProvider::OnConnection(const muduo::net::TcpConnectionPtr&conn)
{
    if(!conn->connected()){
        //和rpc client的连接断开了
        conn->shutdown();
    }
}


//处理已建立连接用户的消息读写的回调 ，如果远端有rpc服务调用请求，这个api就会响应
//请求的反序列化， 响应的序列化
void RpcProvider::OnMessage(const muduo::net::TcpConnectionPtr &conn,//连接
                muduo::net::Buffer *buffer,//缓冲区
                muduo::Timestamp time)//接收到数据的时间信息
{
    //发来的字符串是headersize+header+agrs
    //headersize用4字节存就行 
    //header-》服务名，方法名，参数size大小
    //01串表示的
    //网络接收远端的rpc调用请求的字符流
    std::string recv_buf=buffer->retrieveAllAsString();

    //从字符流读4个字节内容-》headersize
    uint32_t headersize=0;
    recv_buf.copy((char*)&headersize, sizeof (uint32_t), 0);
    //std::memcpy(&headersize,recv_buf.c_str(),sizeof (uint32_t));

    //根据headersize读header信息，反序列化，得到详情信息
    std::string header_str=recv_buf.substr(sizeof (uint32_t),headersize);
    rpc_Proto::RpcHeader rpc_header;
    std::string service_Name;
    std::string method_Name;
    uint32_t args_Size=0;
    if(rpc_header.ParseFromString(header_str))
    {
        //数据反序列化成功
        service_Name=rpc_header.service_name();
        method_Name=rpc_header.method_name();
        args_Size=rpc_header.args_size();
    }
    else{
        RPC_LOG_ERROR("rpc header str:%s parse error!", header_str.c_str());
        return;
    }
    //获取rpc方法的参数字符流数据
    std::string args_str=recv_buf.substr(sizeof (uint32_t)+headersize);
    std::cout << "============================================" << std::endl;
    std::cout<<"headersize: "<<headersize<<std::endl;
    std::cout<<"header_str: "<<header_str<<std::endl;
    std::cout<<"service_Name: "<<service_Name<<std::endl;
    std::cout<<"method_Name: "<<method_Name<<std::endl;
    std::cout<<"args_Size: "<<args_Size<<std::endl;
    std::cout<<"args_str: "<<args_str<<std::endl;
    std::cout << "============================================" << std::endl;


    //获取服务对象和api
    auto it=m_serviceMap.find(service_Name);
    if(it==m_serviceMap.end()){
        RPC_LOG_ERROR("%s is not exist", service_Name.c_str());
        return;
    }
    auto meit=it->second.m_methodMap.find(method_Name);
    if(meit==it->second.m_methodMap.end()){
        RPC_LOG_ERROR("%s::%s is not exist",service_Name.c_str(),method_Name.c_str());
        return;
    }

    google::protobuf::Service *service=it->second.m_service; //获取server对象 -》UserServer
    const google::protobuf::MethodDescriptor*method=meit->second;//获取其方法-》Login

    //生成rpc方法调用的请求request

    google::protobuf::Message* request=service->GetRequestPrototype(method).New();

    if(!request->ParseFromString(args_str))
    {
        RPC_LOG_ERROR("request parse error!");
        return;
    }
    //生成rpc方法调用响应response
    google::protobuf::Message* response=service->GetResponsePrototype(method).New();

    //给下面的method方法的调用，绑定一个Closure回调
   google::protobuf:: Closure*done=google::protobuf::NewCallback<RpcProvider,const muduo::net::TcpConnectionPtr&,
                                                                google::protobuf::Message*>
                                                (this,&RpcProvider::SendRpcResponse,conn,response);
    
    //在框架上根据远端的rpc请求，调用当前rpc结点的发布方法
    service->CallMethod(method,nullptr,request,response,done);


}
//Closure的回调操作，用于序列化rpc响应和网络发送
void RpcProvider::SendRpcResponse(const muduo::net::TcpConnectionPtr &conn,google::protobuf::Message*response)
{
    //把响应response 序列化，通过网络发出去
    std::string response_str;
    if(response->SerializeToString(&response_str))
    {
       RPC_LOG_INFO("SerializeToString reponse success");
       conn->send(response_str);//通过网络发过去，，用的都是muduo框架 
    }
    else{
         RPC_LOG_ERROR("serialize reponse error");
    }
    conn->shutdown();  //短链接，回完响应就断开连接就行
}
