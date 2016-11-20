#include <allegro5/allegro.h>
#include <vector>
#include "weapon.h"

using namespace std;
class Enemy{
protected:
    ALLEGRO_BITMAP *img_enemy;
    const char *path;
    int x, y;
    unsigned char damage;
    bool up;
    void update_hit();

public:
    Enemy(int x,int y, const char *path);
    virtual void move_enemy()=0;
    int get_x();
    int get_y();
};

class poni_arcoiris: public Enemy{
    public:
        poni_arcoiris(int x, int y, const char *path);
        void move_enemy();
};




class poni_rudo_weapon: public Weapon{
    public:
        poni_rudo_weapon(int x, int y, const char *path);
};

class poni_rudo: public Enemy {
  //  vector<poni_rudo_weapon> nubes;
    public:
        poni_rudo(int x, int y, const char *path);
        void move_enemy();
};

class vector_enemigos{
    vector< Enemy * > popoponies;
    public:
        vector_enemigos(const bool &is_arcoiris, const ALLEGRO_MONITOR_INFO &info);
        void move_enemies();
        bool check_collision(const unsigned int &x,const unsigned int &y);
        bool is_empty_();
        void refill(const bool &is_poni_arcoiris, const ALLEGRO_MONITOR_INFO &info);
};

