#include "mystring.hpp"

int main(){
    char word[12] = "helloworld\n";
    String s1(word); //call constructor
	String s2(s1); //call copy-constructor
    String s3 = String(0); //call constructor
    s3 = s1; //call assign-operator
	
    std::cout << s1 << s2 << s3 << std::endl;  //call stream-operator

    return 0; //call destructor when the process ends.
}