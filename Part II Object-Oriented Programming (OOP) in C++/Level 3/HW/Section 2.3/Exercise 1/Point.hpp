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

    void SetX(double);
    void SetY(double);

    double GetX() const;
    double GetY() const;

    string ToString();

    double DistanceOrigin();
    double Distance(const Point&);
};

#endif