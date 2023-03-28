#include "Point.hpp"

int main(){
    //double x_1,y_1;
    //double x_2,y_2;
    //cout<< "Introduce x- and y-coordinates of P1" << endl;
    //cin >> x_1 >> y_1;
    const Point cp(1.5,3.9);
    //Point P1;
    //Point P2;
    //P1.SetX(x_1);
    //P1.SetY(y_1);
    cout << cp.ToString() << endl;
    cout << "X-Coordinate: " << cp.X() << endl;
    cout << "Y-Coordinate: " << cp.Y() << endl;
    cout << "Distance to Origin: "<< cp.Distance()<< endl;
    //cout<< "Introduce x- and y-coordinates of P2" << endl;
   // cin >> x_2 >> y_2;
    //P2.SetX(x_2);
    //P2.SetY(y_2);
    //cout << P2.ToString() << endl;
    //cout << "Distance between Points d: " << P1.Distance(P2)<< endl;
    return 0;
}