class Base {
    public:
        void basemem();   // public member
    protected:
        int i;            // protected member
        // ...
    };
    struct Public_derived : public Base {
        int use_base() { return i; } // ok: derived classes can access i
        // ...
    };
    struct Private_derived : private Base {
        int use_base() { return i; } // ok: derived classes can access i
};

int main(){
    Base b;
    Public_derived d1;
    Private_derived d2;
    b.basemem();   // ok: basemem is public
    d1.basemem();  // ok: basemem is public in the derived class
    d2.basemem();  // error: basemem is private in the derived class
}



