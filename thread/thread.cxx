#include <iostream>
#include <thread>
using namespace std;

/**
 * 使用函数指针创建线程
 */
void foo(int z) {
    for (int i = 0;i < z;i ++) {
        cout << "Thread using function pointer as callable\n"; 
    }
}

/**
 * 使用函数对象创建线程 function objects
 */
class thread_obj {
public:
    void operator()(int x) {
        for (int i = 0; i < x;i ++) {
            cout << "Thread using function object as callable\n";
        }
    }
};

int main() {
    cout << "Threads 1 and 2 and 3 operating independently" << endl;

    thread thread1(foo, 3);
    thread thread2(thread_obj(), 3);

    /**
     * 使用 lambda 创建线程
     */
    auto f = [](int x) {
        for (int i = 0;i < x;i ++) {
            cout << "Thread using lambda expression as callable\n";
        }
    };
    thread thread3(f, 3);

    thread1.join();
    thread2.join();
    thread3.join();

    return 0;
}