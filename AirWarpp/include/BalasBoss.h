#ifndef BALASBOSS_H
#define BALASBOSS_H
#include "Player.h"
#include "Boss.h"
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
    void Colision(BalasBoss bullet[], int size, Player &player,Boss &boss);
    void Disparar(BalasBoss bullet[], int size,Boss &boss);
    int GetX();
    int GetY();

};

#endif // BALASBOSS_H
