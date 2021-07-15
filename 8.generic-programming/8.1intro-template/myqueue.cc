



//this class describe node in the queue. 
//contain data part: item, pointer part: next
template <typename Type> 
class QueueItem {
// private class: no public section
    QueueItem(const Type &t): item(t), next(0) { }
    Type item;           // value stored in this element
    QueueItem *next;     // pointer to next element in the Queue
};


template <typename Type> 
class Queue {
public:
    // empty Queue
    Queue(): head(0), tail(0) { }
    // copy control to manage pointers to QueueItems in the Queue
    Queue(const Queue &Q): head(0), tail(0) { copy_elems(Q); }
    Queue& operator=(const Queue&);
    ~Queue() { destroy(); }
    
    // return element from head of Queue
    // unchecked operation: front on an empty Queue is undefined
    Type& front()             { return head->item; }
    const Type &front() const { return head->item; }
    void push(const Type &);       // add element to back of Queue
    void pop ();                    // remove element from head of Queue
    bool empty () const {           // true if no elements in the Queue
        return head == 0;
    }
private:
    QueueItem<Type> *head;         // pointer to first element in Queue
    QueueItem<Type> *tail;         // pointer to last element in Queue
    // utility functions used by copy constructor, assignment, and destructor
    void destroy();                // delete all the elements
    void copy_elems(const Queue&); // copy elements from parameter
};