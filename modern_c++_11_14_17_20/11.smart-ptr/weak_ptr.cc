#include <memory>
#include <iostream>

using namespace std;

class Parent
{
public:
    //shared_ptr<Child> child;
    weak_ptr<Child> child;
};
 
class Child
{
public:
    //shared_ptr<Parent> parent;
    weak_ptr<Parent> parent;
};

int main(){
    shared_ptr<Parent> pA(new Parent); // PA = 1
    shared_ptr<Child> pB(new Child); // PB = 1
    // 弱引用，不增加计数
    pA->child = pB; // PB = 1
    pB->parent = pA; // PA = 1

    return 0; // PA = 0, PB = 0; 因此 new 出来的 Parent 和 Child 都被释放，没有内存泄漏
}