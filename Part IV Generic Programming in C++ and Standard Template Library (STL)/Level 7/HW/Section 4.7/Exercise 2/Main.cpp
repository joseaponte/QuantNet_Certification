//Exercise 4.7.2 asks us to practice with STL iterators and 
//to create various (4) forms of a Sum() function

#include "Sum.hpp"

double Sum(const map<string, double>::const_iterator& start_4, const map<string, double>::const_iterator& end_4);
//Declaring a Sum() function for the sum of elements of map between iterators

using namespace std;

int main()
{
	list<double> Lst;				//Create a list of doubles

	//Add some data to the list
	Lst.push_back(5.1);					//Add an element (double) 5.1 and push it to back of list
	Lst.push_back(6.32);				//Add an element (double) 6.32 and push it to back of list
	Lst.push_back(5.3);					//Add an element (double) 5.3 and push it to back of list
	Lst.push_back(8.1);					//Add an element (double) 8.1 and push it to back of list
	Lst.push_back(22.6);				//Add an element (double) 22.6 and push it to back of list
	//List = {5.1,6.32,5.3,8.1,22.6}

	cout << "Complete sum of list = " << Sum(Lst) << endl;			//Print full sum of list
	list<double>::const_iterator strt = ++Lst.begin();				//Iterator after first element of list (6.32)
	list<double>::const_iterator nd = --Lst.end();					//Iterator at last element of list (22.6)
	cout << "Sum of list between first and last elements = " << Sum(strt, nd) << endl;
	//Print sum between first and last element

	Lst.clear();					//Clear the list

	vector<double> Vec;				//Create a vector of doubles

	//Add some data to the vector
	Vec.push_back(3.16);				//Add an element (double) 3.16 and push it to back of vector
	Vec.push_back(5.13);				//Add an element (double) 5.13 and push it to back of vector
	Vec.push_back(8.23);				//Add an element (double) 8.23 and push it to back of vector
	Vec.push_back(1.16);				//Add an element (double) 1.16 and push it to back of vector
	Vec.push_back(18.31);				//Add an element (double) 18.31 and push it to back of vector
	Vec.push_back(3.24);				//Add an element (double) 3.24 and push it to back of vector
	Vec.push_back(6.34);				//Add an element (double) 6.34 and push it to back of vector
	//Vector = {3.16,5.13,8.23,1.16,18.31,3.24,6.34}

	cout << "Complete sum of vector = " << Sum(Vec) << endl;			//Print full sum of vector

	vector<double>::const_iterator strt_0 = ++Vec.begin();				//Iterator after first element of vector (5.13)
	vector<double>::const_iterator nd_0 = --Vec.end();					//Iterator at last element of vector (6.34)
	cout << "Sum of vector between first and last elements = " << Sum(strt_0, nd_0) << endl;
	//Print sum between first and last element

	Vec.clear();									//Clear the vector

	map<string, double> Players;					//Create a map that maps strings to doubles

	//Fill the map with data
	Players["Player1"] = 1.23;						//Map string "First" to 1.23
	Players["Player2"] = 3.13;						//Map string "Second" to 3.13
	Players["Player3"] = 8.51;						//Map string "Third" to 8.51
	Players["Player4"] = 6.24;						//Map string "Fourth" to 6.24

	cout << "Complete sum of map = " << Sum(Players) << endl;						//Print full sum of mapped strings
	map<string, double>::const_iterator strt_1 = ++Players.begin();					//Iterator after first element of map (3.13)
	map<string, double>::const_iterator nd_1 = --Players.end();						//Iterator at last element of map (6.24)
	cout << "Sum of map between first and last elements = " << Sum(strt_1, nd_1) << endl;
	//Print sum between first and last element

	//Note elements of the map are ordered in terms of lexicographic order
	//This wouldn't change the total sum result, but could change the sum between iterators result based on the lexicographic ordering of the strings
	//In this case, the strings were selected to purposely have the ordering be: "Player1","Player2","Player3","Player4" to have a consistent result with that of the list and vector

	Players.clear();							//Clear the map

	return 0;
}

//Defining a Sum() function for the sum of elements of map between iterators
double Sum(const map<string, double>::const_iterator& start_4, const map<string, double>::const_iterator& end_4)
{
	double sum_4 = 0;									//Initialize double for the sum to 0
	map<string, double>::const_iterator it_4;			//An iterator for the loop
	for (it_4 = start_4; it_4 != end_4; ++it_4)			//Create a loop that iterates the maps and adds appropriate values
	{
		sum_4 += (*it_4).second;						//Add each element to sum for each iteration of loop using derefereced iterator
	}
	return sum_4;										//Finally return the sum.
}	//Calculates a portion of the sum based on the iterators