#include "student.hpp"
#include <iostream>

using namespace std;

//we implement the detail of copy-constructor, operation-constructor, and destructor here.
//though these function is not in class, the :: makes the function scope is same as class.
//so that inside Student can directy access class data members.
//copy-constructor can also use constructor initializer list !
Student::Student(const Student & s):
    name(s.name), scores(s.scores)
{
    cout << "Student copy-constructor" << endl;
}

//destructor do nothing here, data members will be freed when class object is freed
Student::~Student()
{
    cout << "Student destructor" << endl;
}

//operator constructor
//Note the :: is used before operator=
//we can understand operator= as a special function name.
//Student& is return type
Student& Student::operator=(const Student& s)
{
    //this point to current class object, it can be hide inside class member function
    //here we explictly use this->name to distinguish with s.name
    this->name = s.name;
    this->scores = s.scores;
    cout << "Student operator constructor" << endl;
    return *this; //must return *this, it reference to the left-hand object of operator "="
}

