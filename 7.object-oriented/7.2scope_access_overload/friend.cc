//base class and his son
class Base {
    friend class Frnd; //Frnd can access all member(protected and private) of Base
    protected:
    int i;
};

// Frnd has no access to members in D1
class D1 : public Base {
    protected:
    int j;
};

//base class's friend class and friend class's son
class Frnd {
    public:
    int mem(Base b) { return b.i; }  // ok: Frnd is friend to Base
    int mem(D1 d) { return d.i; }    // error: friendship doesn't inherit
};

// D2 has no access to members in Base
class D2 : public Frnd {
    public:
    int mem(Base b) { return b.i; } // error: friendship doesn't inherit
};
