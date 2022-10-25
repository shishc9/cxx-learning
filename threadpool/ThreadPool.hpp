#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <vector>
#include <thread>
#include <future>
#include <stddef.h>
#include <functional>


class ThreadPool {
public:

  ThreadPool(size_t);
  ~ThreadPool();
  template<class F, class... Args>
  auto enqueue(F&&f, Args&&... args) -> std::future<typename std::result_of<F(Args...)>::type>;

private:
};

#endif