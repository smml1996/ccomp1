#include <iostream>
#include "arrPoints.h"

using namespace std;


int main(){
    Point p(1,2);
    Point p1(7,7);
    Point p2(8,8);
    Point points[3] = {p,p1,p2};
    /*cout<<"punto 1: "; p.printPoint(); cout<<endl;
    cout<<"punto 2 (con constructor copia)"; points[0].printPoint();cout<<endl;
    cout<<"punto 3 con constructor vacio";p2.printPoint(); cout<<endl;
    cout<<"cooderndas x e y con get() "<<p.getX()<<" "<<p.getY()<<endl;
    p.setX(11); p.setY(10);
    cout<<"coordenadas con luego de set()"<<p.getX()<<" "<<p.getY()<<endl;
    p2.modifyPoint(7,8);
    cout<<"punto 3 con tras modifypoint(): "<<p2.getX()<<" "<<p2.getY()<<endl;
    */

    PointArray pa(points, 3);
    //pa.print_arr();
    pa.push_b(Point(7,5));

    pa.insertar(1,Point(1,1));
    pa.insertar(1,Point(1,1));
    //pa.insertar(1,Point(1,1));
    //pa.insertar(1,Point(1,1));
    //pa.insertar(1,Point(1,5));
    pa.push_b(Point(7,5));
    pa.push_b(Point(7,5));
    pa.push_b(Point(7,5));
    pa.print_arr();


return 0;
}
