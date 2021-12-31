#include <iostream>
#include <vector>

//never using namespace in header file
//it makes the namespae pollute other namespace which include the header file!
class Student{
public:
    // constructor for class object initilization
    Student(std::string & n, std::vector<int> & s): name(n), scores(s) 
    {
        std::cout << "Student constructor" << std::endl;
    }
    // copy constructor for class object copy-initilization
    Student(const Student & s); //only declare here, definition in .cc
    // assignment operator constructor for class object assignment-initilization
    // note that it must return the class object which is assigned to. 
    Student& operator=(const Student&);
    // destructor, the ~ means "reverse". same as constructor, it has no return.
    ~Student(); //only declare here, definition in .cc

    //we do not declare other operation here...

private:
    std::string name;
    std::vector<int> scores; //scores for class A, B, ...

};

