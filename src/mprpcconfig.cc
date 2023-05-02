#include "mprpcconfig.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
void MprpcConfig::LoadConfigFile(const char *config_file)
{
    FILE *pf = fopen(config_file, "r");
    if (nullptr == pf)
    {
        cout << config_file << "is not exist!" << endl;
        exit(EXIT_FAILURE);
    }
    // 循环读取
    // 1.注释 2.正确的配置项=xxx 3.去掉开头多余的空格
    while (!feof(pf))
    {
        char buf[512] = {0};
        fgets(buf, 512, pf);

        // 去掉字符串前面的空格
        std::string src_buf(buf);
        if (src_buf.empty())
        {
            continue;
        }
        EraseSpace(src_buf);

        // 判断空行或注释#注释
        if (src_buf.empty() || src_buf[0] == '#')
        {
            continue;
        }
        // 解析配置项
        int index = src_buf.find('=');
        if (index == -1)
        {
            // 配置不合法
            continue;
        }
        std::string key;
        std::string value;
        key = src_buf.substr(0, index);
        EraseSpace(key);
        int endindex = src_buf.find('\n');
        value = src_buf.substr(index + 1, endindex - index - 1);
        EraseSpace(value);
        _configmap[key] = value;
    }
    return;
}
// 查询配置项信息
std::string MprpcConfig::Load(const std::string &key)
{
    if (_configmap.find(key) == _configmap.end())
    {
        return "";
    }
    return _configmap[key];
}
// 去掉前后空格
void MprpcConfig::EraseSpace(std::string &str)
{
    // 去掉字符串前面的空格
    // cout << "str " << str << endl;
    int index = str.find_first_not_of(' ');
    if (index != -1)
    {
        // 说明前面有空格
        str = str.substr(index);
    }
    // 去掉字符串后面多余的空格
    index = str.find_last_not_of(' ');
    if (index != -1)
    {
        // 字符串后面有空格
        str = str.substr(0, index + 1);
    }
}