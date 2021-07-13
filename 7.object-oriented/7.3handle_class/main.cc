#include "book_handle.hpp"
using namespace std;

int main (){

    // bind a handle object to a Bulk_item object
    Sales_item item1(Bulk_item("0-201-82470-1", 50.0, 3, 0.2));
    Sales_item item2(Item_base("0-201-82470-2", 50.0));
    
    cout << item1->net_price(3) << endl;   // virtual call to net_price function
    cout << item2->net_price(3) << endl;

    Basket bsk; // create a multiset container that have many Sales_item objects
    bsk.add_item(item1);
    bsk.add_item(item1);
    bsk.add_item(item1);
    bsk.add_item(item2);
    bsk.add_item(item2);
    bsk.add_item(item2);
    cout << bsk.total() << endl;

    return 0;
}
