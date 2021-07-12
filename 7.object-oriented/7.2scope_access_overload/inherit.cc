class Base {
    public:
        int basemem() { return i; }  // public member
    protected:
        int i;            // protected member
        // ...
};

class Public_derived : public Base {
    int use_base() { return i; }  // ok: Base::i remains protected in Public_derived
};

class Private_derived : private Base {
    int use_base() { return i; } // error: Base::i is private in Private_derived
};

int main(){
    Base b;
    Public_derived d1;
    Private_derived d2;
    
    b.basemem();   // ok: basemem is public
    d1.basemem();  // ok: basemem is public in the derived class
    d2.basemem();  // error: basemem is private in the derived class
    
    d1.use_base();  // ok: i is public in the derived class
    d2.use_base();  // error: i is private in the derived class
}



