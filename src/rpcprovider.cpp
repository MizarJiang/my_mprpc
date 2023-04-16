#include "rpcprovider.h"
#include "mprpcapplication.h"

void RpcProvider::NotifyService(google::protobuf::Service *service)
{
    ServiceInfo service_info;
    const google::protobuf::ServiceDescriptor *pserviceDesc = service->GetDescriptor();
    // 获取服务的名字
    std::string service_name = pserviceDesc->name();
    // 获取服务对象service的方法数量
    int method_count = pserviceDesc->method_count();
    std::cout << "service name: " << service_name << std::endl;
    for (int i = 0; i < method_count; i++)
    {
        // 获取了服务对象指定下标的服务方法的描述（抽象描述）
        const google::protobuf::MethodDescriptor *pMethodDesc = pserviceDesc->method(i);
        std::string methodName = pMethodDesc->name();
        service_info._methodMap.insert({methodName, pMethodDesc});
        std::cout << "method name: " << methodName << std::endl;
    }
    service_info._service = service;
    _serviceMap.insert({service_name, service_info});
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

void RpcProvider::onMessage(const muduo::net::TcpConnectionPtr &conn,
                            muduo::net::Buffer *buff,
                            muduo::Timestamp time)
{
}