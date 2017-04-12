#include "Boss.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdint.h>
using namespace std;

Boss::Boss(int limImgX,int limImY,int vida,ALLEGRO_BITMAP *imagen, int nivel)
{
    //ctor
    LimiteX=limImgX;
    LimiteY=limImY;
    vida=vida;
    escudo=false;
    ID=nivel%4;//porque son 4 bosses distintos
    ActEsc=rand()- nivel*100;
    cont=0;
    Disp=rand()-nivel*100;
    imagen_boss=imagen;
    for (int i = 0; i < 60; i++){
        balas[i] = BalasBoss();
        balas[i].y = y;
        balas[i].x = x;
	    balas[i].activa = false;
        }
}

void Boss::pelear()//patrón que utilizará el boss para disparar
{

    if(ActEsc<0)
    {
        ActEsc==0;
    }
    if(cont==ActEsc)
    {
        escudo=true;
        balas[0].Disparar(balas,50);
    }
    if(cont==Disp)
    {
    balas[0].Disparar(balas,50);
    }
    if(cont==ActEsc*2){
        escudo=false;
        cont=0;
    }

}

void Boss::Colision(Player &player)
{
if (LimiteY<player.GetY() + player.GetBoundy()&&LimiteY > player.GetY() - player.GetBoundy()&&!escudo)
        {
            player.lives--;
        }
}

int Boss::getX()
{

    return x;
}

int Boss::getY()
{

    return y;
}

Boss::~Boss()
{
    //dtor
}
