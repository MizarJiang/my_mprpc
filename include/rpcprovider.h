#pragma once
#include <memory>
#include <muduo/net/TcpConnection.h>
#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/InetAddress.h>
#include "google/protobuf/service.h"

// 框架提供的专门服务发布rpc服务的网络对象类
class RpcProvider
{
private:
    // 组合eventloop
    muduo::net::EventLoop _eventLoop;
    // 新的socket连接回调
    void onConnetction(const muduo::net::TcpConnectionPtr &conn);
    // 新的message连接回调
    void onMessage(const muduo::net::TcpConnectionPtr &,
                   muduo::net::Buffer *,
                   muduo::Timestamp);

public:
    // 这里是框架提供给外部使用的，可以发布rpc方法的函数接口
    void
    NotifyService(google::protobuf::Service *service);
    // 启动rpc服务节点，开始提供rpc远程网络调用服务
    void Run();
};