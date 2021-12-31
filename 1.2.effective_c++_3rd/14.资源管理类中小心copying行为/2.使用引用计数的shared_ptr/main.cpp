#include "lock.h"

int main()
{
    std::mutex m;
    Lock lk1(&m); 
    Lock lk2(lk1); 
}