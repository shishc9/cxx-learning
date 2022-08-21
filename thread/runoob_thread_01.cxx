#include <iostream>
#include <pthread.h>

#define NUM_THREADS 5

void* say_hello(void* args) {
    std::cout << "say hello" << std::endl;
    return 0;
}

/* pthread_create(thread, attr, start_routine, arg)
    thread:         线程id
    attr:           线程属性，一般为null
    start_routine:  线程运行函数起始地址
    arg:            函数参数

    pthread_exit(status)
    显示退出一个线程，通常情况下，是在线程完成工作后无需继续存在时被调用退出。
    若main函数在它所创建线程之前结束，并通过pthread_exit退出，那么其他线程会继续执行.
 */

int main() {
    pthread_t tids[NUM_THREADS];
    for (int i = 0;i < NUM_THREADS; i++) {
        int ret = pthread_create(&tids[i], NULL, say_hello, NULL);
        if (ret != 0) {
            std::cout << "pthread_create error: error_code=" << ret << std::endl;
        }
    }

    pthread_exit(NULL);
    return 0;
}
