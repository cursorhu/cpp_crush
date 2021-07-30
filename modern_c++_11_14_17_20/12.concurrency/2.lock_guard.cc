#include <iostream>
#include <thread>
#include <mutex>

int v = 1;

void critical_section(int change_v) {
    static std::mutex mtx;
    // 有两种方法对临界区 加锁和解锁：
    // 1. lock()上锁，unlock()解锁：其缺陷是 unlock()不一定能执行到，例如临界区发生异常
    // 2. C++11 提供 RAII 风格的 std::lock_gurad，程序员只在临界区前调用一次，不用手动调用 unlock()
    // lock_gurad 保证不管线程函数 正常返回还是中途抛出异常，只要引发堆栈回退，就自动调用了 unlock()
    std::lock_guard<std::mutex> lock(mtx);
    // 临界区：执行竞争操作
    v = change_v;
    // 离开函数作用域后 lock_guard 保证 mtx 被释放
}

int main() {
    std::thread t1(critical_section, 2), t2(critical_section, 3);
    t1.join();
    t2.join();
    std::cout << v << std::endl;
    return 0;
}