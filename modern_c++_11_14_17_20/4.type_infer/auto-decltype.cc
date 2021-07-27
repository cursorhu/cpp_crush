#include<initializer_list>
#include<vector>
#include<iostream>
class MagicFoo{
public:
    std::vector<int> vec;
    //initializer_list 风格的构造函数
    MagicFoo(std::initializer_list<int> list){
        // 从 C++11 起, 使用 auto 关键字进行类型推导
        for(auto it =list.begin(); it !=list.end(); ++it){
            vec.push_back(*it);
        }
    }
};


int main(){
    //call initializer_list
    MagicFoo magicFoo ={1,2,3,4,5};
    
    std::cout <<"magicFoo: ";
    for(auto it = magicFoo.vec.begin(); it != magicFoo.vec.end(); ++it){
            std::cout <<*it <<", ";
    }
    std::cout << std::endl;

    //decltype逆向类型并比较
    if(std::is_same<decltype(magicFoo.vec.begin()), int>::value)
    std::cout <<"type magicFoo.vec == type int"<< std::endl;

    return 0;
}