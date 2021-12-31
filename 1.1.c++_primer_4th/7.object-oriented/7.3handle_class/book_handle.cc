#include "book_handle.hpp"

// use-counted assignment operator; use is a pointer to a shared use count
Sales_item&
Sales_item::operator=(const Sales_item &rhs)
{
    ++*rhs.use;
    decr_use();
    p = rhs.p;
    use = rhs.use;
    return *this;
}

double Bulk_item::net_price(size_t cnt) const
{
    if (cnt >= min_qty)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

double Basket::total() const
{
    double sum = 0.0; // holds the running total

    /* find each set of items with the same isbn and calculate
    * the net price for that quantity of items
    * iter refers to first copy of each book in the set
    * upper_bound refers to next element with a different isbn
    */
    for (const_iter iter = items.begin();
                            iter != items.end(); iter =
                            items.upper_bound(*iter))
    {
        // we know there's at least one element with this key in the Basket
        // virtual call to net_price applies appropriate discounts, if any
        sum += (*iter)->net_price(items.count(*iter));
    }
    return sum;
}
