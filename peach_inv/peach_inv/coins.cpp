#include "coins.h"
#include<string>
Coins::Coins(){
    value=0;
}
Coins::Coins(int x){
    value= x;
}
int Coins::get_value(){
    return value;
}
void Coins::set_value(int val){
    value=val;
}
Coins Coins::operator+(Coins o){
    Coins temp;
    temp.set_value(o.get_value()+value);
    return temp;
}
