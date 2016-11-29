#include <allegro5/allegro.h>
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"
class Pitchie {
    ALLEGRO_BITMAP *pitchie_img;
    ALLEGRO_SAMPLE *sonido;
    char *img;
    unsigned int puntos;
    bool is_shooting;
    short vidas;
    void flip_superpower();
    bool super_power = false;
    unsigned int x,y;
    public:
        Pitchie(const ALLEGRO_MONITOR_INFO &info,char *img,char *sound);
        ALLEGRO_BITMAP *get_image();
        void change_position(const bool is_up, const ALLEGRO_MONITOR_INFO &info );
        void set_path(ALLEGRO_BITMAP img);
        int get_x();
        int get_y();
        int get_vidas();
        void take_damage(bool &exit);
        void redraw();
};
