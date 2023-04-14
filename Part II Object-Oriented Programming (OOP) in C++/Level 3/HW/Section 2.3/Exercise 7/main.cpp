/****************************************************
 * Autor Jose Aponte                                *
 *                                                  * 
 * Inline Functions                                 *                                 
 *                                                  *
 * -------------------------------------------------*
 *                                                  *
 * Make Setter and Getter of the Point Class as     *
 * inline functions. Getter as a normal inline      *
 * and Setter as a default line.                    *
 *                                                  *
****************************************************/

#include "Point.hpp"
#include <iostream>

//>>>>>>>>>>>>> Normal Inline Functions <<<<<<<<<<<<<<<
inline double GetX(Point& P){
    return (P.X());
}

inline double GetY(Point& P){
    return (P.Y());
}

int main(){
    Point pTest;
    double xCoordinate, yCoordinate;


    cout << "Default Constructor: " << pTest.ToString() << endl;

    cout << "Introduce new x- and y- coordinates " << endl;
    cin >> xCoordinate >> yCoordinate;

    pTest.X(xCoordinate);
    pTest.Y(yCoordinate);

    cout << "Values are: " << pTest.ToString() << endl;
    cout << "x- Coordinate is: " << GetX(pTest) << endl;
    cout << "y- Coordinate is: " << GetY(pTest) << endl;
    return 0;
}