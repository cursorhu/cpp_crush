#include <iostream>

//值捕获，有值拷贝
void lambda_value_capture() {
    int value = 1;
    auto copy_value = [value] {
        return value;
    };
    value = 100;
    auto stored_value = copy_value();
    std::cout << "stored_value = " << stored_value << std::endl;
    // 这时, stored_value == 1, 而 value == 100.
    // 因为 copy_value 在创建时就保存了一份 value 的拷贝
}

//引用捕获，没有拷贝
void lambda_reference_capture() {
    int value = 1;
    auto copy_value = [&value] {
        return value;
    };
    value = 100;
    auto stored_value = copy_value();
    std::cout << "stored_value = " << stored_value << std::endl;
    // 这时, stored_value == 100, value == 100.
    // 因为 copy_value 保存的是引用
}

//隐式捕获（最常用）
//可以在捕获列表中只写一个 & 或 = 向编译器声明采用引用捕获或者值捕获
void lambda_implicit_capture() {
    int value = 1;
    auto copy_value_1 = [&] {
        return value;
    };
    auto copy_value_2 = [=] {
        return value;
    };
    value = 100;
    auto stored_value_1 = copy_value_1();
    auto stored_value_2 = copy_value_2();
    std::cout << "stored_value_1 = " << stored_value_1 << std::endl;
    std::cout << "stored_value_2 = " << stored_value_2 << std::endl;
    // 这时, stored_value_1 == 100, stored_value_1 == 1.
}