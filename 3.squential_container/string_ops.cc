#include <string>
#include <iostream>
#include <cctype> //use c lib in c++: tolower, toupper

using namespace std;

void string_operation(string &s1, string &s2){
    
    /* check empty string */
    //if(s1.size() == 0 || s2.size() == 0){
    if( s1.empty() || s2.empty() ){
        cout << "empty word detected!" << endl;
    }
    else{
        cout << "size of two words:" << endl << s1.size() << " " << s2.size() << endl; 
    }
    /* compare string */
    cout << "compare the two words by dictionary order:" << endl;
    if(s1 == s2){
        cout << s1 << " = " << s2 << endl;
    }else if(s1 < s2){
        cout << s1 << " < " << s2 << endl;
    }else{
        cout << s1 << " > " << s2 << endl;
    }
    /* connect two string */
    cout << "merge the two words:" << endl << s1 + s2 << endl;
    /* get character of string */
    cout << "first character of the the two words:" << endl << s1[0] << " " << s2[0] << endl;
    cout << "last character of the the two words:" << endl << s1[s1.size()-1] << " " << s2[s2.size()-1] << endl;
    /* copy between string */
    cout << "move the word2 to word1:" << endl;
    cout << "two words before move: " << endl;
    cout << s1 << " " << s2 << endl;
    s1 = s2;
    cout << "two words after move: " << endl;
    cout << s1 << " " << s2 << endl;  
    /* capital and small character of string */
    cout << "transfer to upper character: " << endl;
    for(string::size_type i = 0; i < s1.size(); ++i){
        s1[i] = toupper(s1[i]); //here if: cout << s[i] , it output ASCII of each character
    }
    cout << s1 << endl;
}

int main(){

    string s1, s2;
    /* get input string */
    cout << "Please input two words:" << endl;
    cin >> s1 >> s2;

    string_operation(s1, s2);
    return 0;
}