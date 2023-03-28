// main.cpp
//
// Creating Array Class
//
// Author Jose Aponte

#include "Point.hpp"		//Include Point Header File
#include "Line.hpp"			//Include Line Header File
#include "Circle.hpp"		//Include Circle Header File
#include "Array.hpp"		//Include Array Header File

using namespace std;

int main()
{
	Array arr_0;			//arr_0 will be used to test the default constructor
	double x_0, y_0;		//Declaring coordinates for p_0
	int i;					//Declaring i for iterations of the loop

	//Testing default constructor
	for (i = 0; i < 10; i++)					//For i <= 0 < 10
	{
		if (i == 0)								//If i = 0
		{
			x_0 = i;							//Set x = 0
			y_0 = i;							//Set y = 0
			Point p_0(x_0, y_0);				//For simplicity, p_0 will be assigned the corresponding index number for its coordinates
			arr_0[i] = p_0;						//Set 1st element to p_0
			cout << "Default Constructor Test: " << "{" << arr_0[i] << ",";
			//Output Default Constructor Test: {(0,0),
		}
		else if (i == 9)						//If i = 9
		{
			x_0 = i;							//Set x = 9
			y_0 = i;							//Set y = 9
			Point p_0(x_0, y_0);				//For simplicity, p_0 will be assigned the corresponding index number for its coordinates
			arr_0[i] = p_0;						//Set 9th element to p_0
			cout << arr_0[i] << "}\n";			//Output (9,9)}
		}
		else
		{
			x_0 = i;							//Otherwise, set x = i
			y_0 = i;							//Set y = i
			Point p_0(x_0, y_0);				//For simplicity, p_0 will be assigned the corresponding index number for its coordinates
			arr_0[i] = p_0;						//Set ith element to p_0
			cout << arr_0[i] << ",";			//Output (i,i),
		}
	}

	//Testing Copy Constructor
	Array arr_1(arr_0);
	for (i = 0; i < 10; i++)					//For i <= 0 < 10
	{
		if (i == 0)								//If i = 0
		{
			cout << "Copy Constructor Test: " << "{" << arr_1[i] << ",";
			//Output Copy Constructor Test: {(0,0),
		}
		else if (i == 9)						//If i = 9
		{
			cout << arr_1[i] << "}\n";			//Output (9,9)}
		}
		else
		{
			cout << arr_1[i] << ",";			//Output (i,i),
		}
	}

	int arr_size;				//Declaring arr_size integer

	cout << "Please enter a size for an array of points: ";
	cin >> arr_size;			//Allowing user to determine size of array

	Array arr_2(arr_size);
	//Testing constructor with size argument
	for (i = 0; i < arr_size; i++)	//For i <= 0 < arr_size
	{
		if (i == 0)								//If i = 0
		{
			x_0 = i;							//Set x = 0
			y_0 = i;							//Set y = 0
			Point p_1(x_0, y_0);				//For simplicity, p_1 will be assigned the corresponding index number for its coordinates
			arr_2[i] = p_1;						//Set 1st element to p_1
			cout << "Constructor w/ Size Argument Test: " << "{" << arr_2[i] << ",";
			//Output Constructor w/ Size Argument Test: {(0,0),
		}
		else if (i == arr_size - 1)				//If i = arr_size
		{
			x_0 = i;							//Set x = arr_size
			y_0 = i;							//Set y = arr_size
			Point p_1(x_0, y_0);				//For simplicity, p_1 will be assigned the corresponding index number for its coordinates
			arr_2[i] = p_1;						//Set 9th element to p_1
			cout << arr_2[i] << "}\n";			//Output (arr_size, arr_size)}
		}
		else
		{
			x_0 = i;							//Otherwise, set x = i
			y_0 = i;							//Set y = i
			Point p_1(x_0, y_0);				//For simplicity, p_1 will be assigned the corresponding index number for its coordinates
			arr_2[i] = p_1;						//Set ith element to p_1
			cout << arr_2[i] << ",";			//Output (i,i)
		}
	}

	//Testing functions from Array Class
	cout << "Now, let's test the functions from the Array class." << endl;

	//Testing the Size function
	cout << "Using the Size function, we can see the size of the array from the default constructor is " << arr_0.Size() << "." << endl;

	//Testing the SetElement function
	cout << "Now we'll test the SetElement function." << endl;
	int index;									//Declaring index integer
	cout << "Please select a number between 0 and 9 to alter the corresponding point in the array: ";
	//Allowing user to initialize index so they can decide which element gets altered
	cin >> index;

	cout << "Enter an x-coordinate: ";
	cin >> x_0;									//Allowing user to decide new x-coordinate
	cout << "Enter a y-coordinate: ";
	cin >> y_0;									//Allowing user to decide new y-coordinate
	Point p_2(x_0, y_0);						//Setting a point to those new coordinates
	
	arr_0.SetElement(index, p_2);				//Setting element (index) to p_2

	if (index > 0 && index < 10)				//If index is in bounds
	{
		cout << "Element " << index + 1 << " = " << arr_0[index] << endl;
		//Output the corresponding element after it's been altered
	}

	//Testing the GetElement function
	cout << "Now we'll test the GetElement function." << endl;

	int get_num;			//Declaring an integer to decide which point in the array to fetch

	cout << "Please select a number between 0 and 9 to fetch the corresponding point in the array: ";
	cin >> get_num;			//Allowing user to decide point in array to fetch
	if (index > 0 && index < 10)				//If index is in bounds
	{
		cout << "Using the GetElement function, we can see element " << get_num + 1 << " = " << arr_0.GetElement(get_num) << endl;
		//Outputs the corresponding element in original array
	}
	else
	{
		cout << "Out of bounds" << endl;
	}

	//Testing operators
	cout << "Now, let's test the operators of the Array class." << endl;

	//Testing operator =
	Array arr_3 = arr_0;
	cout << "Using the = operator, a new array was created." << endl;
	for (i = 0; i < 10; i++)					//For i <= 0 < 10
	{
		if (i == 0)								//If i = 0
		{
			cout << "New array = {" << arr_3[i] << ",";
			//Output New array = {(0,0),
		}
		else if (i == 9)						//If i = 9
		{
			cout << arr_3[i] << "}\n";			//Output (9,9)}
		}
		else
		{
			cout << arr_3[i] << ",";			//Output (i,i)}
		}
	}
	
	//The square bracket operator has already been tested several times
	//Just need to test the const version of it now
	cout << "The square bracket operator has already been tested several times throughout this program." << endl;
	cout << "Let's test the const version." << endl;
	
	cout << "Enter another x-coordinate: ";
	cin >> x_0;
	cout << "Enter another y-coordinate: ";
	cin >> y_0;
	const Point	cp(x_0, y_0);

	arr_0[0] = cp;				//Assigning first element of first array, a const point
	cout << "A new const point was created." << endl;
	cout << "The first element of the first array was assigned this point." << endl;

	for (i = 0; i < 10; i++)					//For i <= 0 < 10
	{
		if (i == 0)								//If i = 0
		{
			cout << "Array 1 = {" << arr_0[i] << ",";
			//Output Default Constructor Test: {(_,_),
		}
		else if (i == 9)						//If i = 9
		{
			cout << arr_0[i] << "}\n";			//Output (9,9)}, unless altered by user earlier
		}
		else
		{
			cout << arr_0[i] << ",";			//Output (i,i), unless altered by user earlier
		}
	}
	
	cout << "Finally, let's test a const Array." << endl;
	const Array arr_4(arr_size);				//Declaring a const array
	//For simplicity, we'll just allow all of the points to equal (0,0)
	for  (i = 0; i < arr_size; i++)
	{
		if (i == 0)								//If i = 0
		{
			cout << "Const Array = " << "{" << arr_4[i] << ",";
			//Output Copy Constructor Test: {(0,0),
		}
		else if (i == arr_size-1)				//If i = arr_size
		{
			cout << arr_4[i] << "}\n";			//Output (0,0)}
		}
		else
		{
			cout << arr_4[i] << ",";			//Output (0,0),
		}
	}
	return 0;
}