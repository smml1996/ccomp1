class Point {
    private:
        float x; float y;
    public:
        Point();
        Point(int x, int y);
        Point(Point &p);
        float getX() const;
        float getY() const;
        void setX(int x);
        void setY(int y);
        void printPoint();
        void modifyPoint(int x, int y);
};
