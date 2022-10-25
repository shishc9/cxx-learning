#include <iostream>
#include <functional>

void print1() {
    std::cout << "hello, print1" << std::endl;
    return ;
}

void print2() {
    std::cout << "hello, print2" << std::endl;
    return ;
}

struct A {
    void operator()() {
        std::cout << "A object" << std::endl;
    }
    void test() {
        std::cout << "test" << std::endl;
    }
};

int main() {
    std::function<void()> func;
    A a_object;

    func = &print1;
    func();

    func = &print2;
    func();

    func = a_object;
    func();

    return 0;
}