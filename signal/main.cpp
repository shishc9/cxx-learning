#include <iostream>
#include <csignal>
#include <unistd.h>


/* c++ 信号处理提供了 signal 函数，用来捕获突发事件。
    void (*signal (int sig, void (*func)(int)))(int);
    signal(registered signal, signal handler);  => 第一个参数是一个整数，代表了信号的编号；第二个参数是一个指向信号处理函数的指针。

    SIGABRT 程序的异常终止，比如调用 abort.
    SIGFPE  错误的算术运算，比如除以零或导致溢出的操作.
    SIGLL   检测非法指令.
    SIGINT  interrupt信号，终止程序.
    SIGSEGV 非法访问内存.
    SIGTERM 发送到程序的终止请求.
 */
void signalHandler(int signum) {
    std::cout << "Interrupt signal (" << signum << ") recieved.\n";
    exit(signum);
}

int main() {
    /* 可以使用 int raise(signal sig) 函数生成信号，该函数带有一个整数信号编号作为参数
        该编号包括：SIGINT、SIGABRT、SIGFPE、SIGILL、SIGSEGV、SIGTERM、SIGHUP。
     */

    int i = 0;
    signal(SIGINT, signalHandler);

    while (++i) {
        std::cout << "go to sleep..." << std::endl;
        if (i == 3) {
            raise(SIGINT);
        }
        sleep(1);
    }

    return 0;
}

/* int main() {
    signal(SIGINT, signalHandler);
    while (1) {
        std::cout << "go to sleep..." << std::endl;
        sleep(1);
    }

      go to sleep...
        go to sleep...
        go to sleep...
        ^CInterrupt signal (2) recieved. 

    return 0;
} */
