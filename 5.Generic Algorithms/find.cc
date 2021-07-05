#include <algorithm>    // std::find
#include <vector>
#include <list>       
#include <iostream>     

using namespace std;

int main(){

    /*** find a element in vector ***/
    vector<int> ivec;
    ivec.push_back(42);
    // value we'll look for
    int search_value = 42;
    // call find to see if that value is present
    // Note this find is generic for all containers, it has input for range(begin, end), and search value. 
    // It's different with find inside container string.find vector.find map.find
    vector<int>::const_iterator result1 = find(ivec.begin(), ivec.end(), search_value);
    // report the result
    cout << "The value in vector: " << search_value 
    << (result1 == ivec.end() ? " is not present" : " is present") 
    << endl;

    /*** find a element in list ***/
    list<int> ilist;
    ilist.push_back(42);
    //int search_value = 42;
    // call find to look through elements in a list
    list<int>::const_iterator result2 = find(ilist.begin(), ilist.end(), search_value);
    cout << "The value in list: " << search_value
    << (result2 == ilist.end() ? " is not present" : " is present")
    << endl;

    /*** find a element in array ***/
    int ia[6] = {27, 210, 42, 109, 83};
    //int search_value = 42;
    int *result3 = find(ia, ia + 5, search_value);
    cout << "The value in array: " << search_value
    << (result3 == ia + 5 ? " is not present" : " is present")
    << endl;

    return 0;
}
