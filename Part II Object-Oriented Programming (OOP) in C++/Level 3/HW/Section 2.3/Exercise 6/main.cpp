/****************************************************
 * Author Jose Aponte                               *
 *                                                  *
 * Test for the Circle Class                        *
 *                                                  *
 ***************************************************/

#include "Circle.hpp"

int main(){
    Circle CircleTest;      // Creates a default constructor
    double xCoordinate, yCoordinate, radiusTest;

    /********** Default Constructor **********/   
    cout << "Default Constructor " << CircleTest.ToString()<<endl;

    cout << "Introduce Point x- and y- coordinate and radius" << endl;
    cin >> xCoordinate >> yCoordinate >> radiusTest;

    /********** Overloading Constructor **********/   
    Circle CircleTest1(xCoordinate, yCoordinate, radiusTest);

    /********** Printing values **********/   
    cout << "Constructor " << CircleTest1.ToString() << endl;
    cout << "Radius = " << CircleTest1.Radius()<< endl;
    cout << "Diameter = " << CircleTest1.Diameter() << endl;
    cout << "Area = " << CircleTest1.Area() << endl;
    cout << "Circumference " << CircleTest1.Circumference() << endl;
    return 0;
}