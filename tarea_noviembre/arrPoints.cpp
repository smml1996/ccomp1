#include "arrPoints.h"
#include <iostream>

using namespace std;
PointArray::PointArray(const Point points[], const int s){
    this-> point = new Point[s];
    this-> s = s;
    Point *temp = this->point;
    for(int i = 0; i<s; i++, temp++){
        *temp = points[i];
    }
}

PointArray::PointArray(const PointArray &pv){
    this->point =  new Point[pv.get_size()];
    this->s = pv.get_size();
    Point *temp = this->point;
    Point *temp1 = pv.get_p();
    for(int i = 0; i<pv.get_size(); i++,temp++, temp1++){
        *temp = *temp1;
    }
}

PointArray::PointArray(){
    this-> s = 0;
    this->point =  new Point[0];
}

bool PointArray::realloc(const int s){
    this-> point =  new Point[s];
    if(!point)return true;
    return false;
}

void PointArray::clear_arr(){
    delete[] this->point;
    this->point =  new Point[0];
    this->s = 0;
}

void PointArray::push_b(const Point &p){
    Point *temp = this->point;
    realloc(this->s);
    Point *temp2 = this->point;
    for(int i = 0; i<s;i++,temp++, temp2++){
        temp2->modifyPoint(temp->getX(), temp->getY());
        if(i==s-1){
            delete[] temp;
        }
    }
    temp2->modifyPoint(p.getX(), p.getY());
    (this->s)++;


}

void PointArray::insertar(const int index, const Point &p){
    if(index>this->s) throw "indice invalido";
    if(index==this->s){
        this->push_b(p);
        return;
    }
    Point *temp = this->point;
    realloc(this->s);
    Point *temp2 = temp;
    Point *temp0 = this->point;
    for(int i = 0; i<s+1; i++, temp0++){
        if(i!=index){
            temp0->modifyPoint(temp2->getX(), temp2->getY());
            temp2++;
        }else{
            temp0->modifyPoint(p.getX(), p.getY());
        }
    }
    delete[] temp;
    (this->s)++;
}

const int PointArray::get_size()const{
    return this->s;
}

void PointArray::print_arr(){
    Point *p = this->point;
    for(int i = 0; i<this->s; i++, p++){
        cout<<p->getX()<<" "<<p->getY()<<endl;
    }
}

void PointArray::remove_point(const int position){
    Point *temp = this->point +position;
    for(int i = 0; i<this->s-1;i++, temp++){
        temp->modifyPoint((temp+1)->getX(),(temp+1)->getY());
    }
    this->s --;
}

Point * PointArray::get_p() const{
    return this->point;
}

