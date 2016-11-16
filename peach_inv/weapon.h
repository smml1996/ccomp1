#include <allegro5/allegro.h>
#include <string>

using namespace std;
class Weapon{
    int x, y;
    ALLEGRO_BITMAP *img;
    static int actual_weapons;
    public:
        Weapon(int x, int y, const char *path);
        Weapon();
        int get_x();
        int get_y();
        virtual bool move_weapon(const ALLEGRO_MONITOR_INFO &info);
        static int &get_num_weapons();
};
