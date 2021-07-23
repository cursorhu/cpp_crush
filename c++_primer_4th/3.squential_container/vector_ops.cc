#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(){
    /* empty vector object */
    vector<int> ivec;
    
    if(ivec.empty())
        cout << "empty vector!" << endl;

    // size_type: Type large enough to hold size of largest object of this type
    for(vector<int>::size_type i = 0; i != 10; ++i){
        //Error using: index can only be used for elements that already exist!
        //ivec[i] = i; //no element to index!
        //Correct using: push-back at empty vector to initilize elements
        ivec.push_back(i);
        //print each element by index
        cout << ivec[i] << endl;
    }

    cout << "size of vector:" << endl << ivec.size() << endl;

}