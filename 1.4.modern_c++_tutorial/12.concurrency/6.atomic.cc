#include <atomic>
#include <thread>
#include <iostream>
//实例化一个原子类型
std::atomic<int> count = {0};

int main() {
    //检查该原子类型是否支持原子操作
    std::cout << count.is_lock_free() << std::endl;

    std::thread t1([](){
        count.fetch_add(1); // 对原子类型变量 + 1
        count.fetch_sub(1); // 对原子类型变量 - 1
    });
    std::thread t2([](){
        count++;        // 对原子类型变量 + 1，等价于 fetch_add
        count += 1;     // 对原子类型变量 + 1，等价于 fetch_add
    });
    
    t1.join();
    t2.join();
    std::cout << count << std::endl;

    return 0;
}