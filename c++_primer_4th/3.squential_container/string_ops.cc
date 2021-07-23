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

    /* string-only operations */
    string ss1("hello world");
    // return substring of 5 characters starting at position 6 (0 based)
    string ss2 = ss1.substr(6, 5); // s2 = world
    // return substring from position 6 to the end of s
    string ss3 = ss1.substr(6); // s3 = world
    
    cout << "ss2: " << ss2 << endl;
    cout << "ss3: " << ss3 << endl;

    string ss4("C++ Primer"); // initialize s to "C++ Primer"
    ss4.append(" 3rd Ed."); // s == "C++ Primer 3rd Ed."
    // insert at end of string, equivalent to s.append(" 3rd Ed.")
    ss4.insert(ss4.size(), " 3rd Ed.");
    cout << "ss4: " << ss4 << endl;
    
    ss4.replace(ss4.size() - 7, 7, "4th Ed.");
    cout << "ss4: " << ss4 << endl;

    /* string find operations */
    string name("AnnaBelle");
    string::size_type pos1 = name.find("Anna"); // pos1 == 0
    cout << "pos1 of Anna in AnnaBelle: " << pos1 << endl;
    
    string numerics("0123456789");
    string str("r2d2");
    string::size_type pos = str.find_first_of(numerics);
    cout << "found number at index: " << pos << " element is " << str[pos] << endl;
}

int main(){

    string s1, s2;
    /* get input string */
    cout << "Please input two words:" << endl;
    cin >> s1 >> s2;

    string_operation(s1, s2);
    return 0;
}