#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>

using namespace std;

bool inicializar_(ALLEGRO_DISPLAY *display, ALLEGRO_MONITOR_INFO &info){

    if(!al_init()){
        cerr<<"no se pudo inicializar allegro"<<endl;
        return false;
    }
    al_get_monitor_info(0,&info);
    display = al_create_display(info.x2, info.y2);
    if(!display){
        cerr<<"no se pudo configurar la pantalla"<<endl;
        return false;
    }
    al_clear_to_color(al_map_rgb(255,255,255));
    al_flip_display();
    al_rest(10.0);
    return true;
}

void escape_(ALLEGRO_DISPLAY *display){
    al_destroy_display(display);
}
