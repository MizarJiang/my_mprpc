#include <iostream>
#include <string>
#include "mprpcapplication.h"
#include "rpcprovider.h"
#include "../user.pb.h"

using std::cout;
using std::endl;
using std::string;

using namespace fixbug;
/*
UserService本来是个本地服务，提供了两个进程内的本地方法Login和GetFriendLists
*/
class UserService : public UserServiceRpc // 使用在rpc服务发布端rpc服务提供者（）
{
public:
    bool Login(string name, string pwd)
    {
        cout << "doing local service :Login " << endl;
        cout << "name: " << name << " pwd: " << pwd << endl;
        return true;
    }
    // 重写基类UserServiceRpc的虚函数，下面的这些方法都是直接调用rpc的框架
    void Login(::google::protobuf::RpcController *controller,
               const ::fixbug::LoginRequest *request,
               ::fixbug::LoginResponse *response,
               ::google::protobuf::Closure *done)
    {
        // 框架给业务上报了请求参数LoginRequest，应用获取相应数据做本地业务
        string name = request->name();
        string pwd = request->pwd();

        // 执行本地业务
        bool login_res = Login(name, pwd);

        // 把响应写入调用方response
        ResultCode *code = response->mutable_result();
        code->set_errcode(0);
        code->set_errrmsg("");
        response->set_sucess(login_res);

        // 执行回调操作 执行响应对象数据的序列化和网络发送（框架完成）
        done->Run();
    }
};
int main(int argc, char *argv[])
{
    // 调用框架的初始化操作
    MprpcApplication::Init(argc, argv);
    // 把UserService发布到rpc节点上
    RpcProvider provider;
    provider.NotifyService(new UserService());
    // 启动一个rpc服务发布节点，run以后，进程进入阻塞状态，等待远程的rpc调用请求
    provider.Run();
    return 0;
}