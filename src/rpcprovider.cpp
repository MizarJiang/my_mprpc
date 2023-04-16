#include "rpcprovider.h"
#include <string>
#include <iostream>
#include <functional>
#include "mprpcapplication.h"
void RpcProvider::NotifyService(google::protobuf::Service *service)
{
}
// 启动rpc服务节点，开始提供rpc远程网络调用服务
void RpcProvider::Run()
{
    std::string ip = MprpcApplication::GetInstance().getConfig().Load("rpcserver_ip");
    if (ip.empty())
    {
        std::cout << "RpcProvider::Run() rpcserver_ip error " << std::endl;
    }
    int port = stoi(MprpcApplication::GetInstance().getConfig().Load("rpcserver_port"));
    if (port <= 0)
    {
        std::cout << "RpcProvider::Run() rpcserver_port error " << std::endl;
    }
    muduo::net::InetAddress address(ip, port);
    // 创建muduo库tcpserver对象
    muduo::net::TcpServer server(&_eventLoop, address, "RpcProvider");
    // 绑定连接回调和消息读写回调方法,分离了网络代码和业务代码
    server.setConnectionCallback(std::bind(&RpcProvider::onConnetction, this, std::placeholders::_1));
    server.setMessageCallback(std::bind(&RpcProvider::onMessage, this,
                                        std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

    // 设置muduo库的线程数量
    server.setThreadNum(4);
    // 启动网络服务
    server.start();
    _eventLoop.loop();
}

void RpcProvider::onConnetction(const muduo::net::TcpConnectionPtr &conn)
{
}

void RpcProvider::onMessage(const muduo::net::TcpConnectionPtr &,
                            muduo::net::Buffer *,
                            muduo::Timestamp)
{
}