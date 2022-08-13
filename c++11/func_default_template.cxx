#include <iostream>

/* 类模板可以有默认参数模板 */
template <typename T, typename U = int, U N = 0>
struct foo {
    //...
};

/* c++11后，函数也可以有默认的参数模板 */
template <typename T = int>
void func() {
    // ... 
}

/* func(); */

template <typename R = int, typename U>
R func2(U val) {
    return val;
}

int main() {
    // 定义了默认模板类型后，编译器可根据参数进行推断。若无法推断则进行报错。
    func2(97); // R = int, U = int
    func2<char>(97); // R = char, U = int
    func2<double, int>(97); // R = double, U = int

    /* template <typename T, typename U = double>
    void func(T val1 = 0, U val2 = 0) {
        // ...
    }

    func('c'); // T = char, U = double
    func(); // 报错，无法推出 T 的类型，即使参数中的默认值为0 */

    return 0;
}