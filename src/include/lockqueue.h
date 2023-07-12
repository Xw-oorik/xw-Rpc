#pragma once
#include <queue>
#include <mutex>
#include <condition_variable>

// 异步写日志的缓冲队列
template <typename T>
class Logger_LockQueue
{
public:
    void Push(const T &data)
    {
        std::unique_lock<std::mutex>lock(mtx);
        que.push(data);
        cond.notify_one();
    }

    T Pop()
    {
        std::unique_lock<std::mutex>lock(mtx);
        while(que.empty())
        {
            cond.wait(lock);
        }
        T data=que.front();
        que.pop();
        return data;
    }

private:
    std::queue<T> que;
    std::mutex mtx;
    std::condition_variable cond;
};