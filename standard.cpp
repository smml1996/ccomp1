#include <iostream>
#include <queue>
#include <stack>
#include <list>
#include <vector>

using namespace std;

bool less_t_5(int n){ return n<5;}
int main(){
    vector<int> v(4,100);
    vector<int> v2(3,7);
    v.push_back(101);
    v.pop_back();
    list<int> lista(4, 7), lista2;


    stack<int> sck;
    queue<int> q;
    for(int i = 0; i<4; i++){ q.push(i);
    lista2.push_back(i); sck.push(i);}
    cout<<"la cola contiene "<<q.size()<<" elementos"<<endl;
    cout<<"el ultimo elemento de la cola es: "<<q.back()<<endl;
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;

    cout<<"el vector contiene "<<v.size()<<" elementos"<<endl;
    cout<<"el vector puede llegar a contener "<<v.max_size()<<endl;
    cout<<"elementos del vector: ";
    for(vector<int>::iterator i = v.begin(); i!=v.end();i++){
        cout<<*i<<" ";
    }
    cout<<endl;
    cout<<"recorriend el vector desde el final con rbegin(): ";
        for(vector<int>::reverse_iterator i = v.rbegin(); i!=v.rend();i++){
        cout<<*i<<" ";
    }
    cout<<endl;
    v.clear(); //ahora el tamaño del vector es 0
    v.swap(v2); //cambiando los contenidos de v y v2
    v.erase(v.begin()+1); //(borra el elemento 0)
    v.insert(v.begin()+1, 200); //inserta 200 en la posicion 1
    v.assign(7,100); //asigna nuevo contenido al vector en este caso 7 cienes

    int *p = v.data(); // p es un puntero al primer elemento del vector
    cout<<v.back()<<endl; //muetra en pantalla el ultimo elemento del vector
     cout<<v.front()<<endl;//muetra en pantalla el primer elemento del vector
     cout<<v.at(0)<<endl; //muestra tambien el primer elemento del vector, el indice se especifica en el parametro

    v.resize(1); //elimina todos lo elementos hasta quedarse con uno
    v.capacity();//muestra cuantos elementos puede contener hasta el momento
    cout<<v.empty()<<endl; //imprime 0, el vector tiene un elemento
    v.reserve(100);// se hace un pedido para que el vector pueda contener por lo menos 100 elementos, si se puede
                    // se hace un cambio de direccion de memoria con la nueva continua que pueda almacenar 100 elementos
    cout<<endl;
    list<int>::iterator it = lista.begin();
    it++;
    lista.splice(it,lista2); //lista : 7 0 1 2 3 7 7

    lista.remove(7); //elimina todos los 7's de la lista
    lista.remove_if(less_t_5); //elimina los elementos menores a 5
    lista.push_back(7);lista.push_back(7);
    lista.push_back(7); lista.push_back(7); lista.push_back(7);
    lista.unique();//elimina elementos repetidos


    lista.clear(); lista2.clear();
    for(int i = 0; i<5; i++){
        if(i %2 ==0){
            lista.push_back(i);
        }else{
            lista2.push_back(i);
        }
    }

    lista.merge(lista2); //lista 2 ahora esta vacia y lista 1 contiene 0 1 2 3 4
    lista.reverse(); //lista ahora es 4 3 2 1 0
    lista.sort(); //lista es denuevo 0 1 2 3 4

    //STACK
    while(!sck.empty()){
        cout<<sck.top()<<" " ;
        sck.pop();
        }
    // 3 2 1 0
}
