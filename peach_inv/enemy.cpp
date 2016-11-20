#include "enermy.h"
#include <iostream>

using namespace std;
Enemy::Enemy(int x, int y, const char *path){
    damage = 0;
    this->path = path;
    this->x = x; this->y = y; img_enemy = al_load_bitmap(path); up =false;

    if(!img_enemy){
        cout<<"asdfnv";
    }
    al_draw_bitmap(img_enemy,x,y,0);
}

int Enemy::get_x(){
    return x;
}

int Enemy::get_y(){
    return y;
}

void Enemy::update_hit(){
    if(++damage ==3){
        //delete(); ************************************************************
    }
}
poni_arcoiris::poni_arcoiris(int x, int y, const char *path): Enemy(x,y,path){}

void poni_arcoiris::move_enemy(){
    if(up){
        y+=5;
        up=false;
    }else{
        y-=5;
        up=true;
    }
    x-=2;

    al_destroy_bitmap(img_enemy);
    img_enemy = al_load_bitmap(path);
    al_draw_bitmap(img_enemy,x,y,0);
}

poni_rudo_weapon::poni_rudo_weapon(int x, int y, const char * path):Weapon(x,y,path){}

poni_rudo::poni_rudo(int x, int y, const char *path):Enemy(x,y, path){}

void poni_rudo::move_enemy(){
    if(up){
        y+=5;
        up=false;
    }else{
        y-=5;
        up=true;
    }
    x-=2;

    al_destroy_bitmap(img_enemy);
    img_enemy = al_load_bitmap(path);
    al_draw_bitmap(img_enemy,x,y,0);
}

vector_enemigos::vector_enemigos(const bool &is_arcoriris, const ALLEGRO_MONITOR_INFO &info){
    int i = 5; int space= 20;
    while(i--){
        if(is_arcoriris){
            popoponies.push_back(new poni_arcoiris(info.x2-200, space, "img/enemigo.png"));
        }else{
            popoponies.push_back(new poni_rudo(info.x2, space, "img/enemigo2.png"));
        }
        space+=200;

    }
}

void vector_enemigos::move_enemies(){
    for(int i = 0; i<popoponies.size();i++){
        popoponies[i]->move_enemy();
        if(popoponies[i]->get_x() ==0){
            Enemy * temp = popoponies[i];
            popoponies.erase(popoponies.begin()+i);
            delete temp;

        }
    }
}

bool vector_enemigos::check_collision(const unsigned int &x, const unsigned int &y){
    for(int i = 0; i<popoponies.size();i++){
        if(x >= popoponies[i]->get_x() && (y >= popoponies[i]->get_y() && y<= popoponies[i]->get_y()+90)){
            Enemy * temp = popoponies[i];
            popoponies.erase(popoponies.begin()+i);
            delete temp;
            return true;
        }
    }return false;
}

bool vector_enemigos::is_empty_(){
    return popoponies.size()==0;
}

void vector_enemigos::refill(const bool &is_poni_arcoiris, const ALLEGRO_MONITOR_INFO &info){
    int i = 4; int space= 20;
    while(i--){
        if(is_poni_arcoiris){
            popoponies.push_back(new poni_arcoiris(info.x2-200, space, "img/enemigo.png"));
        }else{
            popoponies.push_back(new poni_rudo(info.x2-200, space, "img/enemigo2.png"));
        }
        space+=200;
    }

}

