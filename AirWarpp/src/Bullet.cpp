#include "Bullet.h"
#include "objects.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>


Bullet::Bullet(Bullet bullet[], int size)
{
    for(int i = 0; i < size; i++){
        bullet[i].ID = BULLET;
        bullet[i].speed = 10;
        bullet[i].live = false;
    }
}

Bullet::~Bullet()
{

}
Bullet::Bullet(){}


void Bullet::DrawBullet(Bullet bullet[], int size)
{
    for(int i = 0; i < size; i++)
    {
        if (bullet[i].live)
            al_draw_filled_circle(bullet[i].x+10, bullet[i].y, 2, al_map_rgb(255,255,255));
    }
}

void Bullet::FireBullet(Bullet bullet[], int size, Player player)
{
    for(int i = 0; i < size; i++)
    {
        if (!bullet[i].live)
        {
            bullet[i].y = player.GetY()+10;
            bullet[i].x = player.GetX()+22;
            bullet[i].live = true;
            break;
        }
    }
}

void Bullet::UpdateBullet(Bullet bullet[], int size)
{
    for(int i = 0; i < size; i++)
    {
        if (bullet[i].live)
        {
            bullet[i].y -= bullet[i].speed;
            if (bullet[i].y < 0)
                bullet[i].live = false;

        }
    }
}



void Bullet::CollideBullet(Bullet bullet[], int bSize, Enemy enemies[], int eSize, Player &player /*Explosion explosions[], int exSize*/)
{
    for(int i = 0; i < bSize; i++)
    {
        if (bullet[i].live)
        {
            for (int j= 0; j< eSize; j++)
            {
                if (enemies[j].GetLive())
                {
                   if(bullet[i].y > (enemies[j].GetY() - enemies[j].GetBoundy()) &&
                      bullet[i].y < (enemies[j].GetY() + enemies[j].GetBoundy()) &&
                      bullet[i].x > (enemies[j].GetX() - enemies[j].GetBoundx()) &&
                      bullet[i].x < (enemies[j].GetX() + enemies[j].GetBoundx()))
                   {
                       bullet[i].live = false;
                       enemies[j].explode = true;

                       player.score++;



                   }

                }
            }
        }
    }
}

