//Global.cpp is the source file that defines and 
//implements global (non-template) functions for the Group A,B project
#include "Global.hpp"

//Defining a global function that prints the elements of a std::vector<double>
void Print_Vec(const std::vector<double>& Vec)
{
	for (int i = 0; i != Vec.size(); i++)								//For 0<=i<size
	{
		std::cout << "[" << Vec[i] << "]";								//Print "[Vec[0]][Vec[1]]...[Vec[size-1]]"
	}
	std::cout << std::endl;												//Print a new line when finished with the for loop
}

//Defining a global function that prints the elements of a matrix (a vector of vector doubles)
void Print_Matr(const std::vector<std::vector<double> >& Matrix)
{
	for (const std::vector<double>& row : Matrix)						//For the rows of the matrix (Using Range-based for loop which was added in C++11)
	{
		Print_Vec(row);													//Call Print_Vec function and print the row and a new line for each iteration
	}
}