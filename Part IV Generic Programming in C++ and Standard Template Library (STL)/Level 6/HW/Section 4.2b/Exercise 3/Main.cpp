//Exercise 4.2.3 asks us to build onto exercise 4.2.2 
//by adding a PointArray Class so we can add points 
//specific functionality to the Array class

#include "Array.hpp"			//Include Array Header File
#include "PointArray.hpp"		//Include PointArray Header File

using namespace std;
using namespace JoseAponte::Containers;
using namespace JoseAponte::CAD;


int main()
{
	int size;											//Declaring a variable for the size of a point array

	cout << "Please enter an array size: ";
	cin >> size;										//Allowing the user to decide

	PointArray PA_1(size);								//Initializing a PointArray with a size decided by the user

	for (int i = 0; i < PA_1.Size(); i++)				//For 0<=i<size
	{
		double x, y;									//Declaring variables for the coordinates of a point
		x = i;											//Initialize x to the corresponding iteration
		y = i;											//Initialize y to the corresponding iteration
		Point p_1(x, y);								//Initialize a point with coordinates equal to the corresponding iteration
		PA_1[i] = p_1;									//Initialize the elements of PA_1 to p_1
	}
	
	cout << "Point Array 1 = ";
	for (int i = 0; i < PA_1.Size(); i++)				//For 0<=i<size
	{
		if (i == 0)										//If i=0
		{
			cout << "{" << PA_1[i] << ",";				//Print {(0,0),
		}
		else if (i == PA_1.Size()-1)					//If i = size-1
		{
			cout << PA_1[i] << "}" << endl;				//Print (size,size)}
		}
		else
		{
			cout << PA_1[i] << ",";						//Otherwise, print (i,i),
		}
	}

	//Testing Length() function of PointArray
	cout << "The length between the points in Point Array 1 = " << PA_1.Length() << endl;

	cout << "Now we'll test the assigment operator and copy constructor" << endl;

	//Testing Copy Constructor
	PointArray PA_1_Copy(PA_1);

	cout << "Point Array 1 Copy = ";
	for (int i = 0; i < PA_1_Copy.Size(); i++)				//For 0<=i<size
	{
		if (i == 0)											//If i=0
		{
			cout << "{" << PA_1_Copy[i] << ",";				//Print {(0,0),
		}
		else if (i == PA_1_Copy.Size() - 1)					//If i = size-1
		{
			cout << PA_1_Copy[i] << "}";					//Print (size,size)}
		}
		else
		{
			cout << PA_1_Copy[i] << ",";					//Otherwise, print (i,i),
		}
	}

	cout << " = Point Array 1" << endl;

	//Testing Assignment Operator
	PointArray PA_2 = PA_1;
	cout << "Point Array 2 = ";
	for (int i = 0; i < PA_2.Size(); i++)				//For 0<=i<size
	{
		if (i == 0)										//If i=0
		{
			cout << "{" << PA_2[i] << ",";				//Print {(0,0),
		}
		else if (i == PA_2.Size() - 1)					//If i = size-1
		{
			cout << PA_2[i] << "}";						//Print (size,size)}
		}
		else
		{
			cout << PA_2[i] << ",";						//Otherwise, print (i,i),
		}
	}
	
	cout << " = Point Array 1" << endl;

	cout << "The length between the points in Point Array 1 Copy = " << PA_1_Copy.Length() << endl;
	cout << "The length between the points in Point Array 2 = " << PA_2.Length() << endl;

	return 0;
}