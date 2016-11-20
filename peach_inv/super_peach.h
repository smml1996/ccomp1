#include <allegro5/allegro.h>
class Pitchie {

    ALLEGRO_BITMAP *pitchie_img;
    bool is_shooting;
    short vidas;
    void flip_superpower();
    bool super_power = false;
    unsigned int x,y;
    char * score;
    unsigned char score_len;
    public:
        Pitchie(const ALLEGRO_MONITOR_INFO &info);
        ALLEGRO_BITMAP *get_image();
        void change_position(const bool is_up, const ALLEGRO_MONITOR_INFO &info );
        int get_x();
        int get_y();
        void redraw();
        void operator+();
        char * get_score();
};
