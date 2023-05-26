#include "zookeeperutil.h"
#include "mprpcapplication.h"
#include <iostream>
void global_watcher(zhandle_t* zh,int type,int state,const char* path,void* watcherCtx){
    if(ZOO_SESSION_EVENT==type){//回调的消息类型：和会话相关
        if(ZOO_CONNECTED_STATE==state){//zkClient和zkServer连接成功
            sem_t *sem=(sem_t*)zoo_get_context(zh);
            sem_post(sem);
        }
    }
}
ZkClient::ZkClient():m_handle(nullptr){

}
ZkClient::~ZkClient(){
    if(m_handle!=nullptr)
        //关闭句柄，释放资源
        zookeeper_close(m_handle);
}
void ZkClient::start(){
    std::string host=MprpcApplication::GetInstance().getConfig().Load("zookeeper_ip");
    std::string port=MprpcApplication::GetInstance().getConfig().Load("zookeeper_port");
    std::string connstr=host+":"+port;
    /*
    zookeeper_mt:多线程版本
    zookeeper的API客户端程序提供了三个线程
    API调用线程
    网络I/O线程
    watcher回调线程
    */
    m_handle=zookeeper_init(connstr.c_str(),global_watcher,30000,nullptr,nullptr,0);
    if(m_handle==nullptr){
        std::cout<<"zookeeper_init error"<<std::endl;
        exit(EXIT_FAILURE);
    }

    sem_t sem;
    sem_init(&sem,0,0);
    zoo_set_context(m_handle,&sem);

    sem_wait(&sem);
    std::cout<<"zookeeper_init success"<<std::endl;
}
void ZkClient::create(const char* path,const char* data,int datalen,int state/*=0*/){
    char path_buffer[128];
    int bufferlen=sizeof(path_buffer);
    int flag;
    //先判断path表示的znode节点是否存在，如果存在，就不重复创建了
    flag=zoo_exists(m_handle,path,0,nullptr);
    if(ZNONODE==flag){
        //表示path的znode节点不存在
        flag=zoo_create(m_handle,path,data,datalen,&ZOO_OPEN_ACL_UNSAFE,state,path_buffer,bufferlen);
        if(flag==ZOK){
            std::cout<<"znode create success ... path: "<<path<<std::endl;
        }
        else{
            std::cout<<"flag: "<<flag<<std::endl;
            std::cout<<"znode create error ... path: "<<path<<std::endl;
            exit(EXIT_FAILURE);
        }
    }
}
std::string ZkClient::getData(const char* path){
    char buffer[64];
    int bufferlen=sizeof(buffer);
    int flag=zoo_get(m_handle,path,0,buffer,&bufferlen,nullptr);
    if(flag!=ZOK){
        std::cout<<"get znode error ... path: "<<path<<std::endl;
        return "";
    }
    else{
        return buffer;
    }
}