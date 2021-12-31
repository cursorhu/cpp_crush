#include <map>
#include <set>
#include <iostream>

using namespace std;

typedef multimap<string, int>::iterator multi_iter;

int main(){

    multimap<string, int> student;
    student.insert(make_pair("Jack", 18));
    student.insert(make_pair("Jack", 178));
    student.insert(make_pair("Rose", 18));
    student.insert(make_pair("Rose", 160));

    //why only multi-map and multi-set use lower-bound/upper_bound ?
    //in fact it's just same as begin/end in map/set, just because the key may be repetitive.
    multi_iter beg = student.lower_bound("Jack"),
               end = student.upper_bound("Rose");
    // loop through the number of entries there are for this author
    while (beg != end) {
        cout << beg->second << endl; // print each title
        ++beg;
    }

    //another way to get the "first" and "last"
    // equal_range return a pair of iterators that denote range of elements for target key
    pair<multi_iter, multi_iter> pos = student.equal_range("Jack");
    // loop through the number of entries there are for this author
    while (pos.first != pos.second) {
        cout << pos.first->second << endl;
        ++pos.first;
    }

}