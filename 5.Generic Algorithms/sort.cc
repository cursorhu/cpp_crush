#include <algorithm> 
#include <vector>      
#include <iostream>     

using namespace std;

// comparison function to be used to sort by word length
// call back this function can decide the sort rule.
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

bool isBigger(const string &s1, const string &s2)
{
    return s1 > s2;
}

void traversal_printer(vector<string> &svec){
    for(vector<string>::iterator iter = svec.begin(); iter != svec.end(); ++iter){
        cout << *iter << endl;
    }
}

int main(){

    cout << "please input some words and ctrl+D for EOF, example:" << endl 
    << "the quick red fox jumps over the slow red turtle" << endl; 

    //a "temporary buffer" s is used to get user input from cin and write to vector container.
    //cin cannot push_back to vector directly !
    vector<string> words;
    string s; 
    while(cin >> s){
        words.push_back(s);
    }

    // sort words alphabetically so we can find the duplicates
    cout << "sort the words by default rule (alphabetic order):" << endl;
    sort(words.begin(), words.end());

    traversal_printer(words);

    /* eliminate duplicate words:
    * unique reorders words so that each word appears once in the front portion of words and returns an iterator one past the unique range;
    * unique "removes" adjacent duplicates so that it must be used after sort.
    * and "removes" is not real remove, it just move the unique elements to the front, and duplicated elements to the end.
    */
    cout << "remove the duplicate words:" << endl;
    vector<string>::iterator end_unique = unique(words.begin(), words.end());

    /* erase uses a vector operation to remove the nonunique elements
    * this is real "remove"
    */
    words.erase(end_unique, words.end());

    traversal_printer(words);

    cout << "sort by size:" << endl;
    // sort words by size, but maintain alphabetic order for words of the same size
    stable_sort(words.begin(), words.end(), isShorter);
 
    traversal_printer(words);

    cout << "sort reverse alphabetic order:" << endl;
    stable_sort(words.begin(), words.end(), isBigger);
 
    traversal_printer(words);
    
    return 0;
}