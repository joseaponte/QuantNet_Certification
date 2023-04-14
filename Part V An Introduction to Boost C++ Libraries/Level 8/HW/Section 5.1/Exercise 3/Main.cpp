//Exercise 5.1.3 asks us to work with variants from the boost library by creating a typedef and various functions
//We also need to create a visitor class

#include "VariantVisitor.hpp"
#include <iostream>

using namespace std;
using namespace JoseAponte::CAD;

//Create a typedef for a ShapeType variant that can contain a Point, Line or Circle
typedef boost::variant<Point, Line, Circle> ShapeType;

//Declaring a function that ask the user what kind of shape to create and returns that
ShapeType Type();

int main()
{
	//In the main program, call the function
	ShapeType ST_1 = Type();

	//And print the result by sending it to cout
	cout << "ShapeType is " << ST_1 << endl;


	//Next try to assign the variant to a Line variable by using the global boost : get<T>() function
	try
	{
		Line L = boost::get<Line>(ST_1);									//If ST_1 is a line, assign ST_1 to L
		cout << "L is type : " << L << endl;								//Print description of L
	}
	catch (boost::bad_get& err)												//Otherwise, (if it's a point or circle)
	{
		cout << "[ERROR]: ATTEMPTING TO ASSIGN A LINE TO AN INCOMPATIBLE OBJECT." << endl;
		//Print "[ERROR]: ATTEMPTING TO ASSIGN A LINE TO AN INCOMPATIBLE OBJECT."
	}

	//In the main program, create an instance of the visitor (Made three to test various constructors)
	VariantVisitor VV_1;													//Creating a Variant Visitor instance using the default constructor
	VariantVisitor VV_2(1.5);												//Creating a Variant Visitor instance using the single parameter constructor
	VariantVisitor VV_3(2.5, 2.5);											//Creating a Variant Visitor instance using the two parameter constructor
	cout << "Prior to modification, ShapeType is: " << ST_1 << endl;
	cout << ST_1 << " offset by " << "(" << VV_1.DX() << "," << VV_1.DX() << ")" << " = ";
	//Use the boost::apply_visitor(visitor, variant) global function to move the shape
	boost::apply_visitor(VV_1, ST_1);
	cout << ST_1 << endl;
	//Print the shape afterwards to check if the visitor indeed changed the coordinates

	cout << ST_1 << " offset by " << "(" << VV_2.DX() << "," << VV_2.DX() << ")" << " = ";
	//Use the boost::apply_visitor(visitor, variant) global function to move the shape
	boost::apply_visitor(VV_2, ST_1);
	cout << ST_1 << endl;
	//Print the shape afterwards to check if the visitor indeed changed the coordinates

	cout << ST_1 << " offset by " << "(" << VV_3.DX() << "," << VV_3.DX() << ")" << " = ";
	//Use the boost::apply_visitor(visitor, variant) global function to move the shape
	boost::apply_visitor(VV_3, ST_1);
	cout << ST_1 << endl;
	//Print the shape afterwards to check if the visitor indeed changed the coordinates
	return 0;
}

//Defining a function that ask the user what kind of shape to create and returns that
ShapeType Type()
{
	ShapeType official_st;									//Declaring a ShapeType to return
	int typ;												//Declaring an integer that will be used to determine the ShapeType to be returned (based on user input)
	cout << "Please enter '1' for a Point type, '2' for a Line type, or a different integer for a Circle type." << endl;
	cin >> typ;												//Allowing user to decide ShapeType
	if (typ == 1)											//If the user inputs 1
	{
		official_st = Point(0);								//Assign the ShapeType to point (0,0)
		return official_st;									//And return it
	}
	else if (typ == 2)										//If the user inputs 2
	{
		official_st = Line(Point(0), Point(1));				//Assign the ShapeType to a line that runs from (0,0) to (1,1)
		return official_st;									//And return it
	}
	else
	{//For all other values that the user may input
		official_st = Circle(Point(0), Line(Point(0), Point(1,0)));	//Assign the ShapeType to a circle with a center at (0,0) and a radius that runs to (1,0) (unit circle)
		return official_st;											//And return it
	}
}