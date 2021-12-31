#include <algorithm> 
#include <vector>        
#include <iostream>     
#include<iterator> //istream_iterator and ostream_iterator

using namespace std;

int main(){

    vector<int> vec;
    for (vector<int>::size_type i = 0; i != 10; ++i)
        vec.push_back(i); // elements are 0,1,2,...9

    // reverse iterator of vector from back to front
    vector<int>::reverse_iterator r_iter;
    for (r_iter = vec.rbegin(); // binds r_iter to last element
        r_iter != vec.rend(); // rend refers 1 before 1st element
        ++r_iter) // decrements iterator one element
        cout << *r_iter << endl; // prints 9,8,7,...0

    // sorts vec in "normal" order
    sort(vec.begin(), vec.end());
    // sorts in reverse: puts smallest element at the end of vec
    sort(vec.rbegin(), vec.rend());

    return 0;
}