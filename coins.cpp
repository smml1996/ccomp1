#include "coins.h"
#include<string>
Coins::Coins(){
    value=0;
}
Coins::Coins(float x){
    value= x;
}
float Coins::get_value(){
    return value;
}
void Coins::set_value(float val){
    value=val;
}
Coins Coins::operator+(Coins o){
    Coins temp;
    temp.set_value(o.get_value()+value);
    return temp;
}
