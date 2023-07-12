#include <zookeeperClient.h>
#include <iostream>
#include <rpcapplication.h>
#include <logger.h>

// 回调
void global_watcher(zhandle_t *handler, int type, int state, const char *path, void *wathcer_context)
{
    if (type == ZOO_SESSION_EVENT) // 回调的消息类型
    {
        // 连接成功就会发送一个成功信号
        if (state == ZOO_CONNECTED_STATE) // zkclient 和 zkserver 连接成功
        {
            // 获取信号量
            sem_t *sem = (sem_t *)zoo_get_context(handler);
            sem_post(sem);
        }
    }
}
ZookeeperClient::ZookeeperClient():zk_handle(nullptr)
{
}
ZookeeperClient::~ZookeeperClient()
{
    if (zk_handle != nullptr)
    {
        zookeeper_close(zk_handle);
        RPC_LOG_INFO("close zk success");
    }
}
// 连接zk服务器
void ZookeeperClient::start()
{
    std::string ip = RpcApplication::getInstance().getConfig().Load("zookeeper_ip");
    std::string post = RpcApplication::getInstance().getConfig().Load("zookeeper_port");
    std::string msg = ip + ":" + post;
    std::cout << msg << std::endl;
    // 异步的
    /*
	zookeeper_mt：多线程版本
	zookeeper的API客户端程序提供了三个线程
	API调用线程 
	网络I/O线程  pthread_create  poll
	watcher回调线程 pthread_create
	*/
    zk_handle = zookeeper_init(msg.c_str(), global_watcher, 30000, nullptr, nullptr, 0);
    if (zk_handle == nullptr)
    {
       RPC_LOG_FATAL("zookeeper init error");
    }
    sem_t sem;
    sem_init(&sem, 0, 0);
    zoo_set_context(zk_handle, &sem); // 设置信号量

    sem_wait(&sem);
    RPC_LOG_INFO("zookeeper init success");
}
// 在zk服务器上根据指定path路径创建znode结点，填充数据
void ZookeeperClient::create(const char *path, const char *data, int datalen, int state )
{
    char path_buf[128] = {0};
    int buf_len = sizeof(path_buf);
    int flag ;
    // 检查path是否存在
    flag = zoo_exists(zk_handle, path, 0, nullptr);
    if (ZNONODE == flag) // 不存在
    {
        flag = zoo_create(zk_handle, path, data, datalen, 
        &ZOO_OPEN_ACL_UNSAFE, state,
         path_buf, 
         buf_len);
        if (flag == ZOK) // 成功
        {
            RPC_LOG_INFO("znode create  success...path: %s", path);
        }
        else
        {
            RPC_LOG_FATAL("flag: %d, znode create error... path: %s", flag, path);
            
        }
    }
}
// 获取znode结点上的数据
std::string ZookeeperClient::get_data(const char *path)
{
    // buffer存储返回的结果
    char buff[64] = {0};
    int lens = sizeof(buff);
    int flag = zoo_get(zk_handle, path, 0, buff, &lens, nullptr);

    if (flag != ZOK)
    {
        RPC_LOG_ERROR("can't get znode... path: %s", path);
        return "";
    }
    else
    {
        RPC_LOG_INFO(" get znode... path: %s", path);
        return buff;
    }
}