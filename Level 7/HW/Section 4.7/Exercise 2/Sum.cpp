//Sum.cpp defines the Sum() functions declarerd in the Sum header file

#ifndef SUM_CPP					//If SUM_CPP is not yet defined
#define SUM_CPP					//Define it

#include "Sum.hpp"				//Include Sum Header file

template<typename T>
double Sum(const T& source)									//Template function called Sum() that accepts the template argument T as input and returns a double
{
	double sum_1 = 0;										//Initialize double for the sum to 0
	typename T::const_iterator end = source.end();			//In the implementation get an iterator(T::const_iterator) for the end
	typename T::const_iterator it_1;						//An iterator for the loop
	for (it_1 = source.begin(); it_1 != end; ++it_1)		//Create a loop that iterates the container T and adds all values
	{
		sum_1 += (*it_1);									//Add each element to sum for each iteration of loop using derefereced iterator
	}
	return sum_1;											//Finally return the sum.
}	//Calculates the sum of the complete container

template<typename T_2>
double Sum(const T_2& start, const T_2& end)				//Also create a Sum() function that calculates the sum between two iterators
{
	double sum_2 = 0;										//Initialize double for the sum to 0
	T_2 it_2;												//An iterator for the loop
	for (it_2 = start; it_2 != end; ++it_2)					//Create a loop that iterates the container T and adds all values
	{
		sum_2 += (*it_2);									//Add each element to sum for each iteration of loop using derefereced iterator
	}
	return sum_2;											//Finally return the sum.
}	//Calculates the sum of a portion of the container


template<typename T_3>
double Sum(const map<T_3, double>& M)						//Sum() that takes a map<T, double> and adds the doubles from the beginning to the end
{
	double sum_3 = 0;													//Initialize double for the sum to 0
	typename map<T_3, double>::const_iterator end = M.end();			//An iterator the for the end
	typename map<T_3, double>::const_iterator it_3;						//An iterator for the loop
	for (it_3 = M.begin(); it_3 != end; ++it_3)							//Loop that iterates the map and adds all values
	{
		sum_3 += (*it_3).second;										//Add each element to the sum for each iteration
	}
	return sum_3;														//Finally return the sum.
}	//Calculates the sum of the entire map

#endif // !SUM_CPP