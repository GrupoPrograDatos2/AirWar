#ifndef BOSS_H
#define BOSS_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdint.h>
#include "BalasBoss.h"

using namespace std;

class Boss
{
    public:
        Boss(int limImgX,int limImY,int vida,ALLEGRO_BITMAP *imagen, int nivel);
        virtual ~Boss();

        //posiciones y limites
        int x;
        int y;
        int LimiteX;
        int LimiteY;

        //vida
        int vida;
        //ID
        int ID;
        //activación el escudo y disparos
        int ActEsc;
        int Disp;

        ALLEGRO_BITMAP *imagen_boss;

        int getX();
        int getY();

        //lista de balas
        BalasBoss balas[50];

        void Colision(Player &player);
        void pelear();

        bool escudo;




};

#endif // BOSS_H
