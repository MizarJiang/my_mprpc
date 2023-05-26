#pragma once

#include <zookeeper/zookeeper.h>
#include <semaphore.h>
#include <string>

class ZkClient{
public:
    ZkClient();
    ~ZkClient();
    //zkclient启动连接zkserver
    void start();
    //在zkserver上根据指定的path创建znode节点
    void create(const char* path,const char* data,int datalen,int state=0);
    //根据参数指定的znode节点路径，获取znode节点的值
    std::string getData(const char* path);
private:
    //zk的客户端句柄
    zhandle_t* m_handle;
};