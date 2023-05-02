#include <iostream>
#include "mprpcapplication.h"
#include "user.pb.h"
#include "mprpcchannel.h"
int main(int argc, char **argv)
{
    // 整个程序启动以后，想使用mprpc框架来享受rpc服务调用，一定要先调用框架的初始化函数
    MprpcApplication::Init(argc, argv);

    // 延时调用远程发布的rpc方法Login
    fixbug::UserServiceRpc_Stub stub(new MprpcChannel());
    // rpc方法的请求参数
    fixbug::LoginRequest request;
    request.set_name("zhang san");
    request.set_pwd("123456");
    // rpc方法的响应
    fixbug::LoginResponse response;
    // 发起rpc方法的调用,同步的rpc调用过程,MprpcChannel::callmethod
    stub.Login(nullptr, &request, &response, nullptr); // RpcChannel->RpcChannel::callMethod 集中来做所有rpc方法的参数序列化和网络发送

    // 一次rpc调用完成,读调用的结果
    if (response.result().errcode() == 0)
    {
        // 没有错误
        std::cout << "rpc login response success: " << response.sucess() << std::endl;
    }
    else
    {
        // 有错误
        std::cout << "rpc login response error: " << response.result().errcode() << std::endl;
    }
    return 0;
}