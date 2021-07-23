#ifndef __MY_QUEUE_CC__ //this .cc is included in .hpp so add this single include control
#define __MY_QUEUE_CC__ //if not, multi-definition error during compile.

#include "myqueue.hpp"
#include <stdexcept>
#include <iostream>
using std::ostream; 

//copy-constructor from another Queue instance
template <typename Type>
void Queue<Type>::copy_elems(const Queue &orig)
{
    // copy elements from orig into this Queue
    // loop stops when pt == 0, which happens when we reach orig.tail
    for (QueueItem<Type> *pt = orig.head; pt; pt = pt->next)
        push(pt->item);  // copy the element
}

//Member Template Definition:
//must include the class-template parameters and member-function template parameters 
//copy-constructor from an standard container instance, such as std::vector<T> 
template <typename Type> template <typename Iter>
void Queue<Type>::copy_elems(Iter beg, Iter end)
{
    while (beg != end) {
       push(*beg);  
       ++beg;
    }
}

template <typename Type> void Queue<Type>::destroy()
{
    while (!empty())
        pop();
}

//push: create node and link to queue
//corner case is push to empty queue.
template <typename Type> void Queue<Type>::push(const Type &val)
{
    // allocate a new QueueItem object
    QueueItem<Type> *pt = new QueueItem<Type>(val);

    // put item onto existing queue
    if (empty())
        head = tail = pt;   // the queue now has only one element
    else {
        tail->next = pt;    // add new element to end of the queue
        tail = pt;
    }
}

template <typename Type> void Queue<Type>::pop()
{
    // pop is unchecked: Popping off an empty Queue is undefined 
    QueueItem<Type>* p = head;  // keep pointer to head so we can delete it
    head = head->next;          // head now points to next element
    delete p;                   // delete old head element
}

template <typename Type>
Queue<Type>& Queue<Type>::operator=(const Queue &rhs)
{
    if (this != &rhs) {
        // destroy elements on this Queue
        destroy();
        copy_elems(rhs);    // copy Queue
    }
    return *this;
}

//operator function template.
//used for outputing QueueItem
template <typename Type>
ostream& operator<<(ostream &os, const Queue<Type> &q)
{
    os << "< ";
    QueueItem<Type> *p;
    for (p = q.head; p; p = p->next)
            os << p->item << " ";
    os <<">";
    return os;
}

#endif



