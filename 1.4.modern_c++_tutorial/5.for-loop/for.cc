#include<iostream>
#include<vector>
#include<algorithm>
int main(){
    std::vector<int> vec ={1,2,3,4};
    if(auto itr = std::find(vec.begin(), vec.end(), 3); itr != vec.end())
        *itr =4;
    //类似其他语言的 foreach element in vec, 直接遍历成员，而不需要关注 vec 的 begin-end
    for(auto element : vec)
        std::cout << element << std::endl;  // read only
    for(auto& element : vec){
        element +=1;    // writeable
    }
    for(auto element : vec)
        std::cout << element << std::endl;// read only
}