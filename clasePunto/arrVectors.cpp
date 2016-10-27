#include <iostream>

using namespace std;

#include "arrVectors.h"

arrVec::arrVec(const V vectors[], const int s){
    this-> vec = new V[s+5];
    this-> s = s;
    V *temp = this->vec;
    for(int i = 0; i<s; i++, temp++){
        *temp = vectors[i];
    }
}

arrVec::arrVec(const arrVec &pv){
    this->vec =  new V[pv.get_size()+5];
    this->s = pv.get_size();
    V *temp = this->vec;
    V *temp1 = pv.get_p();
    for(int i = 0; i<pv.get_size(); i++,temp++, temp1++){
        *temp = *temp1;
    }
}

arrVec::arrVec(){
    this-> s = 0;
    this->vec = new V[5];
}

bool arrVec::realloc(const int s){
    this-> vec =  new V[s+5];
    if(this->vec!=NULL)return true;
    return false;
}

void arrVec::clear_arr(){
    delete[] this->vec;
    this->vec = new V[5];
    this->s = 0;
}

void arrVec::push_b(V &p){
    V *temp = this->vec;
    if(!(temp+s)->isNull()){
        V *temp0 = this->vec;
        this->realloc(this->s+5);
        V *temp2 = this->vec;
        for(int i = 0; i<s;i++,temp++, temp2++){
            temp2->changeVec(temp->getFirstP(), temp->getSecondP());
            temp2->flipNull();
        }
        temp2->changeVec(p.getFirstP(), p.getSecondP());
        delete[] temp0;
        (this->s)++;
        return;
    }
    temp+=(this->s);
    temp->changeVec(p.getFirstP(), p.getSecondP());
    (this->s)++;
}

void arrVec::insertar(const int index, V &p){
    if(index>this->s) throw "indice invalido";
    if(index==this->s){
        this->push_b(p);
        return;
    }
    V *temp = this->vec;

    if(!(temp+s)->isNull()){
        realloc(this->s+5);
        V *temp2 = temp;
        V *temp0 = this->vec;
        for(int i = 0; i<s+1; i++, temp0++){
            if(i!=index){
                temp0->changeVec(temp2->getFirstP(), temp2->getSecondP());
                temp2++;
            }else{
                temp0->changeVec(p.getFirstP(), p.getSecondP());
            }
        }
        delete[] temp;
        (this->s)++;
        return;
    }
    V *temp1 = temp;
    temp1+= (this->s)-1;
    int i = (this->s)-1;
    for(; i>=index; i--,temp1--){
        (temp1+1)->changeVec(temp1->getFirstP(), temp1->getSecondP());
    }
    (temp+i+1)->changeVec(p.getFirstP(), p.getSecondP());
    (this->s)++;
}

const int arrVec::get_size()const{
    return this->s;
}

void arrVec::print_arr(){
    V *p = this->vec;
    for(int i = 0; i<this->s; i++, p++){
        cout<<p->getFirstP().getX()<<" "<<p->getFirstP().getY()<<"   "<< p->getSecondP().getX()<<" "<<p->getSecondP().getY()<<endl;
    }
}

void arrVec::remove_vec(const int position){
    V *temp = this->vec +position;
    for(int i = 0; i<this->s-1;i++, temp++){
        temp->changeVec((temp+1)->getFirstP(),(temp+1)->getSecondP());
    }
    (this->s) --;
}

V * arrVec::get_p() const{
    return this->vec;
}


