#include <iostream>
#include <algorithm>

int all_num = 0;

int main() {

    /* lambda 表达式的定义:
        [外部变量访问方式说明符](参数) mutable noexcept/throw() -> 返回值类型
        { // body; };

        1. [] => 标识是一个lambda表达式，方括号内部注明该函数可以使用哪些外部变量。外部变量指的是和当前lambda表达式位于同一作用域内的所有局部变量。
        2. () => 参数，如果不需要参数，可以省略()
        3. mutable => 如果使用该关键字，则小括号不能省略。默认情况下，lambda表达式不能修改以值传递方式传入的外部变量的值，而使用该关键字就可以改变。
        4. noexcept/throw() => 若使用，小括号不能省略。
        5. -> 返回值类型 => 若lambda函数体内只有一个return语句或该函数返回void，则编译器可自行推断出该返回值类型，此情况下可以省略。
        6. 函数体 => 函数体可以使用传入的外部变量外，还可以使用全局变量。
     */

    /* 
        1. [] => 外部变量说明
            []                  表示当前lambda函数中不导入任何外部变量
            [=]                 以值传递的方式导入所有外部变量
            [&]                 以引用传递的方式导入所有外部变量
            [val1, val2, ...]   以值传递方式导入val1, val2，多个变量之间没有先后顺序
            [&val1, &val2, ...] 以引用传递方式传入val1, val2，多变量之间没有先后顺序
            [val, &val2, ...]   以上两种方式的混用。
            [=, &val1, ...]     表示除了val1以引用方式传入外，其余都是值传递
            [this]              导入当前this指针
     */

    // eg1. lambda sort
    int num[4] {1, 2, 3, 4};
    std::sort(num, num+4, [](int x, int y) -> bool{ return x > y; });
    for (int n : num) {
        std::cout << n << " "; 
    }

    // eg2. display是为lambda函数设置的函数名
    auto display = [](int a, int b) -> void{
        std::cout << a << " " << b;
    };
    display(10, 20);

    // eg3. 值传递与引用传递的区别. 可以修改全局变量，但引入的外部变量如果是值引用，则不可修改，因为值引用的是左值。
    int num1 = 1, num2 = 2, num3 = 3;
    std::cout << "lambda1:\n";
    auto lambda1 = [=]{
        all_num = 10;
        // num1 = 2, num2 = 3, num3 = 4; 此处num1不是左值
        std::cout << num1 << " " << num2 << " " << num3 << std::endl;
    };
    lambda1();
    std::cout << all_num << std::endl;

    std::cout << "lambda2:\n";
    auto lambda2 = [&]{
        all_num = 100;
        num1 = 10, num2 = 20, num3 = 30;
        std::cout << num1 << " " << num2 << " " << num3 << std::endl;
    };
    lambda2();
    std::cout << all_num << std::endl;

    return 0;
}