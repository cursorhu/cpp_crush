#include <iostream>
#include <mutex>
#include <memory> //smart pointer

class Lock{
public:
    //以mutex指针构造智能指针，同时指定删除器为unlock，相当于同时定义了智能指针释放时所调用的析构函数
    Lock(std::mutex *pm) 
    : mutexPtr(pm, std::mutex::unlock) 
    {
        mutexPtr.get()->lock(); //智能指针的.get()方法可获得其内部的普通指针
        std::cout << "lock" << std::endl;
    }
    //不需要写析构，shared_ptr会调用删除器
private:
    std::shared_ptr<std::mutex> mutexPtr;
};

