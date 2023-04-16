#include <iostream>
#include "test.pb.h"
#include <string>

using namespace std;
using namespace fixbug;

int main()
{
    // LoginResponse rsp;
    // ResultCode *rc = rsp.mutable_result();
    // rc->set_errcode(1);
    // rc->set_errmsg("登录处理失败");

    GetFriendListResponse rsp;
    ResultCode *rc = rsp.mutable_result();
    rc->set_errcode(0);

    User *user1 = rsp.add_frinedlist();
    user1->set_name("李四");
    user1->set_age(20);
    user1->set_sex(User::MAN);

    cout << rsp.frinedlist_size() << endl;

    return 0;
}
int main1()
{
    // 封装了login请求对象的数据
    LoginRequest req;
    req.set_name("张三");
    req.set_pwd("123456");
    // 对象数据序列化-》char*
    string temp;
    if (req.SerializeToString(&temp))
        cout << temp << endl;

    // 反序列化
    LoginRequest reqB;
    if (reqB.LoginRequest::ParseFromString(temp))
        cout << reqB.name() << " " << reqB.pwd() << endl;
    return 0;
}