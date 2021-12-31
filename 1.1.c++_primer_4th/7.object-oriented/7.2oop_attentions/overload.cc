//derived class can overload base class's function member and data member
//derived class can explictly use base class's member even overloaded
//if base class itself have overloaded functions:
//a)A derived class can redefine zero or more of the versions it inherits 
//b)only the redefined in the derived class are accessible through the derived type.
//c)If a derived class wants to make all the overloaded versions available 
//through its type, then it must either redefine all of them or none of them

//derived class overload single function in base class
class Base {
    public:
    int memfcn(){}
};
class Derived : public Base {
    public:
    int memfcn(int num){i = num;} // hides memfcn in the base
    private:
    int i;
};

//base class have overloaded function
//derived class overload all function in base class
class Base2 {
    public:
    int memfcn(){}
    int memfcn(int num){return num;} //Base2 have two overloaded function
};
class Derived2 : public Base2 {
    public:
    int memfcn(){return i;}
    int memfcn(int num){i = num;} // hides memfcn(int num) in the base
    private:
    int i;
};

int main(){
    Derived d; Base b;
    b.memfcn();        // calls Base::memfcn
    d.memfcn(10);      // calls Derived::memfcn
    d.memfcn();        // error: cannot directly call base class's function, it's hidden from derived class object 
    d.Base::memfcn();  // ok: explicitly calls Base::memfcn

    Derived2 d2; Base2 b2;
    b2.memfcn(10);      // calls Base2::memfcn
    d2.memfcn(10);      // calls Derived2::memfcn
    d2.memfcn();        // ok: memfcn is overloaded in Derived2
    d2.Base::memfcn();  // error: Derived2::memfcn(){return i;} already overloaded Base2::memfcn(){}.
}


