#include "myqueue.hpp"

#include <iostream>
#include <vector>
using std::cout; using std::endl; using std::vector;

const int QSIZE = 10;

void check_front_pop(Queue<int> & queue){
    for (int ix = 0; ix != QSIZE; ++ix) {
        int i = queue.front();  // check next item
        if (i != ix)
             cout << "Something's wrong! i = " << i
                  << " ix = " << ix << endl;
        queue.pop();   // and remove it
    }
    if (!queue.empty())
        cout << "Queue is not empty but should be!" << endl;
    else
        cout << "OK, queue empty " << endl;
}

int main() 
{
    Queue<int> queue1;  // default constructor
    for (int ix = 0; ix != QSIZE; ++ix)
        queue1.push(ix);

    //construct q2 q3 based on q1
    Queue<int> queue2(queue1);  // use copy constructor
    Queue<int> queue3 = queue2;  // use asssignment operator for Queue<int> type

    //check each queue and pop all items.
    check_front_pop(queue1);
    check_front_pop(queue2);
    check_front_pop(queue3);
    
    //vector constructed queue
    vector<int> ivec;
    for (int ix = 0; ix != QSIZE; ++ix)
        ivec.push_back(ix);

    Queue<int> queue4(ivec.begin(), ivec.end());  // use asssignment operator for other container type.
    check_front_pop(queue4);

    return 0;
}

