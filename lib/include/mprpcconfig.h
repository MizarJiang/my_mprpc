#pragma once
#include <unordered_map>
#include <string>
// 框架读取配置文件类
// rpcserver_ip rpcserver_port zookeeper_ip zookeeper_port
class MprpcConfig
{
private:
    std::unordered_map<std::string, std::string> _configmap;

public:
    // 负责解析加载配置文件
    void LoadConfigFile(const char *config_file);
    // 查询配置项信息
    std::string Load(const std::string &key);
    // 去掉前后空格
    void EraseSpace(std::string &str);
};