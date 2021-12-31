#include <set>
#include <vector>
#include <iostream>

using namespace std;

int main(){
    
    // define a vector with 20 elements, holding two copies of each number from 0 to 9
    vector<int> ivec;
    for (vector<int>::size_type i = 0; i != 10; ++i) {
    ivec.push_back(i);
    ivec.push_back(i); // duplicate copies of each number
    }
    // iset holds unique elements from ivec
    set<int> iset(ivec.begin(), ivec.end()); //notice this creation of set.
    cout << ivec.size() << endl; // prints 20
    cout << iset.size() << endl; // prints 10

    //try insert again, all key already exist so no change at all.
    iset.insert(ivec.begin(), ivec.end());

    set<int>::iterator iter = iset.find(1);
    cout << "find 1 exist or not：" << *iter << endl;
    
    cout << "count how many 1 exist：" << iset.count(1) << endl;

    cout << "erase all key" << endl;
    iset.erase(iset.begin(), iset.end()); //erase all
    cout << "count how many key exist：" << iset.size() << endl;
    //cannot use iterator to access element that erased!
    //cout << "count how many " << *iter << " exist：" << iset.count(*iter) << endl;
    
}
