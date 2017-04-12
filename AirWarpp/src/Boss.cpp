#include "Boss.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdint.h>
using namespace std;

Boss::Boss(int limImgX,int limImY,int vida,ALLEGRO_BITMAP *imagen, int nivel)
{
    //Constructor
    LimiteX=limImgX;//Límite del boss en X
    LimiteY=limImY;//Límite del boss en Y
    vida=vida;//Es la vida del boss
    escudo=false;
    ID=nivel%4;//porque son 4 bosses distintos
    ActEsc=rand()- nivel*100;//El escudo se activa y desactiva en base a ese número
    cont=0;//Lleva un conteo para activar el escudo y las balas
    Disp=rand()-nivel*100;//El boss dispara en base a ese número
    imagen_boss=imagen;//Es el bitmat o imagen del boss
    for (int i = 0; i < 60; i++){//Inicializa cada espacio del array de balas
        balas[i] = BalasBoss();
        balas[i].y = y;
        balas[i].x = x;
	    balas[i].activa = false;
        }
}

void Boss::pelear()//patrón que utilizará el boss para disparar
{

    if(ActEsc<0)//si el ActEsc diera negativo, lo reemplaza por 0 para evitar errores
    {
        ActEsc==0;
    }
    if(cont==ActEsc)//Si el contador es igual al ActEsc se activa el escudo
    {
        escudo=true;
        balas[0].Disparar(balas,50);
    }
    if(cont==Disp)//El boss dispara cuando el contador es igual al Disp
    {
    balas[0].Disparar(balas,50);
    }
    if(cont==ActEsc*2){//Aquí se desactiva el escudo
        escudo=false;
        cont=0;
    }

}

void Boss::Colision(Player &player)//Aquí se revisa si el jugador choca con el boss
{
if (LimiteY<player.GetY() + player.GetBoundy()&&LimiteY > player.GetY() - player.GetBoundy()&&!escudo)
        {
            player.lives--;//Si es así se le quita vidas al jugador
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
