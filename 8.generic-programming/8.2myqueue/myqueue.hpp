#ifndef __MY_QUEUE_H__
#define __MY_QUEUE_H__

#include <iostream>
#include <vector>

// declaration that Queue is a template needed for friend declaration in QueueItem
template <typename Type> class Queue;

// function template declaration must precede friend declaration in QueueItem
template <typename T>
std::ostream& operator<<(std::ostream&, const Queue<T>&);


//Class QueueItem is a private class that have no public member, because:
//it's only designed to implement Queue and not for general use
//make class Queue a friend of QueueItem so that class Queue can access QueueItem's members 
template <typename Type> 
class QueueItem {
    friend class Queue<Type>;
    // needs access to item and next
    friend std::ostream& operator<< <Type> (std::ostream&, const Queue<Type>&);
    // private class: no public section
    QueueItem(const Type &t): item(t), next(0) { }
    Type item;           // value stored in this element
    QueueItem *next;     // pointer to next element in the Queue
};


//Why in template class Queue:
//we use Queue but not Queue<Type>, while explictly use QueueItem<Type> but not QueueItem ?
//General Rule: when we use the name of a class template, we must specify the template parameters
//One exception: Inside the scope of the template class itself, we can directly use name of the template class name without <parameter>
//because compiler infers the <parameter> of the template 
template <typename Type> 
class Queue {
    // operator<< <Type> () is operator template 
    friend std::ostream& operator<< <Type> (std::ostream&, const Queue<Type>&);
public:
    // constructor: empty Queue
    Queue(): head(0), tail(0) { }
    
    // copy constructor
    Queue(const Queue &Q): head(0), tail(0)
                        { copy_elems(Q); }
    // copy constructor overloaded, for coping from an standard container that have begin and end.
    // Member templates: any typename (template) may have a member that is a typename template or function template
    // A member template follows the same access rules as any other class members
    // A member template is instantiated only when it is used in a program
    // construct a Queue from a pair of iterators on some sequence
    template <typename Iter> 
    Queue(Iter beg, Iter end): head(0), tail(0) 
                        { copy_elems(beg, end); }
    //assign operator
    Queue& operator=(const Queue&); 

    //desctructor
    ~Queue() { destroy(); }
    
    // operations of Queue
    // unchecked operation: front on an empty Queue is undefined
    Type& front()             { return head->item; }
    const Type &front() const { return head->item; } //why overload the front: 
    void push(const Type &);// defined on page 652
    void pop();             // defined on page 651
    bool empty() const {           // true if no elements in the Queue
        return head == 0;
    }
private:
    QueueItem<Type> *head;   // pointer to first element in Queue
    QueueItem<Type> *tail;   // pointer to last element in Queue
    // utility functions used by copy constructor, assignment, and destructor
    // Member functions of a class template are instantiated only when the functions are used (class object calls it).
    // similar to class template, defining an object of a template class instantiate the class. 
    // If a function is never used, then that member function is never instantiated.
    void destroy();                // free the elements in the Queue, sub-function for destructor
    void copy_elems(const Queue&); // copy elements from another Queue, sub-function for copy-constructor
    // version of copy to be used by assign_elems to copy elements from iterator range
    template <typename Iter> void copy_elems(Iter, Iter);
};
 
// Inclusion Compilation Model: include member function definitions as well
// Because compiler need to see the definition of template class or function.
#include "myqueue.cc"

#endif

