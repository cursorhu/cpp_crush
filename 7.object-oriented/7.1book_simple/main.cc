#include "book_item.hpp"
#include <iostream>
using namespace std;

void print_total(ostream &, const Item_base&, size_t);

int main(){
    
     Item_base item;           // object of base type
     // ok: use pointer or reference to Item_base to refer to an Item_base object
     print_total(cout, item, 10);    // passes reference to an Item_base object
     Item_base *p = &item;     // p points to an Item_base object

     Bulk_item bulk;           // object of derived type
     // ok: can bind a pointer or reference to Item_base to a Bulk_item object
     print_total(cout, bulk, 10);    // passes reference to the Item_base part of bulk
     p = &bulk;                // p points to the Item_base part of bulk

}



// calculate and print price for given number of copies, applying any discounts 
void print_total(ostream &os, 
                 const Item_base &item, size_t n)
{
    os << "ISBN: " << item.book() // calls Item_base::book
       << "\tnumber sold: " << n << "\ttotal price: "
       // virtual call: which version of net_price to call is resolved at run time
       << item.net_price(n) << endl;
}
