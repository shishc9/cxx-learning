#include <bits/stdc++.h>
using namespace std;

std::string getDataFromDB(std::string token) {
    std::string data = "get token :: " + token;
    return data; 
}

int main() {
    // 函数初始化 packaged_task 对象，指定返回值与参数
    std::packaged_task<std::string(std::string)> task(getDataFromDB);
    // future 获取返回值并暂存
    std::future<std::string> result = task.get_future();
    // 将任务交给线程执行，并进行传参
    std::thread th(std::move(task), "Arg");

    // 获取返回值，这一步会阻塞
    std::string data = result.get();
    std::cout << data << std::endl;

    return 0;
}