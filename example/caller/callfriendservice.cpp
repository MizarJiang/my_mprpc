#include <iostream>
#include "mprpcapplication.h"
#include "friend.pb.h"
#include "mprpcchannel.h"
#include "mprpccontroller.h"
int main(int argc, char **argv)
{
    // 整个程序启动以后，想使用mprpc框架来享受rpc服务调用，一定要先调用框架的初始化函数
    MprpcApplication::Init(argc, argv);

    // 调用远程发布的rpc方法Login
    fixbug::FriendServiceRpc_Stub stub(new MprpcChannel());
    // rpc方法的请求参数
    fixbug::GetFriendListRequest request;
    request.set_userid(16);
    // rpc方法的响应
    fixbug::GetFriendListResponse response;
    // 发起rpc方法的调用,同步的rpc调用过程,MprpcChannel::callmethod
    MprpcController controller;
    stub.GetFriendList(&controller, &request, &response, nullptr); // RpcChannel->RpcChannel::callMethod 集中来做所有rpc方法的参数序列化和网络发送
    if(controller.Failed()){
        //出现错误
        std::cout<<controller.ErrorText()<<std::endl;
    }
    else{
        //没有错误
        // 一次rpc调用完成,读调用的结果
        if (response.result().errcode() == 0)
        {
            // 没有错误
            std::cout << "rpc getfriendlist response success! " << std::endl;
            int size = response.friends_size();
            for (int i = 0; i < size; i++)
            {
                std::cout << "index: " << i + 1 << " name: " << response.friends(i) << std::endl;
            }
        }
        else
        {
            // 有错误
            std::cout << "rpc login response error: " << response.result().errcode() << std::endl;
        }
    }
    

    return 0;
}