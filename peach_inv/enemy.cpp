#include "enermy.h"
#include <iostream>

using namespace std;
Enemy::Enemy(int x, int y, const char *path){

    this->x = x; this->y = y; img_enemy = al_load_bitmap("img/enemigo.png"); up =false;

    if(!img_enemy){
        cout<<"asdfnv";
    }
}

int Enemy::get_x(){
    return x;
}

int Enemy::get_y(){
    return y;
}

poni_arcoiris::poni_arcoiris(int x, int y, const char *path): Enemy(x,y,path){
}

void poni_arcoiris::move_enemy(const char *path){
    if(up){
       // y+=5;
        up=false;
    }else{
     //   y-=5;
        up=true;
    }
    x-=2;

    al_destroy_bitmap(img_enemy);
    img_enemy = al_load_bitmap("img/enemigo.png");
    al_draw_bitmap(img_enemy,x,y,0);
}

poni_rudo_weapon::poni_rudo_weapon(int x, int y, const char * path):Weapon(x,y,path){

}
