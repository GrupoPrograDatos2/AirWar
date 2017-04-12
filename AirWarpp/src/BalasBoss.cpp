#include "BalasBoss.h"
#include "Player.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdint.h>

using namespace std;

BalasBoss::BalasBoss()
{
    //ctor
}

void BalasBoss::UpdateBullet(BalasBoss bullet[], int size)
{
    for(int i = 0; i < size; i++)
    {
        if (bullet[i].activa)
        {
            bullet[i].y -= bullet[i].velY;
            if (bullet[i].y < 0)
                bullet[i].activa = false;

        }
    }
}

void BalasBoss::DrawBullet(BalasBoss bullet[], int size)
{
    for(int i = 0; i < size; i++)
    {
        if (bullet[i].activa)
            al_draw_filled_circle(bullet[i].x+10, bullet[i].y, 2, al_map_rgb(255,255,255));
    }
}

void BalasBoss::ColisionB(BalasBoss bullet[], int size, Player &player)
{
    for(int i = 0; i < size; i++)
    {

        if (bullet[i].activa)
        {
            if (bullet[i].GetX() < player.GetX() + player.GetBoundx() &&
               bullet[i].GetX() > player.GetX() - player.GetBoundx() &&
               bullet[i].GetY() < player.GetY() + player.GetBoundy() &&
               bullet[i].GetY() > player.GetY() - player.GetBoundy())
           {
               player.lives--;

           }
        }
    }
}

void BalasBoss::Disparar(BalasBoss bullet[], int size)
{
    for(int i = 0; i < size; i++)
    {
        if (!bullet[i].activa)
        {
            bullet[i].activa = true;
            break;
        }
    }
}

int BalasBoss::GetY()
{
    return y;
}

int BalasBoss::GetX()
{
    return x;
}

BalasBoss::~BalasBoss()
{
    //dtor
}
