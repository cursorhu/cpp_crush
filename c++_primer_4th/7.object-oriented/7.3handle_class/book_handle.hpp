#include <stdexcept>
#include <set>
#include <iostream>
#include <string> //std:string
#include <cstddef> //std::size_t

//the Item_base and Bulk_item is same as 7.1book_item
//just add a function clone() to create class object and response pointer to object pointer handler: Sales_item
class Item_base {
public:
    virtual Item_base* clone() const
        { return new Item_base(*this); }

    //constructor
    Item_base(const std::string &book = "", double sales_price = 0.0):
            isbn(book), price(sales_price) { 
        std::cout <<  "Item_base constructor" << std::endl;
    }
    //copy constructor using initilization list.
    Item_base(const Item_base& ib): isbn(ib.isbn), price(ib.price) { 
        std::cout <<  "Item_base copy-constructor" << std::endl; 
    }
    //assignment operator
    Item_base& operator= (const Item_base& ib) {
        std::cout <<  "Item_base operator=" << std::endl; 
        if(&ib == this)
            return *this;
        this->isbn = ib.isbn; 
        this->price = ib.price;
        return *this;
    }

    virtual ~Item_base() { std::cout <<  "Item_base destructor" << std::endl; }

    std::string book() const 
        { return isbn; }

    virtual double net_price(std::size_t n) const 
        { return n * price; }

private:
    std::string isbn;     // identifier for the item

protected: 
    double price;
};

class Bulk_item : public Item_base {
public:
    Bulk_item* clone() const
        { return new Bulk_item(*this); }

    // other members as before
    Bulk_item(): min_qty(0), discount(0.0) { 
        std::cout <<  "Bulk_item constructor 1" << std::endl; 
    }
    // overloaded version constructor: 
    Bulk_item(const std::string& book, double sales_price,
            std::size_t qty = 0, double disc_rate = 0.0):
            Item_base(book, sales_price), //explictly call the base class constructor in initilize list.
            min_qty(qty), discount(disc_rate) { 
        std::cout <<  "Bulk_item constructor 2" << std::endl;     
    } 
    // copy constructor
    Bulk_item(const Bulk_item& bi):  Item_base(bi), min_qty(bi.min_qty), discount(bi.discount) { 
        std::cout <<  "Bulk_item copy-constructor" << std::endl; 
    }

    //assignment operator
    Bulk_item& operator= (const Bulk_item& bi) {
        std::cout <<  "Bulk_item operator=" << std::endl; 
        //The assignment operator must, as always, guard against self-assignment.
        if(&bi == this)
            return *this;
        Item_base::operator=(bi); // assigns the base part by calling base class assignment operator
        this->min_qty = bi.min_qty; //assigns the derived part.
        this->discount = bi.discount;
        return *this; //do not forget to return class object!
    }

    ~Bulk_item(){std::cout <<  "Bulk_item destructor" << std::endl;}

    double net_price(std::size_t) const;

private:
    std::size_t min_qty; // minimum purchase for discount to apply
    double discount;     // fractional discount to apply
};


// use counted handle class for the Item_base hierarchy
class Sales_item {
    friend class Basket;
public:
    // default constructor: unbound handle
    Sales_item(): p(0), use(new std::size_t(1)) { }
    // attaches a handle to a copy of the Item_base object
    Sales_item(const Item_base& item): 
        p(item.clone()), use(new std::size_t(1)) { }
    // copy control members to manage the use count and pointers
    Sales_item(const Sales_item &i):
            p(i.p), use(i.use) { ++*use; }
    ~Sales_item() { decr_use(); }
    Sales_item& operator=(const Sales_item&);
    // member access operators
    const Item_base *operator->() const { if (p) return p;
        else throw std::logic_error("unbound Sales_item"); }
    const Item_base &operator*() const { if (p) return *p;
        else throw std::logic_error("unbound Sales_item"); }

private:
    Item_base *p;        // pointer to shared item
    std::size_t *use;    // pointer to shared use count
    // called by both destructor and assignment operator to free pointers
    void decr_use()
        { if (--*use == 0) { delete p; delete use; } }
};


// compare defines item ordering for the multiset in Basket
inline bool
compare(const Sales_item &lhs, const Sales_item &rhs)
{
    return lhs->book() < rhs->book();
}

//This class holds the customer's purchases in a multiset of Sales_item objects. 
//We use a multiset to allow the customer to buy multiple copies of the same book
class Basket {
    // type of the comparison function used to order the multiset
    typedef bool (*Comp)(const Sales_item&, const Sales_item&);
public:
    // make it easier to type the type of our set
    typedef std::multiset<Sales_item, Comp> set_type;
    // typedefs modeled after corresponding container types
    typedef set_type::size_type size_type;
    typedef set_type::const_iterator const_iter;
    Basket(): items(compare) { } // initialze the comparator
    void add_item(const Sales_item &item)
                        { items.insert(item); }
    size_type size(const Sales_item &i) const
                        { return items.count(i); }
    double total() const; // sum of net prices for all items in the basket
private:
    std::multiset<Sales_item, Comp> items;
};



