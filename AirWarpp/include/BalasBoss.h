#ifndef BALASBOSS_H
#define BALASBOSS_H
#include "Player.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdint.h>

using namespace std;


class BalasBoss
{
    public:
        BalasBoss();
        virtual ~BalasBoss();

    int x;
    int y;
    int velX;
    int velY;
    int dirX;
    int dirY;
    bool activa;

    void UpdateBullet(BalasBoss bullet[], int size);
    void DrawBullet(BalasBoss bullet[], int size);
    void ColisionB(BalasBoss bullet[], int size, Player &player);
    void Disparar(BalasBoss bullet[], int size);
    int GetX();
    int GetY();

};

#endif // BALASBOSS_H
