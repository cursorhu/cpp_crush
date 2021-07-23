#include <stack>
#include <queue> //queue & priority_queue
#include <iostream>

using namespace std;

int main(){
    // empty stack
    stack<int> istack;
    // number of elements we'll put in our stack
    const stack<int>::size_type maxsize = 10;
    
    int i = 0;
    while(istack.size() != maxsize){
        // intStack holds 0...9 inclusive
        istack.push(i++);
    }

    cout << "read and pop the stack: "<< endl;
    // look at each value and pop it off the stack
    while(istack.empty() == false){
        // read the top element of the stack
        int value = istack.top();
        cout << value << endl;
        // pop the top element, and repeat
        istack.pop();
    }


    // empty queue
    queue<char> squeue; //note that the items are char but not string.
    priority_queue<char> pqueue;

    string s = "ABCDEFG";
    for(string::iterator iter = s.begin(); iter != s.end(); ++iter){
        squeue.push(*iter);
        pqueue.push(*iter);
    }

    //container adaptor have no iterator, use index
    //FIFO queue cannot use top() to read item
    cout << "read and pop the queue(FIFO): "<< endl; 
    
    const queue<char>::size_type queue_size = squeue.size();
    //do not use squeue.size() in for(;;) loop, the size is reduced at each pop() !
    for(queue<char>::size_type ix = 0; ix != queue_size; ++ix){
        //queue<char>::value_type value = squeue.front(); //read the front item
        cout << squeue.front() << endl; //First-In-First-Out order.
        squeue.pop();   //pop (remove) the front item
        
    }

    //only priority_queue heve method top()
    cout << "read and pop the queue(priority): "<< endl; 
    for(priority_queue<char>::size_type ix = 0; ix != queue_size; ++ix){
        //priority_queue<char>::value_type value = pqueue.top();   //read the highest-priority item
        cout << pqueue.top() << endl;  //Descending order queue from front to end
        pqueue.pop();
    }


}