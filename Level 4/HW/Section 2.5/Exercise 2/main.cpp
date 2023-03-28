// main.cpp
//
// Creating Array of pointers
//
// Author Jose Aponte

#include "Point.hpp"		//Include Point Header File
#include "Line.hpp"			//Include Line Header File
#include "Circle.hpp"		//Include Circle Header File

using namespace std;

int main()
{
	Point** arr_point = new Point * [3];	//Creating an array of Point pointers with 3 elements on the heap.
	
	double x_0, y_0;						//Coordinates for points
	int i;									//Integer i for loop increments

	for (i = 0; i < 3; i++)					//For 0=i<3
		{
			cout << "Please enter an x-coordinate for point " << i+1 << " : ";
			cin >> x_0;								//Initializing ith x-coordinate
			cout << "Please enter an y-coordinate for point " << i+1 << " : ";
			cin >> y_0;								//Initializing ith y-coordinate

			arr_point[i] = new Point(x_0, y_0);		//Creating, for each element in the array, a point on the heap
		}

	for (i = 0; i < 3; i++)					//For 0=i<3
		{
		cout << "Point " << i + 1 << " = " << *arr_point[i] << endl;	//Iterating the array and printing each point in the array
		}

	for (i = 0; i < 3; i++)					//For 0=i<3
		{
			delete arr_point[i];			//Iterating the array again and deleting each point in the array.
		}

	delete [] arr_point;						//Deleting the array itself

	return 0;
}