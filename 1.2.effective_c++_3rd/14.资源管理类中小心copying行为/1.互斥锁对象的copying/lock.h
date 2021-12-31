#include <iostream>
#include <mutex>

class Lock{
public:
    Lock(std::mutex *pm)
    : mutexPtr(pm)
    {
        mutexPtr->lock();
        std::cout << "lock" << std::endl;
    }
    ~Lock(){
        mutexPtr->unlock();
        std::cout << "unlock" << std::endl;
    }
private:
    std::mutex *mutexPtr;
};

