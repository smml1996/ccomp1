#include "polygon.h"

int Polygon::nPolygons =0;
Polygon::Polygon(PointArray &pa) {
    this->pa = PointArray(pa);
}

Polygon::Polygon(Point points[], int arrl) {
    this->pa =PointArray(points, arrl);
}
Polygon::Polygon() {
    this->pa = PointArray();
}

int Polygon::getNumPolygons() {
    return this->nPolygons;
}

int Polygon::getNumSides(){
    return (this->pa).get_size();
}

const Point * Polygon::getPoints() {
    return (this->pa).get_p();
}
