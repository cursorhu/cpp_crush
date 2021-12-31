#include <utility> //define pair
#include <iostream> 
#include <vector> 

using namespace std;

//it is convenient to use a typedef
typedef pair<string, string> str_map;

int main(){

    pair<string, string> student1("class-1", "James"); // holds two strings
    pair<string, int> age("James", 25); // holds a string and an int

    vector<int> score(2, 100);
    pair<string, vector<int> > class_score("James", score); // holds string and vector<int>
    //define a pair by typedef
    str_map student2("class-1", "Bryant");
    //the first is key, the second is value.
    cout << "key-value of str_map: " << endl;
    cout << student2.first << "," << student2.second << endl;

    cout << "key-value of pair<string, vector<int>>: " << endl;
    cout << class_score.first << "," << class_score.second.front() << "," << class_score.second.back() << endl;

    pair<string, string> user_info;
    string first, last;
    cin >> first >> last;
    //make a pair, type is inferred from cin.
    user_info = make_pair(first, last);
    
    cout << "key-value of user_info: " << endl;
    cout << user_info.first << "," << user_info.second << endl;

    return 0;
}