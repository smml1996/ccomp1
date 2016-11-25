#include "weapon.h"
#include <iostream>

using namespace std;
int Weapon::actual_weapons = 0;
Weapon::Weapon(int x, int y, const char *path){
    img = al_load_bitmap("img/horn.png");
    al_draw_bitmap(img,x,y,20);
    this->x = x; this->y = y;
    actual_weapons++;
}

int Weapon::get_x(){
    return x;
}

int Weapon::get_y(){
    return y;
}

int &Weapon::get_num_weapons(){
    return actual_weapons;
}

bool Weapon::move_weapon(const ALLEGRO_MONITOR_INFO &info){
    al_destroy_bitmap(img);
    img = al_load_bitmap("img/horn.png");
    x+=10;
    if(x>=info.x2){
        return false;
    }
    al_draw_bitmap(img,x,y,0);
    return true;
}
