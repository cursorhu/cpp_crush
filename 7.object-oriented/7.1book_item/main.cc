#include "book_item.hpp"
#include <iostream>
using namespace std;

void print_total(ostream &, const Item_base&, size_t);

int main(){

     cout << "\ntest new-delete:\n" << endl;

     Item_base *itemP = new Item_base; // same static and dynamic type
     delete itemP;                      // ok: destructor for Item_base called
     itemP = new Bulk_item;             // ok: static and dynamic types differ
     delete itemP;                      // ok: destructor for Bulk_item called

     cout << "\ntest print_total:\n" << endl;

     Item_base item("0-201-82470-1", 50.0);           // object of base type
     // ok: use pointer or reference to Item_base to refer to an Item_base object
     print_total(cout, item, 10);    // passes reference to an Item_base object

     Bulk_item bulk("0-201-82470-1", 50.0, 3, 0.2);    // 20% off if buy book >= 3.
     // ok: can bind a pointer or reference to Item_base to a Bulk_item object
     print_total(cout, bulk, 10);    // passes reference to the Item_base part of bulk

     cout << "\ntest copy and assign:\n" << endl;
     Bulk_item bulkcopy(bulk);
     Bulk_item bulkassign;
     bulkassign = bulk;

     return 0; //desctruct bulk, bulkcopy, bulkassign, and finally item 
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
