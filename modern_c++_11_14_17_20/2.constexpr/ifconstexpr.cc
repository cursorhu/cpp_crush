#include<iostream>

template<typename T>
auto print_type_info(const T& t){
    ifconstexpr(std::is_integral<T>::value){
        return t +1;
    }else{
        return t +0.001;
    }
}

int main(){
    std::cout << print_type_info(5) << std::endl;
    std::cout << print_type_info(3.14) << std::endl;
}


// 编译时，以上代码转换为如下：

// int print_type_info(constint& t){
//      return t +1;
// }
// double print_type_info(constdouble& t){
//      return t +0.001;
// }
// int main(){
//     std::cout << print_type_info(5)<< std::endl;
//     std::cout << print_type_info(3.14)<< std::endl;
// }