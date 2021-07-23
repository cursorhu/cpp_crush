#include <iostream>

// implement strcmp-like generic compare function
// returns 0 if the values are equal, 1 if v1 is larger, -1 if v1 is smaller

//Is this template OK for all type?
//No, if T is a user defined class, and the class not support operator < or > , the compare function cannot work.
//So, template is only generic for some types, user should be aware of this.
template <typename T>
int compare(const T &v1, const T &v2)
{
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}

using namespace std;

int main ()
{
    // T is int;
    // compiler instantiates int compare(const int&, const int&)
    cout << compare(1, 0) << endl;
    // T is string;
    // compiler instantiates int compare(const string&, const string&)
    string s1 = "abc", s2 = "abe";
    cout << compare(s1, s2) << endl;
    return 0;
}

