//Exercise 5.1.1 asks us to build onto exercise 4.2.6 by testing an array of shared pointers from the boost library (these are smart pointers that get deleted automatically)
//The following steps must be taken: Create a program that creates an array with shared pointers for shapes, fill it with various shapes, print them, and check if the shapes are automatically deleted

#include "Array.hpp"				//Include Array Header File
#include "Circle.hpp"				//Include Circle Header File
#include <boost/shared_ptr.hpp>		//Include boost shared pointer Header File

using namespace std;
using namespace JoseAponte::Containers;
using namespace JoseAponte::CAD;

// Typedef for a shared pointer to shape and 
// a typedef for an array with shapes stored as shared pointers.
typedef boost::shared_ptr<Shape> ShapePtr;
typedef Array<ShapePtr> ShapeArray;

int main()
{
	{	//Using internal brackets to check if the ptrs get deleted automatically (should occur after ending internal bracket)
		ShapePtr point_sp1(new Point(2, 3));								//Declaring a shape pointer to point(2,3)
		ShapePtr point_sp2(new Point(4, 5));								//Declaring a shape pointer to point(4,5)
		ShapePtr line_sp(new Line(Point(2), Point(4)));						//Declaring a shape pointer to line((2,2)->(4,4))
		ShapePtr circle_sp(new Circle(Point(2), Line(Point(2), (4))));		//Declaring a shape pointer to circle((2,2),line((2,2)->(4,4)))

		ShapeArray arr_sp(12);						//Create an array with shared pointers for shapes

		//Fill it with various shapes
		arr_sp[0] = point_sp1;						//Set first element to point_sp1
		arr_sp[1] = point_sp2;						//Set second element to point_sp2
		arr_sp[2] = line_sp;						//Set third element to line_sp
		arr_sp[3] = circle_sp;						//Set fourth element to circle_sp
		arr_sp[4] = point_sp1;						//Set fifth element to point_sp1
		arr_sp[5] = point_sp2;						//Set sixth element to point_sp2
		arr_sp[6] = line_sp;						//Set seventh element to line_sp
		arr_sp[7] = circle_sp;						//Set eigth element to circle_sp
		arr_sp[8] = point_sp1;						//Set ninth element to point_sp1
		arr_sp[9] = point_sp2;						//Set tenth element to point_sp2
		arr_sp[10] = line_sp;						//Set eleventh element to line_sp
		arr_sp[11] = circle_sp;						//Set last element to circle_sp


		try
		{
			for (int i = 0; i != arr_sp.Size(); i++)	//For 0<=i<(size=12)
			{
				(*arr_sp[i]).Print();					//Print the shapes
			}
		}
		catch (ArrayException& err)						//Making sure only indeces that are in bounds are accessed
		{
			cout << err.GetMessage() << endl;			//Prints "The given index is out of bounds." if array exception is caught
		}
		catch (...)
		{
			cout << "Unknown error." << endl;			//Other catches will be dealt with by printing "Unknown error."
		}
		//Printing use count before auto deletion for all of the shape/shared_pointers
		cout << "Use count of point shape pointer 1 before deletion = " << point_sp1.use_count() << endl;
		cout << "Use count of point shape pointer 2 before deletion = " << point_sp2.use_count() << endl;
		cout << "Use count of line shape pointer before deletion = " << line_sp.use_count() << endl;
		cout << "Use count of circle shape pointer before deletion = " << circle_sp.use_count() << endl;
	}

	//Cannot perform any of the following code because the shape/shared_pointers were automatically deleted after the internal end bracket
	//Since they were initialized internally in that bracket
	//This verifies that shared pointers were automatically deleted
	//cout << "Use count of point shape pointer 1 after deletion = " << point_sp1.use_count() << endl;
	//cout << "Use count of point shape pointer 2 after deletion = " << point_sp2.use_count() << endl;
	//cout << "Use count of line shape pointer after deletion = " << line_sp.use_count() << endl;
	//cout << "Use count of circle shape pointer after deletion = " << circle_sp.use_count() << endl;

	//Also, working through the program in debgger mode shows that the shared pointers are deleted after the internal end bracket line is executed
	//The destructor calls show the shared pointers were deleted automatically too

	return 0;

}