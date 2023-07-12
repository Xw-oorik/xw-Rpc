#include "logger.h"
#include <iostream>
#include <time.h>
#include <muduo/base/Logging.h>
// 单例
Logger &Logger::GetLogInstance()
{
    static Logger logger;
    return logger;
}
void Logger::log_info(std::string msg)
{
    SetLog_Level(INFO);
    log(msg);
}
void Logger::log_error(std::string msg)
{
    SetLog_Level(ERROR);
    log(msg);
}
void Logger::log_fatal(std::string msg)
{
    SetLog_Level(FATAL);
    log(msg);
    //muduo 的日志打印
    LOG_ERROR << "Force Majeure is being dealt with";
    //sleep(10);
    LOG_ERROR << "Question has been record in log file, please restore system,bye";
    exit(0);
}
void Logger::log(std::string msg)
{
    std::string begin_info;
    switch (m_log_level)
    {
    case INFO:
        begin_info = "[INFO]: ";
        break;
    case ERROR:
        begin_info = "[ERROR]: ";
        break;
    case FATAL:
        begin_info = "[FATAL]: ";
        break;
    default:
        break;
    }
    begin_info += msg;
    log_queue.Push(begin_info);
}
Logger::Logger()
{

    // 启动专门的写日志线程
    std::thread writethread([&]()
                            {
while (1)
{

    time_t curtime = time(nullptr);
    tm *timeInfo = localtime(&curtime);

    char file_name[128] = {0};
    // 可以用sprintf格式化
    // sprintf(file_name,"%d-%d-%d-log.txt",timeInfo->tm_year+1900,timeInfo->tm_mon+1,timeInfo->tm_mday);
    // 这里我用time.h库自带的格式化函数
    strftime(file_name, sizeof(file_name), "%Y-%m-%d-log.txt", timeInfo);

    FILE *fp = fopen(file_name, "a+");
    if (fp == nullptr)
    {
        std::cout << "logger file : " << file_name << " error" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::string msg = log_queue.Pop();
    char time_str[64] = {0};
    //  sprintf(time_str,"%d:%d:%d -> ",timeInfo->tm_hour,timeInfo->tm_min,           timeInfo->tm_sec);
    strftime(time_str, sizeof(time_str), "%H:%M:%S -> ", timeInfo);
    msg.insert(0, time_str);
    msg += "\n";
    fwrite(msg.c_str(), sizeof(char), strlen(msg.c_str()), fp);
    //fputs(msg.c_str(),fp);
    fclose(fp);
} 
});

    // 设置分离线程，让他在后台自己写去
    writethread.detach();
}
// 设置日志级别
void Logger::SetLog_Level(LoggerLevel level)
{
    m_log_level = level;
}
// 写日志,写到queue缓冲区
void Logger::Write_Log(std::string msg)
{
    log_queue.Push(msg);
}
