//Exercise 4.2.2 asks us to build onto exercise 4.2.1.b by 
//adding a NumericArray class, using generic inheritance, 
// so types that support numeric operations can be used

#include "Circle.hpp"			//Include Circle Header File
#include "Array.hpp"			//Include Array Header File
#include "NumericArray.hpp"		//Include NumericArray Header File

using namespace std;
using namespace JoseAponte::Containers;


int main()
{
	int size;									//Size Parameter for numeric arrays

	cout << "Please enter a size for the numeric arrays: ";
	cin >> size;								//Allowing user to decide size of the array

	NumericArray<double> NA_1(size);			//Testing Numeric Array for type int of assigned size
	NumericArray<double> NA_2(size);			//Testing functionality with another array of same size and type of parameter
	NumericArray<double> NA_3(size + 1);		//Testing functionality with another array of a different size but same type of parameter

	cout << "Size of numeric array 1 = " << NA_1.Size() << endl;	//Print size of numeric array 1
	cout << "Size of numeric array 2 = " << NA_2.Size() << endl;	//Print size of numeric array 2
	cout << "Size of numeric array 3 = " << NA_3.Size() << endl;	//Print size of numeric array 3

	for (int i = 0; i < size; i++)			//For 0<=i<size
	{
		NA_1[i] = i;							//Set each element of numeric array 1 to the its corresponding index
		NA_2[i] = i;							//Set each element of numeric array 2 to the its corresponding index
	}
	for (int i = 0; i < NA_3.Size(); i++)	//For 0<=i<size+1
	{
		NA_3[i] = i;							//Set each element of numeric array 3 to the its corresponding index
	}
	
	double factor;								//Declaring a factor to test * operator
	
	cout << "Please enter a factor to multiply the first array's elements by: ";
	cin >> factor;								//Allowing user to decide such factor

	NumericArray<double> NA_4 = NA_1.operator*(factor);				//Inializing a factored version of NA_1

	cout << "Numeric Array 1 * " << factor << " = ";				//Print the new numeric array in the form "Numeric Array = {0, ... , (size-1)*factor}
	for (int i = 0; i < size; i++)
	{
		if (i == 0)													//For the first element
		{
			cout << "{" << NA_4[i] << ",";							//Print {0,
		}
		else if (i == NA_4.Size() - 1)								//For the last element
		{
			cout << NA_4[i] << "}" << endl;							//Print (size-1)*factor}
		}
		else
		{
			cout << NA_4[i] << ",";									//Otherwise print ..., i * factor, ...
		}
	}

	//Now, test NA_1's compatability w/ NA_2
	//Everything should work because of the same size parameters
	try
	{
		NumericArray<double> NA_5(size);			//NA_5 will be used to test + operator with alike size and type
		NA_5 = NA_1.operator+(NA_2);
		cout << "Numeric Array 1 + Numeric Array 2 = ";
		for (int i = 0; i < size; i++)			//For 0<=i<size
		{
			if (i == 0)													//For the first element
			{
				cout << "{" << NA_5[i] << ",";							//Print {0,
			}
			else if (i == NA_5.Size() - 1)										//For the last element
			{
				cout << NA_5[i] << "}" << endl;							//Print some scalar from the addition of the NA's
			}
			else
			{
				cout << NA_5[i] << ",";									//Print some scalar from the addition of the NA's
			}
		}
	}
	catch (NA_Exception& error)											//Catch size issues and print statement from GetMessage()
	{
		cout << error.GetMessage() << endl;
	}
	catch (...)															//All other catches will be caught and display "Unknown error"
	{
		cout << "Unknow error" << endl;
	}

	//Now, test NA_1's compatability w/ NA_3
	//Shouldn't work because of size difference

	try
	{
		NumericArray<double> NA_6(size);			//NA_6 will be used to test + operator with alike type but different size
		NA_6 = NA_1.operator+(NA_3);
		cout << "Numeric Array 1 + Numeric Array 3 = ";
		for (int i = 0; i < size; i++)				//Again, none of this should work, but hypothetically:
		{
			if (i == 0)													//For the first element
			{
				cout << "{" << NA_6[i] << ",";							//Print {0,
			}
			else if (i == NA_6.Size() - 1)										//For the last element
			{
				cout << NA_6[i] << "}" << endl;							//Print some scalar from the addition of the NA's
			}
			else
			{
				cout << NA_6[i] << ",";									//Otherwise, print some scalar from the addition of the NA's
			}
		}
	}
	catch (NA_Exception& err)											//If an NA_Exception error is caucght
	{
		cout << err.GetMessage() << endl;								//Use GetMessage() funciton, which notifies user of unalike sizes
	}
	catch (...)															//Otherwise
	{
		cout << "Unknow error" << endl;									//Print unknown error
	}
	
	//Now testing DotProduct() function w/ alike sizes
	//Since the sizes are equal, this should work
	try
	{
		cout << "(NA_1)^T(NA_2) = " << NA_1.DotProduct(NA_2) << endl;	//Trying to print result from dot product
	}
	catch (NA_Exception& errr)											//If an NA_Exception error is caucght
	{
		cout << errr.GetMessage() << endl;								//Use GetMessage() funciton
	}
	catch (...)															//Otherwise
	{
		cout << "Unknow error" << endl;									//Print unknown error
	}

	//Now testing DotProduct() function w/ unlike sizes
	//Should trip an error due to unlike sizes
	try
	{
		cout << "(NA_1)^T(NA_3) = " << NA_1.DotProduct(NA_3) << endl;	//Trying to print result from dot product
	}
	catch (NA_Exception& errr)											//If an NA_Exception error is caucght
	{
		cout << errr.GetMessage() << endl;								//Use GetMessage() funciton
	}
	catch (...)															//Otherwise
	{
		cout << "Unknow error" << endl;									//Print unknown error
	}

	//Testing Copy Constructor
	NumericArray<double> NA1_Copy(NA_1);

	cout << "Numeric Array 1 Copy = ";
	for (int i = 0; i < NA1_Copy.Size(); i++)						//For the size of the copy numeric array
	{
		if (i == 0)													//For the first element
		{
			cout << "{" << NA1_Copy[i] << ",";						//Print {0,
		}
		else if (i == NA1_Copy.Size() - 1)							//For the last element
		{
			cout << NA1_Copy[i] << "}";								//Print the last element of NA1_copy
		}
		else
		{
			cout << NA1_Copy[i] << ",";								//Print some other element of NA1_copy
		}
	}
	cout << " = Numeric Array 1." << endl;

	cout << "Now assigning the elements and size of Numeric Array 1 to Numeric Array 3." << endl;
	//Testing Assignment Operator
	NA_3 = NA_1;

	cout << "Numeric Array 3 = ";
	for (int i = 0; i < NA_3.Size(); i++)
	{
		if (i == 0)													//For the first element
		{
			cout << "{" << NA_3[i] << ",";							//Print {0,
		}
		else if (i == NA_3.Size() - 1)								//For the last element
		{
			cout << NA_3[i] << "}";									//Print the last element of NA_1
		}
		else
		{
			cout << NA_3[i] << ",";									//Otherwise print some middle element of NA_1
		}
	}
	cout << " = Numeric Array 1." << endl;

	return 0;
}