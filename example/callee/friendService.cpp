#include <iostream>
#include <string>
#include "mprpcapplication.h"
#include "rpcprovider.h"
#include "../friend.pb.h"
#include <vector>
#include "logger.h"

using namespace fixbug;
/*
UserService本来是个本地服务，提供了两个进程内的本地方法Login和GetFriendLists
*/
class FriendService : public FriendServiceRpc // 使用在rpc服务发布端rpc服务提供者（）
{
public:
    std::vector<std::string> GetFriendList(uint32_t userid)
    {
        std::cout << "do GetFriendList Service, userid: " << userid << std::endl;
        std::vector<std::string> vec;
        vec.push_back("gao yang");
        vec.push_back("liu hong");
        return vec;
    }
    // 重写基类方法
    void GetFriendList(::google::protobuf::RpcController *controller,
                       const ::fixbug::GetFriendListRequest *request,
                       ::fixbug::GetFriendListResponse *response,
                       ::google::protobuf::Closure *done)
    {
        // 框架给业务上报了请求参数LoginRequest，应用获取相应数据做本地业务
        uint32_t userid = request->userid();
        std::vector<std::string> friendList = GetFriendList(userid);

        // 把响应写入调用方response
        ResultCode *code = response->mutable_result();
        code->set_errcode(0);
        code->set_errrmsg("");

        for (std::string &name : friendList)
        {
            std::string *p = response->add_friends();
            *p = name;
        }

        // 执行回调操作 执行响应对象数据的序列化和网络发送（框架完成）
        done->Run();
    }
};
int main(int argc, char **argv)
{
    // LOG_INFO("first log message!");
    // LOG_ERROR("%s:%s:%d",__FILE__,__FUNCTION__,__LINE__); 
    // 调用框架的初始化操作
    MprpcApplication::Init(argc, argv);
    // 把UserService发布到rpc节点上
    RpcProvider provider;
    provider.NotifyService(new FriendService());
    // 启动一个rpc服务发布节点，run以后，进程进入阻塞状态，等待远程的rpc调用请求
    provider.Run();
    return 0;
}