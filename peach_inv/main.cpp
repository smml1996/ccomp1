#include <iostream>
#include <string.h>
#include <vector>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "super_peach.h"
#include "enermy.h"
#define FPS 20.0
#define ALPHA 0.5f
using namespace std;

enum keys {
    KEY_UP, KEY_DOWN, KEY_SPACE
};
char* puntos = "Puntos: 0";
char* monedas = "Coins : 0";
int score = 0;
//int c = 0;
int main(int argc, char **argv){

//variables

    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_MONITOR_INFO info;
    ALLEGRO_BITMAP  *image   = NULL;

    vector<Weapon *> weapons;
    bool wanna_exit= false;
    bool key[3]={false,false, false};

// **************************************************

//INICIALiZACIONES
    if(!al_init()){
        cerr<<"no se pudo inicializar allegro"<<endl;
        return -1;
    }
    al_init_font_addon();
    al_init_ttf_addon();
    al_install_keyboard();
    ALLEGRO_FONT *font = al_load_ttf_font("fonts/Starfish.ttf",72,0);
    timer = al_create_timer(1.0 / FPS);
    if(!timer) {
      cerr<< "failed to create timer!\n"<<endl;
      return -1;
    }
    al_get_monitor_info(0,&info);
    display = al_create_display(info.x2, info.y2);
    ALLEGRO_COLOR color = al_map_rgba_f(1.0*ALPHA, 0.4*ALPHA, 0.6*ALPHA, ALPHA);
    ALLEGRO_COLOR cleanColor = al_map_rgb(0,0,0);
    if(!display){
        cerr<<"no se pudo configurar la pantalla"<<endl;
        return -1;
    }
    if(!al_init_image_addon()) {
      al_show_native_message_box(display, "Error", "Error", "no se pudo inicializar libreria",
                                 NULL, ALLEGRO_MESSAGEBOX_ERROR);
      return 0;
    }

    image = al_load_bitmap("img/galaxy.jpg");
    char *j = "img/pony_vida_5.png";
    Pitchie p(info,j);
    if(!image) {
      al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
                                 NULL, ALLEGRO_MESSAGEBOX_ERROR);
      al_destroy_display(display);
      return 0;
   }
    al_draw_bitmap(image,0,0,0);
    al_draw_bitmap(p.get_image(), p.get_x(),p.get_y(),0);

    event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
vector_enemigos v_e(0, info);

    al_flip_display();
    al_start_timer(timer);
    bool is_poni_arc =1;

//***********************************************************

    while(!wanna_exit){
        ALLEGRO_EVENT ev;

        al_wait_for_event(event_queue, &ev);

        if(ev.type == ALLEGRO_EVENT_TIMER) {
         if(key[KEY_UP]) {
            p.change_position(true,info);

         }
         if(key[KEY_DOWN]) {
            p.change_position(false,info);

         }if(key[KEY_SPACE]){

         }

      }
      else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
         break;
      }
      else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
         switch(ev.keyboard.keycode) {
            case ALLEGRO_KEY_UP:
               key[KEY_UP] = true;
               break;

            case ALLEGRO_KEY_DOWN:
               key[KEY_DOWN] = true;
               break;
            case ALLEGRO_KEY_SPACE:
                key[KEY_SPACE]=true;
                break;
         }
      }
      else if(ev.type == ALLEGRO_EVENT_KEY_UP) {
         switch(ev.keyboard.keycode) {
            case ALLEGRO_KEY_UP:
               key[KEY_UP] = false;
               break;

            case ALLEGRO_KEY_DOWN:
               key[KEY_DOWN] = false;
               break;

            case ALLEGRO_KEY_ESCAPE:
               wanna_exit = true;
               break;
            case ALLEGRO_KEY_SPACE:
                key[KEY_SPACE]=false;
                if(Weapon::get_num_weapons()<10){
                weapons.push_back(new Weapon(p.get_x()+70,p.get_y()+10, "img/peach.png"));
            }
                break;
         }
      }
       al_clear_to_color(cleanColor);
     al_draw_bitmap(image,0,0,0);
     p.redraw();


    al_draw_text(font, color, info.x2/2,info.y2/2 -200,ALLEGRO_ALIGN_CENTRE, puntos);
    al_draw_text(font, color, info.x2/2,info.y2/2,ALLEGRO_ALIGN_CENTRE, monedas);
    if(v_e.move_enemies()){
        p.take_damage();
    }
     for(unsigned int i = 0; i<weapons.size();i++){
        if(!(weapons[i]->move_weapon(info)) ||v_e.check_collision(weapons[i]->get_x(), weapons[i]->get_y())){
            delete weapons[i];
            weapons.erase(weapons.begin()+i);
            Weapon::get_num_weapons()--;

            score++;

        }
     }
     al_flip_display();
     if(v_e.is_empty_()){
        v_e.refill(is_poni_arc,info);
        is_poni_arc = !is_poni_arc;
     }
    }
   al_destroy_timer(timer);
   al_destroy_display(display);
   al_destroy_event_queue(event_queue);
    return 0;
}
