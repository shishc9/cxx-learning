#include <iostream>
#include <vector>
#include <typeinfo>
#include <string>

using std::vector;

class Base2 {
public:
    Base2(){}
    int x;
};

template <typename T>
class Base {
public:
    void func(T& container) {
        m_it = container.begin();
    }

    auto get_m_it() {return m_it;}
private:
    //typename T::iterator m_it; 错误写法，因为T::iterator不能包含所有的迭代器类型，当T是一个const容器时，应当使用const_ite.
    decltype(T().begin()) m_it;
};

int main() {
    /* decltype 与 auto 功能一样，都是在编译时期进行自动类型推导。 */

    /* decltype 推导规则 */
    /**
     * usage: decltype(exp) varname = value;
     * 如果 exp 是一个不被括号 () 包围的表达式，或者是一个类成员的访问表达式，或者是一个单独的变量，那么 decltype(exp) 的类型与 exp 一致。
     * 如果 exp 是一个函数调用，那么 decltype(exp)的类型与函数返回值类型一致。
     * 如果 exp 是一个左值，或者被括号 () 包围，那么类型就是 exp 的引用；假设 exp 的类型为T，那么 decltype(exp) 的类型就是 T&。
     */


    // eg1. exp是一个普通的表达式
    int n1 = 0;
    const int& r = n1;

    decltype(n1) a = n1; // a => int
    decltype(r) b = n1; // b => const int&

    // eg2. exp是一个函数调用 [函数需要带上参数，但这仅仅是形式，并不会真正执行函数代码]
    int& func_int_r(int, char);
    int&& func_int_rr(void);
    int func_int(double);

    const int& func_cint_r(int, int, int);
    const int&& func_cint_rr(void);

    decltype(func_int_r(100, 'A')) a2 = n1; // a => int&
    decltype(func_int_rr()) b2 = 0; // b => int&&
    decltype(func_cint_r(1,2,3)) x = n1; // x => const int&

    // eg3. exp是左值，或者被()包围
    const Base2 obj;
    decltype(obj.x) a1 = 0; // 类成员的访问表达式，a1 => int
    decltype((obj.x)) b1 = a; // 带右括号， b1 => int&

    /* 左值是指那些表达式执行结束后依然存在的数据，也就是持久性数据；右值是指那些表达式执行结束后不再存在的数据，也就是临时性的数据。
     * 有一种很简单的方法来区分左值与右值，对表达式取地址，如果编译器不报错就为左值，否则为右值。
     */
    int n = 0, m = 0;
    decltype(n + m) c = 0; // n+m 得到一个右值，c => int
    decltype(n = n + m) d = c; // n=n+m 得到一个左值，d => int&



    /* 一个实际中的例子。auto只能用于类的静态成员，不能用于普通成员，如果想要推导普通成员的类型，就必须使用decltype */
    const vector<int> v;
    Base<const vector<int>> obj2;
    obj2.func(v);
    std::cout << "m_ite type is:" << typeid(obj2.get_m_it()).name() << std::endl;
    
    return 0;
}