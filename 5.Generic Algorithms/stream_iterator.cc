#include <algorithm> 
#include <vector>        
#include <iostream>     
#include<iterator> //istream_iterator and ostream_iterator

using namespace std;

int main(){

    //vector<string> svec;

    istream_iterator<string> in_iter(cin), eof; // read ints from cin, define "end" iterator
    ostream_iterator<string> out_iter(cout, "\n"); // read ints from cin, with insert "\n"
    
    // read until end of file, storing what was read in vec
    while (in_iter != eof){
   
        //svec.push_back(*in_iter++);
        //*out_iter++ = svec.back();
        
        *out_iter++ = *in_iter++;
    }

     // copy svec to ostream.
     //copy(svec.begin(), svec.end(), out_iter);
    
   return 0;
}

