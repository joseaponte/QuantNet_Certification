//Header file for the Sum() functions

#ifndef SUM_HPP				//If SUM_HPP is not yet defined
#define SUM_HPP				//Define it

#include <map>				//Include map header
#include <iostream>			//Include iostream header
#include <list>				//Include list header
#include <vector>			//Include vector header

using namespace std;

template<typename T>
double Sum(const T& source);						//Template function called Sum() that accepts the template argument T as input and returns a double
//Calculates the sum of the complete container

template<typename T_2>
double Sum(const T_2& start, const T_2& end);		//Also create a Sum() function that calculates the sum between two iterators
//Calculates the sum of a portion of the container

template<typename T_3>
double Sum(const map<T_3, double>& M);				//Sum() that takes a map<T, double> and add the doubles from the beginning to the end
//Calculates the sum of the entire map

#ifndef SUM_CPP
#include "Sum.cpp"
#endif
#endif