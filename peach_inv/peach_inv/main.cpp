#include <iostream>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"
#include "super_peach.h"
#include "enermy.h"
#include "coins.h"
#define ALPHA 0.5f
#define FPS 20.0

using namespace std;


int puntos = 0;
Coins monedas;
Coins incremento(5);
int score = 0;

enum keys {
    KEY_UP, KEY_DOWN, KEY_SPACE
};

template <typename t>
string to_string(t i)
{
    stringstream ss;
    ss << i;
    return ss.str();
}
int main(int argc, char **argv){


    bool is_weapon;
    vector<Weapon *> weapons;
    bool wanna_exit= false;
    bool key[3]={false,false, false};
    bool is_poni_arc =1;
    string ps =to_string(puntos), cs=to_string(monedas.get_value());
    char const *pchar =ps.c_str(), *cchar=cs.c_str();char *j = "img/pony_vida_5.png";


    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_MONITOR_INFO info;
    ALLEGRO_BITMAP  *image   = NULL;
    ALLEGRO_EVENT ev;


    al_init();
    al_init_font_addon();
    al_init_ttf_addon();
    al_install_keyboard();
    timer = al_create_timer(1.0 / FPS);
    al_get_monitor_info(0,&info);
    display = al_create_display(info.x2, info.y2);
    al_init_image_addon();
    al_start_timer(timer);
    Pitchie p(info,j);
    vector_enemigos v_e(0, info);
    ALLEGRO_COLOR color = al_map_rgba_f(1.0*ALPHA, 0.4*ALPHA, 0.6*ALPHA, ALPHA);
    ALLEGRO_COLOR cleanColor = al_map_rgb(0,0,0);
    image = al_load_bitmap("img/galaxy.jpg");
    ALLEGRO_FONT *font = al_load_ttf_font("fonts/Starfish.ttf",72,0);
    event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());


    while(!wanna_exit){
        al_wait_for_event(event_queue, &ev);

        if(ev.type == ALLEGRO_EVENT_TIMER) {
            al_clear_to_color(cleanColor);
            al_draw_bitmap(image,0,0,0);
            p.redraw();

            if(key[KEY_UP]) {
                p.change_position(true,info);
            }

            if(key[KEY_DOWN]) {
                p.change_position(false,info);
            }

            if(key[KEY_SPACE]);

            ps = to_string(puntos);

        }else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {

                break;

        }else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
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
        }else if(ev.type == ALLEGRO_EVENT_KEY_UP) {

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
                    if(Weapon::get_num_weapons()<5){
                        weapons.push_back(new Weapon(p.get_x()+70,p.get_y()+10, "img/horn.png"));
                        Weapon::get_num_weapons()++;
                    }
                    break;
            }

        }

        if(v_e.move_enemies(p.get_x(),p.get_y())){
            p.take_damage(wanna_exit);
        }

        for(unsigned int i = 0; i<weapons.size();i++){

            if(!(weapons[i]->move_weapon(info)) ||v_e.check_collision(weapons[i]->get_x(), weapons[i]->get_y())){

                delete weapons[i];
                weapons.erase(weapons.begin()+i);
                Weapon::get_num_weapons()--;
                puntos+=10;
                monedas = monedas +incremento;

            }

        }

        if(v_e.is_empty_()){

            v_e.refill(is_poni_arc,info);
            is_poni_arc = !is_poni_arc;

        }

        ps  = to_string(puntos);
        cs = to_string(monedas.get_value());
        pchar = ps.c_str();
        cchar = cs.c_str();
        al_draw_text(font, color, info.x2/2,info.y2/2 -200,ALLEGRO_ALIGN_CENTRE, "Puntos: ");
        al_draw_text(font, color, (info.x2/2)+210,info.y2/2 -200,ALLEGRO_ALIGN_CENTRE, pchar);
        al_draw_text(font, color, info.x2/2,info.y2/2,ALLEGRO_ALIGN_CENTRE, cchar);
        al_draw_text(font, color, info.x2/2+100,info.y2/2,ALLEGRO_ALIGN_CENTRE, "$");
        al_flip_display();

    }

    al_destroy_timer(timer);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_install_audio();
    al_init_acodec_addon();
    al_reserve_samples(1);
    ALLEGRO_SAMPLE *sample= al_load_sample("sounds/game_over.wav");
    display = al_create_display(info.x2,info.y2);
    al_play_sample(sample, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL);
    al_clear_to_color(al_map_rgb(0,0,0));
    image = al_load_bitmap("img/final_pic.png");
    al_draw_bitmap(image,0,0,0);
    al_flip_display();
    al_rest(20.0);
    al_destroy_display(display);
    al_destroy_sample(sample);

    return 0;
}
