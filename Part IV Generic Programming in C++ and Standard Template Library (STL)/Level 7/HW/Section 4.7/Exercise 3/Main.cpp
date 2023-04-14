//Excercise 4.7.3 asks us to practice with STL Algorithms 
//by using the count_if function on a global function and 
//a function object
#include <list>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include "IsLess.hpp"


bool IsLessThan(double Ele);			//Declaring a boolean to check if the element of a container is less than a specified value

using namespace std;

int main()
{
	list<double> Lst;					//Create a list of doubles

	//Add some data to the list
	Lst.push_back(5.1);					//Add an element (double) 5.1 and push it to back of list
	Lst.push_back(6.32);				//Add an element (double) 6.32 and push it to back of list
	Lst.push_back(5.3);					//Add an element (double) 5.3 and push it to back of list
	Lst.push_back(8.1);					//Add an element (double) 8.1 and push it to back of list
	Lst.push_back(22.6);				//Add an element (double) 22.6 and push it to back of list
	//List = {5.1,6.32,5.3,8.1,22.6}

	//cout << count_if(Lst.begin(), Lst.end(), IsLessThan) << endl;
	//Prints number of elements of list less than 6.2 using global checking function
	//Replace the global checking function, by a function object

	IsLess IL;							//Declaring an IsLess object using default constructor
	cout << "Number of elements in list less than " << IL.Val() << " = " << count_if(Lst.begin(), Lst.end(), IL) << endl;
	//Prints number of elements of list less than 6.2 using object function

	Lst.clear();						//Clear the list

	vector<double> Vec;					//Create a vector of doubles

	//Add some data to the vector
	Vec.push_back(3.16);				//Add an element (double) 3.16 and push it to back of vector
	Vec.push_back(5.13);				//Add an element (double) 5.13 and push it to back of vector
	Vec.push_back(8.23);				//Add an element (double) 8.23 and push it to back of vector
	Vec.push_back(1.16);				//Add an element (double) 1.16 and push it to back of vector
	Vec.push_back(18.31);				//Add an element (double) 18.31 and push it to back of vector
	Vec.push_back(3.24);				//Add an element (double) 3.24 and push it to back of vector
	Vec.push_back(6.34);				//Add an element (double) 6.34 and push it to back of vector
	//Vector = {3.16,5.13,8.23,1.16,18.31,3.24,6.34}

	//cout << count_if(Vec.begin(), Vec.end(), IsLessThan) << endl;
	//Prints number of elements of vector less than 6.2 using global checking function
	//Replace the global checking function, by a function object

	IsLess IL2(5.1);					//Declaring an IsLess object with its value to check against as 5.1
	cout << "Number of elements in vector less than " << IL2.Val() << " = " << count_if(Vec.begin(), Vec.end(), IL2) << endl;
	//Prints number of elements of list less than 6.2 using object function
	cout << "Changing check value from " << IL2.Val();
	//Prints current check value
	IL2.Val(17.5);						//Changing check value from 5.1 to 17.5
	cout << " to " << IL2.Val() << endl;
	//Prints new check value
	cout << "Number of elements in vector less than " << IL2.Val() << " = " << count_if(Vec.begin(), Vec.end(), IL2) << endl;
	//Prints number of elements of list less than 6.2 using object function

	Vec.clear();						//Clear the vector

	return 0;
}

bool IsLessThan(double Ele)		//Defining a boolean to check if the element of a container is less than a specified value
{
	return Ele < 6.2;			//Return elements of container that are less than 6.2
}