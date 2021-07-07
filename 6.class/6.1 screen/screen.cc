#include "screen.hpp"
#include <iostream>

//get contents char of target place 
char Screen::get(index r, index c) const
{
    index row = r * width; // compute the row location
    return contents[row + c]; // offset by c to fetch specified character
}
//set contents char of current cursor and return current object
Screen& Screen::set(char c)
{
    contents[cursor] = c;
    return *this; //'this' is a pointer in any class object, that pointer to the object itself.
}
//set contents char of target place and return current object
Screen& Screen::set(index r, index c, char ch)
{
    contents[r * width + c] = ch;
    return *this;
}
//move cursor to target place and return current object
Screen& Screen::move(index r, index c)
{
    index row = r * width; // row location
    cursor = row + c;
    return *this;
}
//display contents and return current object
const Screen& Screen::display(std::ostream& os) const
{	
	os << contents << std::endl;
	return *this; 
}