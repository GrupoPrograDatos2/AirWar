#include "Enemy.h"
#include "objects.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

Enemy::Enemy()
{

}

Enemy::~Enemy()
{

}



void Enemy::UpdateEnemy()
{
    y+= speed;
}

void Enemy::DrawEnemy()
{
    al_draw_filled_circle(x, y, 20, al_map_rgb(255,0,0));

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

