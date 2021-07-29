#include <iostream>
#include <functional>


using foo1 = void(int); // 定义函数类型, using 是别名语法
void functional(foo1 f) { // 定义在参数列表中的函数类型 foo 被视为退化后的函数指针类型 foo*
    f(1); // 通过函数指针调用函数
}

int foo2(int para) {
    return para;
}

int foo3(int a, char c, float f)
{
    std::cout << a << std::endl;
    std::cout << c << std::endl;
    std::cout << f << std::endl;
    return 0;
}

int main() {
    ////函数对象作为函数指针传递
    //定义一个匿名函数对象
    auto f = [](int value) {
        std::cout << value << std::endl;
    };

    f(1); // lambda 表达式直接调用
    //当 Lambda 表达式的捕获列表为空时，闭包对象还能够转换为函数指针值进行传递
    functional(f); // 传递闭包对象，隐式转换为 foo* 类型的函数指针值
    
    //// std::function <ret(args)> 示例
    // std::function 包装了一个返回值为 int, 参数为 int 的函数
    std::function<int(int)> func1 = foo2;
    int base = 10;
    std::function<int(int)> func2 = [&](int value) -> int {
        return value + base;
    };
    std::cout << func1(1) << std::endl;
    std::cout << func2(1) << std::endl;


    //// std::bind 和 std::placeholder 示例
    // std::bind 用来绑定函数调用的参数，有时候可能并不一定能够一次性获得调用某个函数的全部参数，
    // std::placeholder 将部分调用参数提前绑定到函数身上成为一个新的对象，然后在参数齐全后完成调用。
    // 使用 std::placeholders::_1 来对被 bind 的函数的第一个参数进行占位， 同理_2，_3 表示第2, 3 个参数占位
    auto bindFunc1 = bind(foo3, std::placeholders::_1, 'A', 100.1);
    bindFunc1(10); //只需要输入第一个参数即可调用

    auto bindFunc2 = bind(foo3, std::placeholders::_2, std::placeholders::_1, 100.1);
    bindFunc2('B', 10); //注意bindFunc2输入参数顺序并不是foo3的参数顺序，bind 不仅可以决定要输入什么参数，还可以改变参数顺序

    auto bindFunc3 = bind(foo3, std::placeholders::_2, std::placeholders::_3, std::placeholders::_1);
    bindFunc3(100.1, 30, 'C');

    return 0;
}
