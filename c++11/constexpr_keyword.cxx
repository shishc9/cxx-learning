#include <iostream>

/* 常量表达式不可以直接修饰自定义类型，若需要修饰，必须提供由常量表达式修饰的默认构造函数，且该构造函数体中不可以有内容 */
class myType{
public:
    constexpr myType(const char* name, int age):name(name),age(age){};
    constexpr const char* getname() {return name;}
    constexpr int getage() {return age;}
private:
    const char* name;
    int age;
};

int main() {
    /* constexpr 修饰多个常量组成的表达式 */

    constexpr int num = 1 + 2 + 3;
    int url[num]{1,2,3,4,5,6};
    std::cout << url[1] << std::endl;  // 2

    /* constexpr 修饰函数必须满足四个条件
        1. 整个函数的函数体中，除了可以包含using指令，typedef语句以及static_assert断言外，只能包含一条return语句。
        2. 该函数必须有返回值，即函数的返回值不能是void
        3. 函数在使用之前，必须有对应的定义语句。若是先声明后定义，定义也必须在调用之前。
        4. return返回的表达式必须是常量表达式。
     */
    return 0;
}