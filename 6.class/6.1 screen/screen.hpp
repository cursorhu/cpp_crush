#include <string>

//a class is defined in .hpp (C++ header file), because it defines a date type that package private data and public methods
//we can understand it as a user-defined data type, it's definition and usage is just like normal data types.
class Screen {
// what "public" means:
// Members(typically functions) defined after a public label are accessible(visible) to all parts of the program.  
public:
    //this type-define only work for this class's scope.
    typedef std::string::size_type index;

    //constructor function is same name as class, so that compile recognize it as a constructor.
    //like any other function, a constructor has a name, a parameter list, and a function body, But have NO return data
    //constructor may also contain a constructor initializer list
    //constructor initializer list format: initilize data members after constructor(): and before { }
    //what's advantage of initializer list:
    //data members are initilized when creating object. if we initilize them inside function, 
    //they are initlized to default value when creating object, and then do data copy to set data members a given value inside function. 
    //It's more efficient to use constructor initializer list.
    //we can set some parameters default value at constructor definition. if caller not input these values, the default value takes work.
    //notice the initilization format of "contents": it receives input parameters, and follows string creation format: string s(size, value)
    Screen(index ht, index wd, index c = 0): contents(ht * wd, ' '), cursor(c), height(ht), width(wd){} //user-defined constructor
    //user-defined constructor and default constructor may be overloaded functions. object creation format will decide which to use.
    //default constructor, if we want to use default constructor while we already defined constructor like above. we must declare it explictly.
    //if we do not have a user-defined constructor, then we do not need to explicitly declare default constructor. compiler will do this.
    Screen(){} 

    // return character at the cursor or at a given position
    // the two get() are overloaded functions, the caller format of get() decides which to call.
    // what "const member function" means:
    // A const member function may not change the data members of the object on which it operates, in another word, read only.
    char get() const { return contents[cursor]; } //direct declared and implemented in class
    char get(index ht, index wd) const; //declared in class and implemented in .cc
    //Member functions that are defined inside the class, are automatically treated as inline
    //we can also explicitly declare a member function as inline
    //inline means the function instructions have copies at each calling. 
    //while the normal function call only have a function entry and using stack
    inline index get_cursor() const;
    
    //set contents value at current cursor.
    // Screen& means return a reference to the Screen object itself
    // by this return, we can do a serial of operations such as screen.set().get() 
    Screen& set(char);
    Screen& set(index, index, char); //parameter in declaration may only declare type
    //move cursor to (r,c)
    Screen& move(index r, index c);

    //return the contents.
    //usually return reference (&) but not data, to avoid unnecessary data copy when return.
    const Screen& display(std::ostream& os) const;

// Members(typically data members) defined after a private label are not accessible(hidden) to code that uses the class
private:
    std::string contents;
    index cursor;
    index height, width;
};

//inline function defined in hpp, because it has no difference to function that defined inside the class
inline Screen::index Screen::get_cursor() const{
    return cursor;
}
