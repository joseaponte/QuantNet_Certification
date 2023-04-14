#ifndef Line_HPP
#define Line_HPP

#include <iostream>
#include "Point.hpp"
using namespace std;

class Line{
private:
    Point startPoint;
    Point endPoint;
public:
    Line();
    Line(const Point&, const Point&);

    Line(const Line&);

    ~Line();

    void P1(const Point&);
    void P2(const Point&);

    Point P1() const;
    Point P2() const;

    string ToString() const;

    double Length();
};

#endif
