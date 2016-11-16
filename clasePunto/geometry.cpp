

Point constructorPoints[4];

Point *updateConstructorPoints(const Point &p1, const Point &p2, const Point &p3, const Point &p4 = Point(0,0)){
    constructorPoints[0]=p1;
    constructorPoints[1]=p2;
    constructorPoints[2]=p3;
    constructorPoints[3]=p4;
    return constructorPoints;

}