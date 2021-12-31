#include "lock.h"

int main()
{
    std::mutex m;
    Lock m1(&m); //构造一个RAII风格的lock对象
    Lock m2(m1); //当RAII对象被复制，其管理的资源会发生什么？
}