#pragma once

#include<semaphore.h>
#include<zookeeper/zookeeper.h>
#include<string>

class ZookeeperClient
{
public:
    ZookeeperClient();
    ~ZookeeperClient();
    //连接zk服务器
    void start();
    //在zk服务器上根据指定path路径创建znode结点，填充数据 
    //state默认为0是永久性结点，1为临时结点
    void create(const char *path, const char *data, int datalen, int state = 0);
    //获取znode结点上的数据
    std::string get_data(const char *path);
private:
    //zk客户端句柄
    zhandle_t* zk_handle;
};