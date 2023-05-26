#include "mprpcchannel.h"
#include "rpcheader.pb.h"
#include "mprpcapplication.h"
#include "mprpccontroller.h"

#include <string>
#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>
#include <error.h>
#include <memory>
/*
header_size+service_name method_name args_size+args
*/
void MprpcChannel::CallMethod(const google::protobuf::MethodDescriptor *method,
                              google::protobuf::RpcController *controller,
                              const google::protobuf::Message *request,
                              google::protobuf::Message *response,
                              google::protobuf::Closure *done)
{

    const google::protobuf::ServiceDescriptor *sd = method->service();
    std::string service_name = sd->name();    // service_name
    std::string method_name = method->name(); // method_name

    // 获取参数的序列化字符串长度 args_size
    uint32_t args_size = 0;
    std::string args_str;
    if (request->SerializeToString(&args_str))
    {
        args_size = args_str.size();
    }
    else
    {
        controller->SetFailed("request Serialize To String fail");
        return;
    }

    // 定义rpc的请求header
    mprpc::RpcHeader rpcHeader;
    rpcHeader.set_service_name(service_name);
    rpcHeader.set_method_name(method_name);
    rpcHeader.set_args_size(args_size);

    uint32_t header_size = 0;
    std::string rpc_header_str;
    if (rpcHeader.SerializeToString(&rpc_header_str))
    {
        header_size = rpc_header_str.size();
    }
    else
    {
        controller->SetFailed("rpcHeader Serialize To String fail");
        return;
    }

    // 组织待发送的rpc请求的字符串
    std::string send_rpc_str;
    // send_rpc_str.insert(0, 4, header_size);
    send_rpc_str.insert(0, std::string((char *)&header_size, 4));
    std::cout << "test send_rpc_str: " << send_rpc_str << std::endl;
    send_rpc_str += rpc_header_str;
    send_rpc_str += args_str;

    // 打印调试信息
    std::cout << "======================" << std::endl;
    std::cout << "header_size: " << header_size << std::endl;
    std::cout << "rpc_header_str: " << rpc_header_str << std::endl;
    std::cout << "service_name: " << service_name << std::endl;
    std::cout << "method_name: " << method_name << std::endl;
    std::cout << "args_str: " << args_str << std::endl;
    std::cout << "======================" << std::endl;

    // 使用tcp变成，完成rpc方法的远程调用
    auto deleter = [](int *fd)
    {
        if (*fd != -1)
            close(*fd);
        delete fd;
    };
    // std::unique_ptr<int, decltype(deleter)> clientfd(new int(socket(AF_INET, SOCK_STREAM, 0)), deleter);
    int clientfd = socket(AF_INET, SOCK_STREAM, 0);
    // int clientfd = socket(AF_INET, SOCK_STREAM, 0);
    if (clientfd == -1)
    {
        std::string errstr="create socket error! errno: " + std::to_string(errno);
        controller->SetFailed(errstr);
        exit(EXIT_FAILURE);
    }

    // std::string ip = MprpcApplication::GetInstance().getConfig().Load("rpcserver_ip");
    // uint16_t port = atoi(MprpcApplication::GetInstance().getConfig().Load("rpcserver_port").c_str());

    //rpc方法调用方想调用service_name的method_name服务，需要查询zk上该服务所在的host信息
    ZkClient zkCli;
    zkCli.start();
    std::string method_path="/"+service_name+"/"+method_name;
    std::string host_data=zkCli.getData(method_path.c_str());
    //host_data:127.0.0.1:8000
    if(host_data==""){
        controller->SetFailed(method_path+" is not exist!");
        return;
    }
    int index=host_data.find(":");
    if(index==-1){
        controller->SetFailed(method_path+" address is invalid!");
        return;
    }
    std::string ip=host_data.substr(0,index);
    uint16_t port=atoi(host_data.substr(index+1,host_data.size()-index).c_str());

    struct sockaddr_in server_addr;
    server_addr.sin_family = PF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip.c_str());

    // 发起连接
    if (-1 == connect(clientfd, (struct sockaddr *)&server_addr, sizeof(server_addr)))
    {
        std::string errstr="connect error! errno: " + std::to_string(errno);
        controller->SetFailed(errstr);
        close(clientfd);
        exit(EXIT_FAILURE);
    }
    // 发送rpc请求
    if (-1 == send(clientfd, send_rpc_str.c_str(), send_rpc_str.size(), 0))
    {
        std::string errstr="send error! errno: " + std::to_string(errno);
        controller->SetFailed(errstr);
        close(clientfd);
        return;
    }
    // 接收rpc请求的响应值
    char recv_buf[1024] = {0};
    int recv_size = 0;
    if (-1 == (recv_size = recv(clientfd, recv_buf, 1024, 0)))
    {
        std::string errstr="recv error! errno: " + std::to_string(errno);
        controller->SetFailed(errstr);
        close(clientfd);
        return;
    }
    // 反序列化rpc调用的响应请求
    std::string response_str(recv_buf, 0, recv_size);
    if (!response->ParseFromArray(recv_buf, recv_size))
    {
        std::string errstr="parse arroe! response_str: " + std::string(recv_buf, 0, recv_size);
        controller->SetFailed(errstr);
        close(clientfd);
        return;
    }
    close(clientfd);
}
