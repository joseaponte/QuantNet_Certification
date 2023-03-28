#ifndef Point_HPP
#define Point_HPP

#include <iostream>
#include <sstream>

using namespace std;

class Point
{
private:
    double m_x;
    double m_y;
public:
    Point();
    ~Point();

    void SetX(double);
    void SetY(double);

    double GetX() const;
    double GetY() const;

    string ToString();
};

#endif