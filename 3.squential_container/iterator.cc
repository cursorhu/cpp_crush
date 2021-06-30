#include <vector>
#include <list>
#include <iostream>

using namespace std;

class Elements{
    public:
        Elements(int i, string s): id(i), name(s){}
        ~Elements(){}
        int & get_id(){
            return id;
        }
        string & get_name(){
            return name;
        }
    private:
        int id;
        string name;
};

int main(){

    vector<int> ivec;
    const vector<int>::size_type size = 10;
    for(vector<int>::size_type ix = 0;ix != size; ++ix){
        ivec.push_back(ix);
    }

    //iter point to middle element
    vector<int>::iterator iter = ivec.begin() + ivec.size()/2;
    cout << "middle of ivec: " << *iter << endl;
    cout << "next elements to middle of ivec: " << *++iter << endl; //++iter make the iter move persistently!
    cout << "last elements of ivec: " << *(--iter + ivec.size()/2 -1) << endl; //iterator + n is only available for vector/deque

    //init a class type element
    Elements e(1, "first-item");
    //init a vector that element is class type object
    vector<Elements> evec;
    evec.push_back(e); 
    //use iterator to fetch element and its members
    vector<Elements>::iterator iter2 = evec.begin();
    cout << "first elements of evec: " << "id: " << iter2->get_id() << " name: " << iter2->get_name() << endl;

    return 0;

}