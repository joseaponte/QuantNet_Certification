// TestPoint.cpp
//
// Testing Point
//
// Author Jose Aponte

#include "Point.hpp"


int main(){
    Point p(1.0,1.0);
    if(p==1.0) std::cout<<"Equal!"<<endl;
    else std::cout<<"Not equal"<<endl;
    return 0;
}



/**
 * The first part of the exercise, the program
 * didn't compile because the constructor is 
 * receiving two arguments instead of one.
 * 
 * Also, declaring the constructor as explicit did
 * not run the program
*/