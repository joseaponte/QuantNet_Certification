// Point.hpp
//
// Header file for Points in two dimensions. A given Point has 3 coordinates
// for compatibility with other systems. However, it is not possible to
// influence the third coordinate and furthermore, the delivered functionality
// is typically two-dimensional.
//
//  Author Jose Aponte


#ifndef Point_HPP
#define Point_HPP

#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

class Point
{
private:
    double m_x;                     // x-coordinate
    double m_y;                     // y-coordinate
public:

/*----- Constructors -----*/
    Point();                        // Default constructor
    Point(double,double);           // Initialize point with x- and y-value
    ~Point();                       // Destructor

    Point(const Point&);            // Copy constructor

/*----- Accessing Functions -----*/
    void X(double);              // Set point with x-value
    void Y(double);              // Set point with y-value

    double X() const;            // Get point's x-value
    double Y() const;            // Get point's y-value

    string ToString();              // 

    double DistanceOrigin();
    double Distance(const Point&) const;

/*----- Operator Functions -----*/
    Point operator-() const;                 // Negate the coordinates
    Point operator*(double) const;           // Scale the coordinates
    Point operator+(const Point&) const;     // Add coordinates
    bool operator==(const Point&) const;     // Equally compare operator
    Point& operator= (const Point&);         // Assignment operator
    Point& operator*=(double);               // Scale the coordinates & assign
};

#endif