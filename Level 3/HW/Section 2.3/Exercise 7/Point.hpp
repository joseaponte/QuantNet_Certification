/****************************************************
 * Author Jose Aponte                               *
 *                                                  *
 * Definitions for the Point class                  *
 *                                                  *
 * -------------------------------------------------*
 * Class Point                                      *
 *  Member Functions                                *
 *      Point()  -- Default constructor             *
 *      ~Point() -- Destructor                      *
 *      Point(double, double)                       *
 *          Creates a Point with coordinate         *
 *          (x,y)                                   *
 *      X(double)                                   *
 *          Set the value x-point                   *
 *      Y(double)                                   *
 *          Set the vale y-point                    *
 *      X()                                         *
 *          Get the value x-point                   *
 *      Y()                                         *
 *          Get the value y-point                   *
 *      Distance()                                  *
 *          Returns the distance between the        *
 *          point and the origin (0,0)              *
 *      Distance(&Point)                            *
 *          Returns the distance between points     *
 ***************************************************/

#ifndef Point_HPP
#define Point_HPP

#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

class Point
{
private:
    double m_x;
    double m_y;
public:

    //>>>>>>>>>>>>> Default Constructor & Destructor <<<<<
    Point();
    ~Point();

    //>>>>>>>>>>>>> Constructor <<<<<<<<<<<<<<<
    Point(double,double);

    // >>>>>>>>>>>>> Overloading Functions <<<<<<<<<<<<<<<
    // ----- Setters -----
    void X(double);
    void Y(double);

    // ----- Getters -----
    double X() const;
    double Y() const;

    // >>>>>>>>>>>>> Functions <<<<<<<<<<<<<<<
    // Return a string with the x- and y-values
    string ToString() const ;

    // Return the distance between the point and origin
    double Distance() const;

    // Return the distance between point P1 and P2
    double Distance(const Point&);
};

#endif