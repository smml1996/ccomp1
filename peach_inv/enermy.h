#include <allegro5/allegro.h>
#include <vector>
#include "weapon.h"

using namespace std;
class Enemy{
protected:
    ALLEGRO_BITMAP *img_enemy;
    int x, y;
    bool up;
public:
    Enemy(int x,int y, const char *path);
    virtual void move_enemy(const char *path)=0;
    int get_x();
    int get_y();
};

class poni_arcoiris: public Enemy{
    public:
        poni_arcoiris(int x, int y, const char *path);
        void move_enemy(const char *path);
};

class poni_rudo_weapon: public Weapon{

    public:
        poni_rudo_weapon(int x, int y, const char *path);
};

class poni_rudo: public Enemy {
    vector<poni_rudo_weapon> nubes;
    public:
        poni_rudo(int x, int y, const char *path);
};
