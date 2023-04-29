#include "rpcprovider.h"
#include "mprpcapplication.h"
#include "rpcheader.pb.h"

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
// 新的socket连接回调
void RpcProvider::onConnetction(const muduo::net::TcpConnectionPtr &conn)
{
    if (!conn->connected())
    {
        // 断开连接
        conn->shutdown();
    }
}
/*
在框架内部，RpcProvider和RpcConsumer协商好之间通信用的protobuf数据类型
service_name method_name args
定义proto的message类型，进行数据头的序列化和反序列化
header_size(4字节)+header_str+args_str
为了避免粘包问题，储存一个args_size

使用std::string insert和copy方法，固定存储4个字节
*/
// 如果远程有一个rpc服务的调用请求，那么onMessage方法就会响应
void RpcProvider::onMessage(const muduo::net::TcpConnectionPtr &conn,
                            muduo::net::Buffer *buff,
                            muduo::Timestamp time)
{
    // 网络上接收的远程rpc调用请求的字符流 Login args
    std::string recv_buf = buff->retrieveAllAsString();

    // 从字符流中读取前四个字节的内容
    uint32_t header_size = 0;
    recv_buf.copy((char *)&header_size, 4, 0);

    // 根据header_size读取数据头的原始字符流，反序列化数据，得到rpc请求的详细信息
    std::string rpc_header_str = recv_buf.substr(4, header_size);
    mprpc::RpcHeader rpcHeader;
    std::string service_name;
    std::string method_name;
    uint32_t args_size;
    if (rpcHeader.ParseFromString(rpc_header_str))
    {
        // 数据头反序列化成功
        service_name = rpcHeader.service_name();
        method_name = rpcHeader.method_name();
        args_size = rpcHeader.args_size();
    }
    else
    {
        // 数据头反序列化失败
        std::cout << "rpc_header_str:" << rpc_header_str << " parase error!" << std::endl;
        return;
    }
    // 获取rpc方法参数的字符流数据
    std::string args_str = rpc_header_str.substr(4 + header_size, args_size);
    // 打印调试信息
    std::cout << "======================" << std::endl;
    std::cout << "header_size: " << header_size << std::endl;
    std::cout << "rpc_header_str: " << rpc_header_str << std::endl;
    std::cout << "service_name: " << service_name << std::endl;
    std::cout << "method_name: " << method_name << std::endl;
    std::cout << "args_str: " << args_str << std::endl;
    std::cout << "======================" << std::endl;
}