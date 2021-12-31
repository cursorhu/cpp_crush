#include <memory>
#include <iostream>

using namespace std;

class Parent
{
public:
    shared_ptr<Child> child;
};
 
class Child
{
public:
    shared_ptr<Parent> parent;
};

int main(){
    shared_ptr<Parent> pA(new Parent); // PA = 1
    shared_ptr<Child> pB(new Child); // PB = 1
    // 循环引用
    pA->child = pB; // PB = 2
    pB->parent = pA; // PA = 2

    return 0; // PA = 1, PB = 1; 因此 new 出来的 Parent 和 Child 都没有释放，产生内存泄漏
}
