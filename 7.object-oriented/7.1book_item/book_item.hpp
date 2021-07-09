#include <string>
#include <iostream>

// Item sold at an undiscounted price
// derived classes will define various discount strategies
class Item_base {
public:

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
        //The assignment operator must, as always, guard against self-assignment.
        if(&ib == this)
            return *this;
        this->isbn = ib.isbn; 
        this->price = ib.price;
        return *this;
    }

    // A base class usually should define as virtual any function that a derived class will need to redefine.
    // derived classes will override and apply different discount algorithms
    // this function returns total sales price for a specified number of items
    virtual double net_price(std::size_t n) const { return n * price; } //virtual function in base class.
    //As the root class of an inheritance hierarchy, we generally define a virtual destructor to overload default destructor.
    //why base class desctructor must defined as virtual:
    //desctructor must support dynamic binding, defined as virtual is essential for it. 
    //desctructor is designed to called only once. we cannot call a base class desctuctor in derived class desctuctor.
    //To ensure that the proper destructor is run, dynamic binding decide which class desctuctor to call depending on object.
    //Why the constructor, copy-constructor and operator cannot defined as virtual:
    //Constructors cannot be defined as virtual. 
    //Constructors are run before the object is fully constructed. virtual dynamic binding rely on complete object.
    //Making the class assignment operator virtual is confusing and not useful. because each class should have its own assignment operator.
    //Copy constructor is same as above.
    virtual ~Item_base() { std::cout <<  "Item_base destructor" << std::endl; }

    std::string book() const { return isbn; }

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
    // constructor of derived class.
    // The constructor initializer also implicitly invokes the Item_base DEFAULT constructor to initialize its base-class part
    // Firstly the Item_base part is initialized using the Item_base default constructor.
    // After the Item_base constructor finishes, the members of the Bulk_item part are initialized
    Bulk_item(): min_qty(0), discount(0.0) { 
        std::cout <<  "Bulk_item constructor 1" << std::endl; 
    }
    // overloaded version constructor: 
    // we can initialize both base and derived class object with input parameters:
    Bulk_item(const std::string& book, double sales_price,
            std::size_t qty = 0, double disc_rate = 0.0):
            Item_base(book, sales_price), //explictly call the base class constructor in initilize list.
            min_qty(qty), discount(disc_rate) { 
        std::cout <<  "Bulk_item constructor 2" << std::endl;     
    } 
    // copy constructor
    // same as above constructor, derived copy-constructor must explictly call the base class's 
    // copy constructor for the base class part. also use the initilize list.
    // initilize list have sequence: base class member should be in initilize list front, and derived class in back.
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

    // Derived class's desctructor have some relationship to base class desctructor ? check the cout print.
    // Reverse to the constructor. derived class's desctructor will be firstly called to destroy the derived part members.
    // then base class desctructor is called to destroy the base class part members.
    // The derived destructor no need to explictly call base class's destructor, which is different to 
    // copy constructor and assignment operator, compiler will automatically call the base class destructor.

    ~Bulk_item(){std::cout <<  "Bulk_item destructor" << std::endl;}

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
