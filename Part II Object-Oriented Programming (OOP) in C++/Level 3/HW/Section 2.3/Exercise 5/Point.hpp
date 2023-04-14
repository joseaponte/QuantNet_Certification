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
    Point();
    ~Point();

    Point(double,double);

    void X(double);
    void Y(double);

    double X() const;
    double Y() const;

    string ToString() const ;

    double Distance() const;
    double Distance(const Point&);
};

#endif