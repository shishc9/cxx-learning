#include <iostream>

class A {
public:
    static int get(void) {
        return 100;
    }
};

class B {
public:
    static const char* get(void) {
        return "class B";
    }
};

template <typename T>
void func(void) {
    auto val = T::get();
    std::cout << val << std::endl;
}

int main() {
    /* auto 关键字仅仅是一个占位符，c++是强类型语言，变量必须是有明确类型的。使用 auto，该变量类型是由编译器推导出来的。 */
    
    /* => 符号意思为：推导出 */
    int x = 0;
    auto *p1 = &x; // auto => int
    auto p2 = &x; // auto => int*
    auto &r1 = x; // auto => int
    auto r2 = r1; // auto => int. 当 = 右边的表达式是一个引用类型时，auto会把引用抛弃，直接推导出原始类型

    /* auto 结合 const */
    const auto n = x; // auto => int
    auto f = n; // auto => int. 当 = 右边的表达式带有 const 属性时，auto不会使用const属性，而是直接推导出 non-const 类型
    const auto &r3 = x; // auto => int
    auto &r4 = r3; // auto => const int. r3(const int&), 当 = 右边是const与引用结合时，auto会保留const

    /* auto 关键字的限制 */
    /*
       使用 auto 时，变量必须进行初始化。
       auto 不能在函数参数中使用。
       auto 不能作用于类的非静态成员变量。
       auto 关键字不能定义数组。
       auto 不能用作模板参数。 eg. template<class T> class A{};  ====== A<auto> c1 ❎ 
    */


   /* auto 用于迭代器与泛型编程 */
    func<A> ();
    func<B> ();

    return 0;
}
