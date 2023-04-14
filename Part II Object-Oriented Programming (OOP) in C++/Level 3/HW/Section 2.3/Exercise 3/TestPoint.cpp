#include "Point.hpp"

int main(){
    double x_1,y_1;
    //double x_2,y_2;
    cout<< "Introduce x- and y-coordinates of P1" << endl;
    cin >> x_1 >> y_1;
    Point P1(x_1,y_1);
    //Point P1;
    //Point P2;
    //P1.SetX(x_1);
    //P1.SetY(y_1);
    cout << P1.ToString() << endl;
    cout << "X-Coordinate: " << P1.X() << endl;
    cout << "Y-Coordinate: " << P1.Y() << endl;
    cout << "Distance to Origin: "<< P1.Distance()<< endl;
    //cout<< "Introduce x- and y-coordinates of P2" << endl;
   // cin >> x_2 >> y_2;
    //P2.SetX(x_2);
    //P2.SetY(y_2);
    //cout << P2.ToString() << endl;
    //cout << "Distance between Points d: " << P1.Distance(P2)<< endl;
    return 0;
}