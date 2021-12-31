

template<typename...Ts>
void arg_count(Ts... args){
    std::cout <<sizeof...(args)<< std::endl;
}

template<typename T0,typename... T>
void printf(T0 t0, T... t){
    std::cout << t0 << std::endl;
    ifconstexpr(sizeof...(t) > 0) 
        printf(t...);
}


template<typename T1, typename T2>
class MagicType{
public:
    T1 name;
    T2 power;
};

//type-define for template, by "using"
template<typename T1, typename T2>
using DarkMagic = MagicType<T1, T2>;

int main(){

    arg_count();    // 输出0
    arg_count(1);   // 输出1
    arg_count(1,"");    // 输出2

    printf(0, 3.14, "a");

    DarkMagic<"avatarkill", 999> avatarkill;

    return 0;
}