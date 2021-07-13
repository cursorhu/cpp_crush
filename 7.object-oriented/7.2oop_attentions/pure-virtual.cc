#include <iostream>

class Base {
public:
    // A pure virtual function is specified by writing = 0 after the function parameter list
    // Defining a virtual as pure indicates that the function provides an interface for sub-sequent types to override
    // A class containing (or inheriting) one or more pure virtual functions is an abstract class. 
    // We may not create objects of an abstract type 
    // We can understand that a pure virtual function/class works as interface declaration for it's derived class to follow.
    virtual int fcn() = 0; //it's only a declaration.
};

class D1 : public Base {
public:
    // defines another interface (pure virtual) with parameter list
    virtual int fcn(int) = 0; 
    // D1 inherits definition of Base::fcn()
};

//Implementation class for it's father's interface (pure virtual) declaration.
class D2 : public D1 {
public:
    int fcn(int); // implement the D1::fcn(int)
    int fcn();    // implement the Base::fcn()
};

//pure virtual function need no definition, they only declares.
//int Base::fcn() { std::cout << "Base::fcn()" << std::endl; }
//int D1::fcn(int i) { std::cout << "D1::fcn(int)" << std::endl; return i;}
int D2::fcn(int i) { std::cout << "D2::fcn(int)" << std::endl; return i;}
int D2::fcn() { std::cout << "D2::fcn()" << std::endl; return 0; }

int main(){

    //Base b; D1 d1; //error: cannot create pure virtual class object.
    D2 d2;
    
    d2.fcn(1);
    d2.fcn();

    Base *pd = &d2; //Runtime Dynamic also supported for abstract class
    pd->fcn();

    return 0;
}