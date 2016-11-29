#include  "arrVectors.h"

#include <iostream>

using namespace std;
arrVec::arrVec(const V vectors[], const int s){

    this-> vec = new V[s];
    this-> s = s;
    V *temp = this->vec;
    for(int i = 0; i<s; i++, temp++){
        *temp = vectors[i];
    }
}

arrVec::arrVec(const arrVec &pv){
    this->vec =  new V[pv.get_size()];
    this->s = pv.get_size();
    V *temp = this->vec;
    V *temp1 = pv.get_p();
    for(int i = 0; i<pv.get_size(); i++,temp++, temp1++){
        *temp = *temp1;
    }
}

arrVec::arrVec(){
    this-> s = 0;
    this->vec = new V[0];
}

bool arrVec::realloc(const int s){
    this-> vec =  new V[s];
    return true;
}

void arrVec::clear_arr(){
    delete[] this->vec;
    this->vec = new V[0];
    this->s = 0;
}

void arrVec::push_b(V &p){
    V *temp = this->vec;
    V *temp0 = this->vec;
    this->realloc(this->s);
    V *temp2 = this->vec;
    for(int i = 0; i<s;i++,temp++, temp2++){
        temp2->changeVec(temp->getFirstP(), temp->getSecondP());
    }
    temp2->changeVec(p.getFirstP(), p.getSecondP());
    delete[] temp0;
    (this->s)++;
}

void arrVec::insertar(const int index, V &p){
    if(index>this->s) throw "indice invalido";
    if(index==this->s){
        this->push_b(p);
        return;
    }
    V *temp = this->vec;

        realloc(this->s);
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




