#include <string>
#include <iostream>

using namespace std;

int main(){
    string s1 = "string1";
    string s2("string2");
    string s3(s1);
    //printf("s1: %s, s2: %s, s3: %s\n", s1.c_str(), s2.c_str(), s3.c_str());
    cout << s1 << s2 << s3;
}