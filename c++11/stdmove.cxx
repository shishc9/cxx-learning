#include <iostream>

/* move函数可以将某个左值强制转化为右值 */

class first{
public:
    first() :num(new int(0)) {
        std::cout << "construct!" << std::endl;
    }

    first(first &&d) :num(d.num) {
        d.num = nullptr;
        std::cout << "first move construct!" << std::endl;
    }
public:
    int *num;
};

class second{
public:
    second() : fir() {}
    second(second&& sec) : fir(std::move(sec.fir)) {
        std::cout << "second move construct" << std::endl;
    }
public:
    first fir;
};

int main() {
    second oth;
    second oth2 = std::move(oth);

    /* output:
        construct!
        first move construct!
        second move construct!
        在31行和22行发生了两次move
     */

    return 0;
}
