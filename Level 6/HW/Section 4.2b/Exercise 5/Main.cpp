//Exercise 4.2.5 asks us to build onto exercise 4.2.4 by 
//adding a StackException Base Class with StackFullException 
//and StackEmptyException derived classes so that the internal 
//use of array is unknown to user

#include "Array.hpp"			//Include Array Header File
#include "PointArray.hpp"		//Include PointArray Header File
#include "Stack.hpp"			//Include Stack Header File

using namespace std;
using namespace JoseAponte::Containers;
using namespace JoseAponte::CAD;


int main()
{
	Stack<double> stk_1(5);					//Declaring a stack with size 5

	cout << "Constructor with size parameter: (Push)" << endl;
	for (int i = 0; i < 6; i++)				//Testing getters and push first, makes testing class in main easier. Also, should trip StackException(Full) on last iteration
		try
	{
		stk_1.Push(i + .3);					//Testing push function
		cout << "Element " << stk_1.Current() -1 << " = " << stk_1.Element() << endl;
	}
	catch (StackException& error)			//Make sure the current index is not changed when there's an exception.
	{
		cout << error.S_GetMessage() << endl;
	}
	catch (...)
	{
		cout << "Unknown error." << endl;	//Other catches will print unknown error
	}
	//Successfully only increments m_current if no excpetion

	Stack<double> stk_2(stk_1);				//Copy stack 1 to stack 2 to test copy constructor
	Stack<double> stk_3;					//Declaring a third stack w/ default constructor
	stk_3.operator=(stk_2);					//Assign stk_1 to stk_3

	cout << "Constructor with size parameter: (Pop)" << endl;
	for (int i = 0; i < 6; i++)				//Now testing pop. Also, should trip StackException(Empty) on last iteration
		try
	{
		cout << "Element " << stk_1.Current() << " = " << stk_1.Pop() << endl;		//Testing Pop() function
	}
	catch (StackException& err)
	{
		cout << err.S_GetMessage() << endl;	//Make sure the current index is not changed when there's an exception.
	}
	catch (...)
	{
		cout << "Unknown error." << endl;	//Other catches will print unknown error
	}
	//Successfully only increments m_current if no excpetion

	//Now testing copy constructor
	cout << "Copy Constructor: (Pop)" << endl;

	for (int i = 0; i < 6; i++)				//Testing push on copy of stack 1. Again, should trip StackException(Empty) on last iteration
		try
	{
		cout << "Element " << stk_2.Current() << " = " << stk_2.Pop() << endl;			//Testing pop function w/ copied stack
	}
	catch (StackException& errr)			//Make sure the current index is not changed when there's an exception.
	{
		cout << errr.S_GetMessage() << endl;
	}
	catch (...)
	{
		cout << "Unknown error." << endl;	//Other catches will print unknown error
	}
	//Successfully only increments m_current if no excpetion

	//Now testing the assignment Operator
	cout << "Assignment Operator: (Pop)" << endl;
	for (int i = 0; i < 6; i++)				//Testing getters and push compatability with assigned stack. Again, should trip StackException(Empty) on last iteration
		try
	{
		cout << "Element " << stk_3.Current() << " = " << stk_3.Pop() << endl;		//Testing pop function w/ Assigned Stack
;
	}
	catch (StackException& err)			//Make sure the current index is not changed when the Array class threw an exception.
	{
		cout << err.S_GetMessage() << endl;
	}
	catch (...)
	{
		cout << "Unknown error." << endl;	//Other catches will print unknown error
	}
	//Successfully only increments m_current if no excpetion

	return 0;
}