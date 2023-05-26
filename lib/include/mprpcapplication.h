#pragma once
#include "mprpcconfig.h"
#include "zookeeperutil.h"
// mprpc框架的基础类
// 使用单例模式
class MprpcApplication
{
private:
    MprpcApplication() {}
    MprpcApplication(const MprpcApplication &) = delete;
    MprpcApplication(MprpcApplication &&) = delete;

private:
    static MprpcConfig _config;

public:
    static MprpcApplication &GetInstance();
    static void Init(int argc, char **argv);
    static MprpcConfig &getConfig();
};