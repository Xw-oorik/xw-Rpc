#pragma once

#include "lockqueue.h"
#include <string>
#include<thread>
#include <cstring>

enum LoggerLevel
{
    INFO,  // 普通消息 0
    ERROR,// 错误消息 1
    FATAL //毁灭信息 2
};

// rpc框架提供的日志系统
class Logger
{
public:
    void log_info(std::string msg);
    void log_error(std::string msg);
    void log_fatal(std::string msg);
    //写日志
    void log(std::string msg);
public:
    // 设置日志级别
    void SetLog_Level(LoggerLevel level);
    // 写日志,写到queue缓冲区
    void Write_Log(std::string);
    //单例
    static Logger& GetLogInstance();

private:
    int m_log_level; // 记录日志级别

    Logger_LockQueue<std::string> log_queue; // 日志缓冲队列
    // 单例
    Logger();//构造函数里面实现，另起分离线程，去queue拿日志信息写到文件中
    Logger(const Logger &) = delete;
    Logger(Logger &&) = delete;
    Logger &operator=(const Logger &) = delete;
};

//给用户提供一个宏 去记录日志就行，不用自己去初始化Logger对象，调用log方法
//这是日志系统设计，给外提供的一个思路
#define RPC_LOG_INFO(logmsgformat, ...)\
    do\
    {\
        Logger &logger=Logger::GetLogInstance();\
        char c[1024]={0};\
        snprintf(c,1024,logmsgformat,##__VA_ARGS__);\
        logger.log_info(c); \
    }while(0);


#define RPC_LOG_ERROR(logmsgformat, ...) \
    do\
    {\
        Logger &logger=Logger::GetLogInstance();\
        char c[1024]={0};\
        snprintf(c,1024,logmsgformat,##__VA_ARGS__);\
        logger.log_error(c); \
    }while(0);

#define RPC_LOG_FATAL(logmsgformat, ...) \
    do\
    {\
        Logger &logger=Logger::GetLogInstance();\
        char c[1024]={0};\
        snprintf(c,1024,logmsgformat,##__VA_ARGS__);\
        logger.log_fatal(c); \
    }while(0);