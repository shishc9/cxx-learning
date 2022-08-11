#pragma once
#ifndef __THREAD_POOL_H__
#define __THREAD_POOL_H__

#include <functional>
#include <vector>
#include <thread>
#include <queue>
#include <future>
#include <condition_variable>
#include <mutex>

class ThreadPool {
public:
    ThreadPool(size_t);
    template<class F, class... Args>
    auto enqueue(F&& f, Args&&... args)
        -> std::future<typename std::result_of<F(Args...)>::type>;
    ~ThreadPool();
private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;

    std::mutex queue_mutex;
    std::condition_variable condition;
    bool stop;
};

#endif