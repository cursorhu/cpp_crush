//clear two cases:
// a) derived class overload base class function, 
// b) derived class implement the base class virtual function.

#include <iostream>

class Base {
public:
    virtual int fcn();
};

class D1 : public Base {
public:
    // hides fcn in the base; this fcn is not virtual
    int fcn(int); // parameter list differs from fcn in Base
    // D1 inherits definition of Base::fcn()
};

class D2 : public D1 {
public:
    int fcn(int); // nonvirtual function hides D1::fcn(int)
    int fcn();    // redefines virtual fcn from Base
};

//definitions
int Base::fcn() { std::cout << "Base::fcn()" << std::endl; }
int D1::fcn(int i) { std::cout << "D1::fcn(int)" << std::endl; return i;}
int D2::fcn(int i) { std::cout << "D2::fcn(int)" << std::endl; return i;}
int D2::fcn() { std::cout << "D2::fcn()" << std::endl; return 0; }

int main(){

    Base b; D1 d1; D2 d2;
    
    d1.fcn(1);
    //d1.fcn(); //error: cannot call base class function from derived class object without explictly Base::fcn()
    d2.fcn(1);
    d2.fcn();

    b.fcn(); //object calling way shall call Base::fcn(), not derived.

    Base *pd = &d2; //Runtime Dynamic Binding must use pointer or reference
    pd->fcn();

    return 0;
}
