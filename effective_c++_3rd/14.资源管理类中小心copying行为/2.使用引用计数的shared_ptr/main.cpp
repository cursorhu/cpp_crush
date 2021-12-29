#include "lock.h"

int main()
{
    std::mutex m;
    Lock m1(&m); 
    Lock m2(m1); 
}