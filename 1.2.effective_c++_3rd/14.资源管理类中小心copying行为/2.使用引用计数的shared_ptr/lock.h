#include <iostream>
#include <mutex>
#include <memory> //smart pointer

class Lock{
public:
    //以mutex指针构造智能指针，同时指定删除器，即智能指针检查计数为0时调用的对象析构函数
    Lock(std::mutex * m) 
    : mutexPtr(m, deleter) 
    {
        mutexPtr->lock();
        std::cout << "lock" << std::endl;
    }
    void deleter()
    {
        mutexPtr->unlock();
        std::cout << "unlock" << std::endl;
    }
    //不需要写析构，shared_ptr会调用删除器
private:
    std::shared_ptr<std::mutex> mutexPtr;
};

