//auto_ptr 在 C++11 已废弃，建议使用C++11 智能指针

#include <iostream>
#include <memory> //智能指针

using namespace std;

class Test{
    public:
    Test(const string& str){
        s = str;
        cout << s << endl;
    }

    ~Test(){
        cout << "~Test" << endl;
        //do nothing
    }

    private:
    string s;

};

int main(){
    //注意智能指针本质是个类模板，要用类的初始化方式，不能用 auto_ptr<T> t = new T(xxx) 这种形式
    auto_ptr<Test> t(new Test("hello world")); // C++11 已废弃 auto_ptr 

    return 0; // new 出来的对象分配在堆上，不属于进程内部，所以析构并不会释放成员的内存；需要 auto_ptr 释放掉
}


