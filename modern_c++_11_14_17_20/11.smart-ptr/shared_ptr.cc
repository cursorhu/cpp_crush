#include <iostream>
#include <memory>
void foo(std::shared_ptr<int> i)
{
    (*i)++;
}
int main()
{
    // auto pointer = new int(10); // illegal, not allow direct assignment
    // Constructed a std::shared_ptr
    auto pointer = std::make_shared<int>(10);
    //可以用智能指针操作对象
    foo(pointer);
    std::cout << *pointer << std::endl; // 11


    //std::shared_ptr 可以通过 get() 方法来获取原始指针
    //通过 reset() 来减少一个引用计数，通过 use_count()来查看一个对象的引用计数
    auto pointer1 = std::make_shared<int>(10);
    auto pointer2 = pointer1; // 引用计数+1
    auto pointer3 = pointer1; // 引用计数+1
    int *p = pointer1.get(); // 这样不会增加引用计数
    std::cout << "pointer1.use_count() = " << pointer1.use_count() << std::endl; // 3
    std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl; // 3
    std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl; // 3
    pointer2.reset();
    std::cout << "reset pointer2:" << std::endl;
    std::cout << "pointer1.use_count() = " << pointer1.use_count() << std::endl; // 2
    std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl; // 0, pointer2 已 reset
    std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl; // 2
    pointer3.reset();
    std::cout << "reset pointer3:" << std::endl;
    std::cout << "pointer1.use_count() = " << pointer1.use_count() << std::endl; // 1
    std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl; // 0
    std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl; // 0, pointer3 已 reset

    // The shared_ptr will be destructed before leaving the scope
    return 0;
}