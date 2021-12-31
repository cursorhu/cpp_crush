
#include <iostream>
#include <memory>
struct Foo {
    Foo() { std::cout << "Foo::Foo" << std::endl; }
    ~Foo() { std::cout << "Foo::~Foo" << std::endl; }
    void foo() { std::cout << "Foo::foo" << std::endl; }
};
void f(const Foo &) {
    std::cout << "f(const Foo&)" << std::endl;
}
int main() {
    // 创建 unique_ptr
    std::unique_ptr<Foo> p1(std::make_unique<Foo>());
    
    // p1 不空, 输出
    if (p1) p1->foo();
    
    // P1 移动给 P2
    std::unique_ptr<Foo> p2(std::move(p1));
    // p2 不空, 输出
    f(*p2);
    if(p2) p2->foo();
    // p1 为空, 无输出
    if(p1) p1->foo();

    // P2 移动给 P1
    p1 = std::move(p2);
    // p2 为空, 无输出
    if(p2) p2->foo();
    // p1 不空, 输出
    if(p1) p1->foo();
    
    return 0; // Foo 的实例会在离开作用域时被销毁
}

