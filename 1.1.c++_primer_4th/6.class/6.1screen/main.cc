#include "screen.hpp"
#include <iostream>

int main(){
    
    //ways to create an object of a class
    Screen myscreen1; //implicitly use the default constructor, just like common types definition.
    //Screen myscreen1(); // Error! declares a function, not an object
    Screen myscreen2 = Screen(); //explicitly use the default constructor and "assign to" a object. Infact constructor have no return !
    Screen myscreen3 = Screen(5,10); //explicitly use the default constructor with input parameters
    Screen *myscreen_p = new Screen(5,10); //explicitly use the user-defined constructor with "new", return pointer to the class object
    
    myscreen2.set('2'); //set concent=2 at current cursor
    myscreen3.set(0,0,'3'); //set concent=3 at (0, 0)
    myscreen3.set(0,9,'d'); //set concent=d at (0, 9)

    char ch = myscreen2.get();// calls Screen::get()
    std::cout << ch << std::endl;
    ch = myscreen3.get(0,0); // calls Screen::get(index, index)
    std::cout << ch << std::endl;
    ch = myscreen_p->get(0,0); // calls Screen::get(index, index)
    std::cout << ch << std::endl;
    
    //concents output to cout.
    myscreen3.display(std::cout);
    //a series of calls, based on return of *this
    myscreen3.move(4,7).set('e').move(4,8).set('n').move(4,9).set('d').display(std::cout);

    //return cursor
    std::cout << myscreen3.get_cursor() << std::endl;

    return 0;
}