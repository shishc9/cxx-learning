/* 在泛型编程中，可能需要通过参数的运算来得到返回值的类型。 */
#include <iostream>

template<typename R, typename T, typename U>
R add(T t, U u) {
    return t + u;
}

template<typename T, typename U>
decltype((*(T*)0) + (*(U*)0)) add2(T t, U u) {
    return t + u;
}

template<typename T, typename U>
auto add3(T t, U u) -> decltype(t + u) {
    return t + u;
}

int& foo(int& i);
float foo(float& f);

template<typename T>
auto func(T& val) -> decltype(foo(val)) {
    return foo(val);
}

template<typename T>
auto func2(T& val) -> int {
    return 0;
}

int main() {

    int a = 1;
    float b = 2.0;
    auto c = add<decltype(a + b)>(a, b);

    
    /* c++11中增加了返回类型后置，将 decltype 和 auto 结合起来完成返回值类型推导 */
    
    // add3. add4
    //func(a);
    std::cout << func2(a) << std::endl;
    return 0;
}