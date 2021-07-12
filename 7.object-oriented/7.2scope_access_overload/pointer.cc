//be careful, the derived class pointer or reference have NO auto conversion.
//because the class type decide its scope. a base class scoped pointer cannot access derived scope member, same is reference.
//must explitly make pointer/reference the derived class type. before use derived class's member.

class Base{
    public:
    int b_func(){ return i; }

    protected:
    int i;
};

class Derived : public Base{
    public:
    int d_func(){ return i; }
};

int main(){

    Derived d;
    //pointer have no auto conversion.
    Derived *pd = &d; //deriverd type pointer
    Base *pb = &d; //base type pointer, assigned by deriverd object.
    
    pd->d_func(); 
    pb->d_func(); //pb is recognized as Base *， Base type have on d_func

    //reference is same as pointer
    Derived &rd = d; //deriverd type reference
    Base &rb = d; //base type reference.
    
    rd.d_func(); 
    rb.d_func(); //rb is recognized as Base &， Base type have on d_func

    //explictly conversion is ok
    pb = (Derived *)&d;
    pb->d_func();

    rb = (Derived &)d;
    rb.d_func();

    return 0;
}