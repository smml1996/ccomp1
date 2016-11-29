#include<iostream>
using namespace std;
class Coins{
private:
    int value;
public:
    Coins();
    Coins(int x);
    int get_value();
    void set_value(int val);
    Coins operator+(Coins o);

};
