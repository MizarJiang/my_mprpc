#include "logger.h"
#include <time.h>
#include <iostream>

//获取日志的单例
Logger& Logger::GetInstance(){
    static Logger instance;
    return instance;
}
//设置日志级别
void Logger::SetLogLevel(LogLevel level){
    m_loglevel=level;
}
//写日志
void Logger::Log(std::string msg){
    m_que.push(msg);
}
Logger::Logger(){
    //启动专门的写日志线程
    std::thread writeLogTask([&](){
        for(;;){
            //获取当天的日期，然后取日志信息，写入响应的日志文件当中，追加模式
            time_t now=time(nullptr);
            tm *nowtm= localtime(&now);
            
            std::string file_name;
            file_name=std::to_string(nowtm->tm_year+1900)+"_"+std::to_string(nowtm->tm_mon+1)+"_"
                                +std::to_string(nowtm->tm_mday)+".txt";

            //创建文件或打开文件
            FILE *pf=fopen(file_name.c_str(),"a+");
            if(pf==nullptr){
                std::cout<<"logger file: "<<file_name<<" open error!"<<std::endl;
                exit(EXIT_FAILURE);
            }
            std::string msg=m_que.pop();

            std::string curTime;
            curTime=std::to_string(nowtm->tm_hour)+":"+std::to_string(nowtm->tm_min)+":"
                                +std::to_string(nowtm->tm_sec);
            
            std::string level=m_loglevel==INFO?" INFO":" ERROR";
            msg =msg+" "+curTime+" "+level;
            msg.append("\n");
            fputs(msg.c_str(),pf);
            fclose(pf);
        }
    });
    //设置分离线程
    writeLogTask.detach();
}