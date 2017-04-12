#ifndef BOSS_H
#define BOSS_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdint.h>

using namespace std;

class Boss
{
    public:
        Boss(int limImgX,int limImY,int vida,ALLEGRO_BITMAP *imagen);
        virtual ~Boss();

        //posiciones y limites
        int x;
        int y;
        int LimiteX;
        int LimiteY;

        //vida
        int vida;

        ALLEGRO_BITMAP *imagen_boss;

        int getX();
        int getY();




};

#endif // BOSS_H
