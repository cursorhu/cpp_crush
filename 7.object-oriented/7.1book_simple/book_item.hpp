#include <string>

// Item sold at an undiscounted price
// derived classes will define various discount strategies
class Item_base {
public:
    Item_base(const std::string &book = "", double sales_price = 0.0):
                    isbn(book), price(sales_price) { }
    std::string book() const { return isbn; }
    
    // A base class usually should define as virtual any function that a derived class will need to redefine.
    // derived classes will override and apply different discount algorithms
    // this function returns total sales price for a specified number of items
    virtual double net_price(std::size_t n) const { return n * price; }
    //as the root class of an inheritance hierarchy, generally define a virtual destructor
    virtual ~Item_base() { }

// The public and private is global access control
// A derived class is same as other class, can only access public members but not private members
// In another word, private is still private after inheritance
private:
    std::string isbn;     // identifier for the item

// A protected member may be accessed by a derived object but may not be accessed by general user
// In another word, "protected" makes some "private" member "public" for derived class, while "private" for other class
// protected is a blend of private and public:
// Like private members, protected members are inaccessible to users of the class
// Like public members, the protected members are accessible to classes derived from this class.
// protected has another important property:
// A derived object may access the protected members of its base class only through a derived object. 
// The derived class has no special access to the protected members through base type objects.
protected: 
    double price;        
};


// discount kicks in when a specified number of copies of same book are sold
// the discount is expressed as a fraction used to reduce the normal price
class Bulk_item : public Item_base {
public:
    // redefines base version so as to implement bulk purchase discount policy
    double net_price(std::size_t) const;
private:
    //Each Bulk_item object contains four data elements: 
    //It inherits isbn and price from Item_base and defines min_qty and discount
    //Though it contains four data elements, the class object can only access three members, 
    //the base class protected member (price) is not accessible
    std::size_t min_qty; // minimum purchase for discount to apply
    double discount;     // fractional discount to apply
};
