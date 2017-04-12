#include "Boss.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdint.h>
using namespace std;

Boss::Boss(int limImgX,int limImY,int vida,ALLEGRO_BITMAP *imagen)
{
    //ctor
    LimiteX=limImgX;
    LimiteY=limImY;
    vida=vida;
    imagen_boss=imagen;
}

Boss::~Boss()
{
    //dtor
}
