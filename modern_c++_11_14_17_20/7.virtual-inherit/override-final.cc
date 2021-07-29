
//override
class Base{
    public:
    virtual void foo(int);
};
class SubClass: public Base{
    virtual void foo(int) override;// 合法
    virtual void foo(float) override;// 非法, 父类没有此虚函数
};

//final
class Base{
    virtual void foo() final;
};
class SubClass1 final: Base{ }; // 合法，因为没有重载Base::foo; 同时声明 SubClass1 不能被继承
class SubClass2: SubClass1{ }; // 非法, SubClass1 已 final
class SubClass3: Base{
    void foo(); // 非法, foo 已 final
};