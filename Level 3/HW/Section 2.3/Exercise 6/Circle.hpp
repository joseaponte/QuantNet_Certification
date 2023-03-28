/****************************************************
 * Author Jose Aponte                               *
 *                                                  *
 * Definitions for the Circle class                 *
 *                                                  *
 * -------------------------------------------------*
 * Class Circle                                     *
 *  Member Functions                                *
 *      Circle()  -- Default constructor            *
 *      ~Circle() -- Destructor                     *
 *      Circle(const Point&, const double)          *
 *          Creates a Circle with center            *
 *          (x,y) and radius m_radius               *
 *      void CenterPoint(Point&)                    *
 *          Calculate the middle point              *
 *          of the radius and the center            *
 *      double Radius()                             *
 *          Returns the radius value                *
 *      double Diameter()                           *
 *          Returns the diameter of the circle      *
 *      double Area()                               *
 *          Returns the area of the circle          *
 *      double Circumference()                      *
 *          Returns the circumference               *
 *          of the circle                           *
 *      string ToString()                           *
 *          Returns a string with the               *
 *          center coordinates and radius           *
 *           of the circle                          *
 ***************************************************/

#ifndef Circle_HPP
#define Circle_HPP
#define _USE_MATH_DEFINES //Pi value from OS

#include<iostream>
#include<sstream>
#include<cmath>
#include "Point.hpp"

using namespace std;

class Circle{
private:
    Point pCenter;
    double m_radius;
public:
    //>>>>>>>>>>>>> Default Constructor & Destructor <<<<<
    Circle();
    ~Circle();

    //>>>>>>>>>>>>> Overloading Constructor <<<<<<<<<<<<<<<
    Circle(const Point&, const double);
    Circle(const double, const double, const double);
  
    //>>>>>>>>>>>>> Functions <<<<<<<<<<<<<<<
    void CenterPoint(Point&);
    double Radius();
    double Diameter();
    double Area();
    double Circumference();
    string ToString() const;
};

#endif