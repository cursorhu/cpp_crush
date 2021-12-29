### 7.为多态基类声明virtual析构函数
设计一个记录时间的基类：TimeKeeper作为base class, 各种不同的计时方法作为derived class。
```
class TimeKeeper{
public:
    TimeKeeper();
    ~TimeKeeper();
    ...
};
class AtomicClock: public TimeKeeper {...}; //原子钟
class WristClock: public TimeKeeper {...}; //腕表
...
```

使用工厂模式，通过以下调用，返回一个**指向derived class对象的base class指针**:
```
TimeKeeper* ptk = getTimeKeeper(); //创建基类对象的heap空间，返回指针
...
delete ptk; //释放heap
```

**通过父类指针释放子类对象的heap会发送什么：**
会直接调用父类的析构函数，而不是调用子类的析构函数，这将导致“局部销毁”。
因为调用的是父类析构函数，只析构了子类对象中的基类数据部分，而子类特有的部分没有析构，造成内存泄漏。

**如何让析构自动调用子类的析构函数：**
父类析构定义为虚函数, 那么利用父类指针调用此析构时，会找到子类实现的虚函数表，最终调用到子类析构函数
```
class TimeKeeper{
public:
    TimeKeeper();
    virtual ~TimeKeeper();
    ...
};
```
**什么时候定义父类析构为虚函数：**
当父类包含任意virtual函数时，表示它被意图设计为base class，其析构函数应该定义为虚函数；
当父类不包含virtual函数时，表示它不可作为base class，其析构函数不应该定义为虚函数

所有STL容器，例如string, vector, list, set, unordered_map，都是不带virtual析构函数的class, 
因此绝不要继承STL容器类，以下是典型错误：
```
class MyString: public std::string{
    ...
};
```
**析构函数的调用顺序**
从最底层子类(most derived)的析构开始调用，依次向上调用各base class的析构

