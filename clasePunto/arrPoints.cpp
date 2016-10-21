#include "arrPoints.h"
#include <iostream>

using namespace std;
PointArray::PointArray(const Point points[], const int s){
    this-> point = new Point[s+5];
    this-> s = s;
    Point *temp = point;
    for(int i = 0; i<s; i++, temp++){
        *temp = points[i];
    }
}

PointArray::PointArray(const PointArray &pv){
    this->point =  new Point[pv.get_size()+5];
    this->s = pv.get_size();
    Point *temp = point;
    Point *temp1 = pv.point;
    for(int i = 0; i<pv.get_size(); i++,temp++, temp1++){
        *temp = *temp1;
    }
}

PointArray::PointArray(){
    this-> s = 0;
    this->point = new Point[5];
}

bool PointArray::realloc(const int s){
    this-> point =  new Point[s+5];
    if(point!=NULL)return true;
    return false;
}

void PointArray::push_b(const Point &p){
    Point *temp = this->point;


    if(!(temp+s)->isNull()){
        Point *temp0 = this->point;
        realloc(this->s+5);
        Point *temp2 = this->point;
        for(int i = 0; i<s;i++,temp++, temp2++){
            temp2->modifyPoint(temp->getX(), temp->getY());
            temp2->flipNull();
        }
        temp2->modifyPoint(p.getX(), p.getY());
        delete[] temp0;
        (this->s)++;
        return;
    }
    temp+=(this->s);
    temp->modifyPoint(p.getX(), p.getY());
    (this->s)++;
}

void PointArray::insertar(const int index, const Point &p){
    if(index>this->s) throw "indice invalido";
    if(index==this->s){
        this->push_b(p);
        return;
    }
    Point *temp = this->point;

    if(!(temp+s)->isNull()){
        realloc(this->s+5);
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
        delete [] temp;
        (this->s)++;
        return;
    }
    Point *temp1 = temp;
    temp1+= (this->s)-1;
    int i = (this->s)-1;
    for(; i>=index; i--,temp1--){
        (temp1+1)->modifyPoint(temp1->getX(), temp1->getY());
    }
    (temp+i+1)->modifyPoint(p.getX(), p.getY());
    (this->s)++;
}

const int PointArray::get_size()const{
    return this->s;
}

void PointArray::clear_arr(){
    delete[] this->point;
}

void PointArray::print_arr(){
    Point *p = this->point;
    for(int i = 0; i<this->s; i++, p++){
        cout<<p->getX()<<" "<<p->getY()<<endl;
    }
}



void PointArray::remove_arr(const int index){
     Point *temp = *this->point;
     
}
