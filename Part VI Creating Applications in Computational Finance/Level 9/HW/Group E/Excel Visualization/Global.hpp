//Global.hpp is the header file that declares 
//global (non-template) functions for the Group A,B project
#ifndef GLOBAL_HPP					//If GLOBAL_HPP is undefined
#define GLOBAL_HPP					//Define it

#include "EuropeanOption.hpp"

//Declaring a global function that prints the elements of a std::vector<double>
void Print_Vec(const std::vector<double>& Vec);

//Declaring a global function that prints the elements of a matrix (a vector of vector doubles)
void Print_Matr(const std::vector<std::vector<double> >& Matrix);
#endif	//! GLOBAL_HPP