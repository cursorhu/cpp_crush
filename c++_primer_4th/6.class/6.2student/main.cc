#include "student.hpp"
#include <vector>
using namespace std;

int main(){
    
    int temp[3] = {90, 85, 70};
    vector<int> score(temp, temp+3); //initilize by array.
    string name = "Jack";
    
    //call constructor 
    Student Jack = Student(name, score);
    
    //call copy-constructor
    Student JackClone = Student(Jack);
    
    //call operator-constructor 
    JackClone = Jack; //calls operator constructor because this is value assignment.
    //Student JackAssign = Jack; //calls copy constructor, not operator constructor!

    return 0;
}

