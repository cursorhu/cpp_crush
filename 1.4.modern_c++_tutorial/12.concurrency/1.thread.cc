#include <iostream>
#include <thread>

int main() {
    // 创建 thread (工作线程)，使用 Lambda 匿名函数风格 
    std::thread t([](){
        std::cout << "hello world." << std::endl;
    });

    // 获取工作线程 id
    std::cout << t.get_id() << std::endl;

    // 实现线程同步
    // 主线程调用 thread 对象 t 的 join 方法
    // 只有工作线程完成后 join 才会返回, 在此之前主线程阻塞在 join
    t.join();

    // 此时 thread 已执行完毕

    return 0; // 主线程销毁，thread 伴随进程一起销毁 
}