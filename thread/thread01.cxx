#include <iostream>
#include <functional>
#include <thread>
#include <future>
#include <exception>

void get_int(std::promise<int>& prom) {
  int x;
  std::cout << "enter an interger value: ";
  std::cin.exceptions(std::ios::failbit);
  try {
    std::cin >> x;
    prom.set_value(x);
  } catch (std::exception&) {
    prom.set_exception(std::current_exception());
  }
}

void print_int(std::future<int>& future) {
  try {
    int x = future.get();
    std::cout << "value: " << x << '\n';
  } catch (std::exception& e) {
    std::cout << "[exception caught: " << e.what() << "]\n";
  }
}

int main() {
  std::promise<int> prom;
  std::future<int> future = prom.get_future();

  std::thread th1(get_int, std::ref(prom));
  std::thread th2(print_int, std::ref(future));

  th1.join();
  th2.join();

  return 0;
}