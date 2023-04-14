#include "Point.hpp"

int main(){
    double x,y;
    cout<< "Introduce x- and y-coordinates" << endl;
    cin >> x >> y;
    Point P;
    P.SetX(x);
    P.SetY(y);
    cout << P.ToString() << endl;
    cout << "X-Coordinate: " << P.GetX() << endl;
    cout << "Y-Coordinate: " << P.GetY() << endl;
    return 0;
}