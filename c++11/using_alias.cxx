#include <iostream>
#include <map>

int main() {

    /* typedef unsigned int uint_t; 可以重定义一种类型，但这种类型并不是一个新的类型，而是之前类型的一种别名。 */
    /* 
        void func(unsigned int);
        void func(uint_t);  // error: redefinition - 说明是不合法的函数重载
     */

    typedef std::map<std::string, int> map_int_t;
    typedef std::map<std::string, std::string> map_string_t; // 我们需要的其实是一个固定以 std::string 为 key 的 map.

    // 所以旧标准中一般这样定义
    /* template <typename Val>
    struct str_map {
        typedef std::map<std::string, Val> type;
    };

    str_map<int>::type map1; */

    // 必须加上 str_map 这种外敷类，显得十分繁琐。使用 using 的方法如下
    template <typename Val>
    using str_map_t = std::map<std::string, Val>;

    str_map_t<int> map1;


    /* 定义函数指针时，using也显得更加方便 */
    typedef void(*func_t)(int, int);
    using func_t = void(*)(int, int);

}