#include "Enemy.h"
#include "objects.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>


Enemy::Enemy()
{
    explode = false;
}

Enemy::~Enemy()
{

}



void Enemy::UpdateEnemy()
{
    if (explode == true)
    {

        if(++frameCount>= frameDelay)
            {
                curFrame += 1;
                if (curFrame ==1) al_play_sample(expsound, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);

                if(curFrame >= maxFrame)
                {
                    curFrame =0;

                    live = false;
                    explode = false;


                    speed = 4;
                }
                frameCount = 0;

            }
    }
    y+= speed;
}

void Enemy::DrawEnemy()
{
    if(explode == true)
    {
        speed = 0;
        int fx = (curFrame) * eframeWidth;


        al_draw_bitmap_region(expimage, fx, 0, eframeWidth, eframeHeight, x+20 - eframeWidth/2, y+10 - eframeHeight/2, 0);

    }
    else
        al_draw_bitmap(image, x, y, 0);

}


void Enemy::SpawnEnemy()
{

}

void Enemy::SetID(int pid)
{
    ID = pid;
}



void Enemy::SetX(int px)
{
    x = px;
}


void Enemy::SetY(int py)
{
    y = py;
}


void Enemy::SetSpeed(int pspeed)
{
    speed = pspeed;
}

void Enemy::SetLive(bool plive)
{
    live = plive;
}

void Enemy::SetBoundx(int px)
{
    boundx = px;
}

void Enemy::SetBoundy(int py)
{
    boundy = py;
}

void Enemy::SetImage(ALLEGRO_BITMAP *pimage, ALLEGRO_BITMAP *pexpimage)
{
    image = pimage;
    expimage = pexpimage;
}



int Enemy::GetID()
{
    return ID;
}
int Enemy::GetX()
{
    return x;
}
int Enemy::GetY()
{
    return y;
}
int Enemy::GetSpeed()
{
    return speed;
}
bool Enemy::GetLive()
{
    return live;
}
int Enemy::GetBoundx()
{
    return boundx;
}
int Enemy::GetBoundy()
{
    return boundy;
}

