#include "polygons.h"
#include <cmath>


Point constructorPoints[4];

Point *updateConstructorPoints(const Point &p1, const Point &p2, const Point &p3, const Point &p4 = Point(0,0)){
    constructorPoints[0]=p1;
    constructorPoints[1]=p2;
    constructorPoints[2]=p3;
    constructorPoints[3]=p4;
    return constructorPoints;

}

Triangle::Triangle(Point &a, Point &b, Point &c):Polygon(updateConstructorPoints(a,b,c),3) {

    nPolygons++;
}

double Triangle::area() {
    double side1, side2, side3;
    side1 = pow(pa.get_p()->getX()- (pa.get_p()+1)->getX(),2);
    side1+= pow(pa.get_p()->getY()- (pa.get_p()+1)->getY(),2);
    side1 = sqrt(side1);
    side2 = pow((pa.get_p()+1)->getX()-(pa.get_p()+2)->getX(),2);
    side2+= pow((pa.get_p()+1)->getY()-(pa.get_p()+2)->getY(),2);
    side2 = sqrt(side2);
    side3 = pow(pa.get_p()->getX()-(pa.get_p()+2)->getX(),2);
    side3+= pow(pa.get_p()->getY()-(pa.get_p()+2)->getY(),2);
    side3 = sqrt(side3);
    double midPerimeter = (side1+side2+side3)/2.0;
    return sqrt(midPerimeter*(midPerimeter-side1)*(midPerimeter-side2)*(midPerimeter-side3));
}

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
