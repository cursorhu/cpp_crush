#include <string>
#include <iostream>

using namespace std;

int main(){
    string s;

    //read all std input until End-Of-File, and output as words.
    while(cin >> s){
        cout << s << endl;
    }

    //read std input and output as lines
    //while(getline(cin, s)){
    //    cout << s << endl;
    //}

    return 0;
}