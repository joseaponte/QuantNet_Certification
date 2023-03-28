//Exercise 4.7.1 asks us to practice with the different STL containers (namely a list, a vector, and a map)

#include <iostream>
#include <list>
#include <vector>
#include <map>

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

	cout << "First element of list = " << Lst.front() << endl;		//Use the front() function to access the first element
	cout << "Last element of list = " << Lst.back() << endl;		//Use the back() function to access the last element

	Lst.clear();					//Clear the list

	vector<double> Vec;				//Create a vector of doubles

	//Vec.reserve(10);				//Forum says to "skip" this

	//Add some data to the vector
	Vec.push_back(3.16);				//Add an element (double) 3.16 and push it to back of vector
	Vec.push_back(5.13);				//Add an element (double) 5.13 and push it to back of vector
	Vec.push_back(8.23);				//Add an element (double) 8.23 and push it to back of vector
	Vec.push_back(1.16);				//Add an element (double) 1.16 and push it to back of vector
	Vec.push_back(18.31);				//Add an element (double) 18.31 and push it to back of vector


	//Vector = {3.16,5.13,8.23,1.16,18.31}
	
	//Use the index operator to access some elements

	cout << "Vector element 1 = " << Vec[0] << endl;	//Access and print first element
	cout << "Vector element 3 = " << Vec[2] << endl;	//Access and print third element
	cout << "Vector element 5 = " << Vec[4] << endl;	//Access and print fifth element

	cout << "Vector size = " << Vec.size() << endl;				//Size before growing vector
	cout << "Vector capacity = " << Vec.capacity() << endl;		//Capacity before growing vector

	cout << "Now making the vector grow." << endl;

	Vec.push_back(3.24);				//Add an element (double) 3.24 and push it to back of vector
	Vec.push_back(6.34);				//Add an element (double) 6.34 and push it to back of vector

	cout << "Grown vector size = " << Vec.size() << endl;					//Prints new size
	cout << "Grown vector capacity = " << Vec.capacity() << endl;			//Prints new capacity

	//Both size (5 to 7) and capacity (6 to 9) increased when pushing back more elements
	//Vector = {3.16,5.13,8.23,1.16,18.31,3.24,6.34}

	Vec.clear();								//Clear the vector

	map<string, double> Players;				//Create a map that maps strings to doubles

	//Fill the map with data
	Players["Player1"] = 1.23;						//Map string "Player1" to 1.23
	Players["Player2"] = 3.13;						//Map string "Player2" to 3.13
	Players["Player3"] = 8.51;						//Map string "Player3" to 8.51
	Players["Player4"] = 6.24;						//Map string "Player4" to 6.24

	//Access elements using the square bracket operator
	cout << "Player1 -> " << Players["Player1"] << endl;		//Printing descriptions using square bracket operator
	cout << "Player2 -> " << Players["Player2"] << endl;		//Printing descriptions using square bracket operator
	cout << "Player3 -> " << Players["Player3"] << endl;		//Printing descriptions using square bracket operator
	cout << "Player4 -> " << Players["Player4"] << endl;		//Printing descriptions using square bracket operator

	Players.clear();						//Clear the map

	return 0;
}