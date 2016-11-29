#include<iostream>
using namespace std;
class Coins{
private:
    float value;
public:
    Coins();
    Coins(float x);
    float get_value();
    void set_value(float val);
    Coins operator+(Coins o);

};
