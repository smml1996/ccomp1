#include "super_peach.h"
#include<iostream>
using namespace std;

Pitchie::Pitchie(const ALLEGRO_MONITOR_INFO &info){
    pitchie_img = al_load_bitmap("img/peach.png");;
    vidas = 5;
    is_shooting = false;
    x = 10;
    y = info.y2/2;
}

void Pitchie::flip_superpower(){
    super_power !=super_power;
}

ALLEGRO_BITMAP *Pitchie::get_image(){
    return pitchie_img;
}


void Pitchie::change_position(const bool is_up, const ALLEGRO_MONITOR_INFO &info){
    if(is_up){
        cout<<y<<endl;
        if(y-5>10){
            y-=10;
        }else{
            y = info.y2-150;
        }
    }else if(y+5<=info.y2-170){
        y+=10;
    }else{
        y=0;
    }
}


int Pitchie::get_x(){
    return x;
}

int Pitchie::get_y(){
    return y;
}

void Pitchie::redraw(){
    al_destroy_bitmap(pitchie_img);
    pitchie_img = al_load_bitmap("img/peach.png");
    al_draw_bitmap(pitchie_img,x,y,0);
}

