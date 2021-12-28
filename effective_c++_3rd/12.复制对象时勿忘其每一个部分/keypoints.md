### 12.复制对象时勿忘其每一个部分
设计良好的类只会有两个拷贝函数：
- copy构造函数：拷贝构造
- copy-assignment函数：赋值构造

拷贝函数容易漏掉成员的复制，常见以下两种情况：
- 一个类设计好后，新增了成员，但忘记修改对应的拷贝构造和赋值构造函数
- 类继承时，子类的拷贝构造和赋值构造函数，只复制了子类成员，没有调用父类的拷贝构造和赋值构造函数，复制父类成员

类继承是最容易出错的情况，示例如下。

```
//基类
class Customer{
public:
    ...
    Customer(const Customer& rhs);
    Customer& operator=(const Customer& rhs);
private:
    std::string name;
};

Customer::Customer(const Customer& rhs)
: name(rhs.name) //和普通构造函数一样，建议初始化列表构造
{
    ...
}
Customer& Customer::operator=(const Customer& rhs)
{
    name = rhs.name;
    return *this;
}
```

错误的子类拷贝函数：
```
//子类
class VIPCustomer: public Customer{
public:
    ...
    VIPCustomer(const VIPCustomer& rhs);
    VIPCustomer& operator=(const VIPCustomer& rhs);
private:
    int priority;
};

VIPCustomer::VIPCustomer(const VIPCustomer& rhs)
: priority(rhs.priority) 
{
    ...
}
VIPCustomer& VIPCustomer::operator=(const VIPCustomer& rhs)
{
    priority = rhs.priority;
    return *this;
}
```
问题在哪里：
子类只复制了priority，而没有复制父类的name，发生拷贝遗漏！

正确做法：**调用父类的拷贝函数，父类的成员让父类的函数去拷贝**
```
//子类
VIPCustomer::VIPCustomer(const VIPCustomer& rhs)
: Customer(rhs),
  priority(rhs.priority)
{
    ...
}
VIPCustomer& VIPCustomer::operator=(const VIPCustomer& rhs)
{
    Customer::operator=(rhs);
    priority = rhs.priority;
    return *this;
}
```

注意，调用要对应，拷贝构造调用拷贝构造，不要调用赋值构造，反过来同理。
一定要记住，子类的成员可不只有子类中定义的成员，记住这点就不会忘记调用父类的拷贝构造。