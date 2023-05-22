#include "mprpcapplication.h"
#include "logger.h"
#include <iostream>
#include <unistd.h>

using std::cout;
using std::endl;
// 静态成员变量初始化
MprpcConfig MprpcApplication::_config;
void ShowArgsHelp()
{
    cout << "format: conmand -i <configfile>" << endl;
}
MprpcApplication &MprpcApplication::GetInstance()
{
    static MprpcApplication temp;
    return temp;
}
void MprpcApplication::Init(int argc, char **argv)
{
    if (argc < 2)
    {
        ShowArgsHelp();
        exit(EXIT_FAILURE);
    }
    int c = 0;
    std::string config_file;
    while ((c = getopt(argc, argv, "i:")) != -1)
    {
        switch (c)
        {
        case 'i':
            config_file = optarg;
            cout << config_file << endl;
            break;
        case '?':
            ShowArgsHelp();
            exit(EXIT_FAILURE);
        case ':':
            ShowArgsHelp();
            exit(EXIT_FAILURE);
        default:
            break;
        }
    }
    // 开始加载配置文件
    // rpcserver_ip=   rpcserver_port=   zookeeper_ip=  zookeeper_port=
    _config.LoadConfigFile(config_file.c_str());

    LOG_INFO("rpcserver_ip: %s",_config.Load("rpcserver_ip").c_str());
    LOG_INFO("rpcserver_port: %s",_config.Load("rpcserver_port").c_str());
    LOG_INFO("zookeeper_ip: %s",_config.Load("zookeeper_ip").c_str());
    LOG_INFO("zookeeper_port: %s",_config.Load("zookeeper_port").c_str());
    // cout << "rpcserver_ip: " << _config.Load("rpcserver_ip") << endl;
    // cout << "rpcserver_port: " << _config.Load("rpcserver_port") << endl;
    // cout << "zookeeper_ip: " << _config.Load("zookeeper_ip") << endl;
    // cout << "zookeeper_port: " << _config.Load("zookeeper_port") << endl;
}

MprpcConfig &MprpcApplication::getConfig()
{
    return _config;
}