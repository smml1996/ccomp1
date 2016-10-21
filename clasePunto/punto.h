class Point {
    private:
        int x; int y; bool is_null;
    public:
        Point();
        Point(int x, int y);
        Point(Point &p);
         int getX() const;
         int getY() const;
        void setX(int x);
        void setY(int y);
        void printPoint();
        void modifyPoint(int x, int y);
        void flipNull();
        bool isNull();

};
