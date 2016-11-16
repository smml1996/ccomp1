#include "rectangle.h"
#include "geometry.cpp"
#include <cmath>
Rectangle::Rectangle(const Point &a, const Point &b):Polygon(updateConstructorPoints(a,Point(a.getX(),b.getY()),Point(b.getX(),a.getY()),b),4){
    this->nPolygons++;
}
Rectangle::Rectangle(int x1, int y1, int x2, int y2):Polygon(updateConstructorPoints(Point(x1,y1),Point(x1,y2),Point(x2,y2),Point(x2,y1)),4) {

    nPolygons++;
}


double Rectangle::area() {
    double side1 = fabs((*((this->pa).get_p())).getX() - (*((this->pa).get_p()+2)).getX());
    double side2 = fabs((*((this->pa).get_p())).getY() - (*((this->pa).get_p()+2)).getY());
    return side1*side2;
}
