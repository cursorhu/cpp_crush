#include <map>
#include <iostream>

using namespace std;

typedef map<string,int>::value_type KVType;

int main(){
    //At first we must understand map is an array, whose element is pair.
    //We handle it just like a array,though some features are different

    //define an empty map, each element is <string, int> pair
    map<string, int> book;
    //Add element to map, by index
    // Using an index that is not already present ADDs an element with that index to the map
    // This is differently from subscripting an array or vector, whose element must exist. 
    book["C++ Primer 5th"] = 1;

    //Add element to map, by insert, the map element value_type is pair.
    //If the key(e.first) is not in m , inserts a new element with value e.second . 
    //If the key is in m , then m is unchanged.
    book.insert(map<string, int>::value_type("C++ Primer 4th", 2));

    //better way to insert
    book.insert(make_pair("C++ Primer 3rd", 3));
    book.insert(KVType("C++ Primer 2nd", 4));

    //map's iterator is a reference to map container's pair (value_type)
    //the iterator traverse output is ordered by key with ascending dictionary order, not insert order ! 
    for(map<string, int>::iterator iter = book.begin(); iter != book.end(); ++iter){
        cout << iter->first << " " << iter->second << endl;
    }

    //Finding and Retrieving a map Element
    //DO NOT USE index to retrieve a map element! using a subscript has an important side effect: 
    //If that key is not already in the map, then subscript inserts an element with that key, and value is default.
    cout << book["not exist book"] << endl;
    
    //use map.count or map.find to retrieve without create
    //map.count() always returns either 0 or 1, because the key in map is either have one, or not exist.
    if(book.count("not exist book"))
        cout << ++book["not exist book"] << endl;
    
    //map.find() return iterator, use iter->second to get the value
    //if iter == map.end(), the key is not exist.
    map<string,int>::iterator iter = book.find("not exist book");
    if(iter != book.end())
        cout << iter->second << endl;
    //erase element
    //erase of a key returns number of elements removed
    if (book.erase("not exist book"))
        cout << "\'not exist book\' erased" << endl;
    else
        cout << "\'not exist book\' is not exist" << endl;
}