#include <iostream>
#include <thread>
#include <future>

// std::packaged_task 对象内部包含了两个最基本元素，
// 一、被包装的任务(stored task)，任务(task)是一个可调用的对象，如函数指针、成员函数指针或者函数对象，
// 二、共享状态(shared state)，用于保存任务的返回值，可以通过 std::future 对象来达到异步访问共享状态的效果。

int main() {
    // 将一个 lambda 匿名函数封装到 packaged_task 中
    // std::packaged_task 能提供一个std::future对象给该异步操作的创建者，其模板参数为要封装函数的类型
    std::packaged_task<int(int)> task(
        [&](int i){return i;}
        );
    // std::packaged_task::get_future 用于：
    // 获得与 packaged_task 共享状态相关联的 future 对象.
    std::future<int> result = task.get_future();
    // 创建一个工作线程完成处理异步 task
    // 向 thread() 传参必须传引用
    // std::move() 将传参变成右值引用; 用 std::ref() 也可以变成引用 
    std::thread t(std::move(task), 10);
    //std::thread t(std::ref(task), 10);

    // detach() 将子线程和主线程分离：子线程在后台继续运行，主线程失去子线程的控制权；即使主线程结束子线程也不受影响
    t.detach();

    std::cout << "waiting...";
    result.wait(); // 在此阻塞直到异步task完成

    // 输出执行结果
    std::cout << "done!" << std:: endl << "future result is " << result.get() << std::endl;

    return 0;
}