//#include "punto.h"
//#include "vector2.h"
//#include "arrVectors.h"
#include <iostream>
//#include "arrPoints.h"

#include "rectangle.h"
using namespace std;
/*
void printAttributes(Polygon *polygon) {
    cout<<"the area of the polygon is "<<polygon->area()<<endl;
    cout<<"the coordinates are: "<<endl;
    cout<<"x y"<<endl;
    const Point *temp = polygon->getPoints();
    for(int i = 0; i<polygon->getNumSides();i++){
        cout<<(temp+i)->getX()<<" "<<(temp+i)->getY()<<endl;
    }
}*/
int main(){
    /*
    int x1, y1, x2, y2;
    cin>>x1>>y1>>x2>>y2;
    Rectangle rec = Rectangle(x1,y1,x2,y2);
    printAttributes(&rec);*/
/*
    Point p(1,2);
    Point p1(7,7);
    Point p2(8,8);
    Point points[3] = {p,p1,p2};

    V v(p,p1);
    V v1(p2,p1);
    V vectors[2] = {v, v1};
    arrVec av(vectors, 2);

    av.print_arr();
    cout<<av.get_size()<<endl;
    av.remove_vec(1);
    av.print_arr();
    av.push_b(v);
    av.print_arr();
    av.clear_arr();
    av.print_arr();
    av.insertar(0,v1);
    av.print_arr();
*/
/*
    cout<<"punto 1: "; p.printPoint(); cout<<endl;
    cout<<"punto 2 (con constructor copia)"; points[1].printPoint();cout<<endl;
    cout<<"punto 3 con constructor vacio";p2.printPoint(); cout<<endl;
    cout<<"cooderndas x e y con get() "<<p.getX()<<" "<<p.getY()<<endl;
    p.setX(11); p.setY(10);
    cout<<"coordenadas con luego de set()"<<p.getX()<<" "<<p.getY()<<endl;
    p2.modifyPoint(7,8);
    cout<<"punto 3 con tras modifypoint(): "<<p2.getX()<<" "<<p2.getY()<<endl;


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
    //pa.print_arr();
    //cout<<sizeof(pa);
    pa.clear_arr();
    pa.print_arr();
    pa.remove_point(2);
    pa.print_arr();
*/

return 0;
}
