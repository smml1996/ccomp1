#include "super_peach.h"
#include<iostream>

using namespace std;

Pitchie::Pitchie(const ALLEGRO_MONITOR_INFO &info,char * img,char *sound){
    pitchie_img = al_load_bitmap(img);
    sonido = al_load_sample(sound);
    vidas = 5;
    this->img=img;
    is_shooting = false;
    x = 10;
    y = info.y2/2;

}

void Pitchie::flip_superpower(){ super_power !=super_power;}

ALLEGRO_BITMAP *Pitchie::get_image(){return pitchie_img;}

void Pitchie::take_damage(bool &exit){
    vidas--;
    al_play_sample(sonido,1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);

    if(vidas <= 0){
        exit = true;
    }else{
        switch(vidas){
            case 1:
                this->img="img/pony_vida_1.png";
                break;
            case 2:
                this->img="img/pony_vida_2.png";
                break;
            case 3:
                this->img="img/pony_vida_3.png";
                break;
            case 4:
                this->img="img/pony_vida_4.png";
                break;
        }
    }
}

void Pitchie::change_position(const bool is_up, const ALLEGRO_MONITOR_INFO &info){
    if(is_up){
        if(y-5>10)y-=10;
        else y = info.y2-100;
    }else if(y+5<=info.y2-170)y+=10;
    else y=0;

}
int Pitchie::get_vidas(){return vidas;}
int Pitchie::get_x(){return x;}
int Pitchie::get_y(){return y;}

void Pitchie::redraw(){
    al_destroy_bitmap(pitchie_img);
    pitchie_img = al_load_bitmap(img);
    al_draw_bitmap(pitchie_img,x,y,0);
}


