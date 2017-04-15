#include "EnemyList.h"
#include "objects.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "allegro5/allegro_image.h"
#include <iostream>

#include "Enemy.h"

EnemyList::EnemyList(Enemy enemies[], int size, ALLEGRO_BITMAP *pimage, ALLEGRO_BITMAP *pexpimage, ALLEGRO_SAMPLE *pexpsound)
{
    for(int i =0; i < size; i++)
    {
        enemies[i].SetID(ENEMY);
        enemies[i].SetLive(false);
        enemies[i].explode = false;
        enemies[i].SetSpeed(4);
        enemies[i].SetBoundx(al_get_bitmap_width(pimage));
        enemies[i].SetBoundy(al_get_bitmap_height(pimage));
        enemies[i].SetImage(pimage, pexpimage);
        enemies[i].frameCount = 0;
        enemies[i].curFrame = 0;
        enemies[i].frameDelay = 1;
        enemies[i].eframeHeight = 100;
        enemies[i].eframeWidth = 100;
        enemies[i].maxFrame = 36;
        enemies[i].expsound = pexpsound;

    }
}

EnemyList::~EnemyList()
{
    //dtor
}



void EnemyList::UpdateEnemy(Enemy enemies[], int size)
{
    for(int i =0; i<size; i++)
    {
        if(enemies[i].GetLive()==true)
        {
            enemies[i].UpdateEnemy();

            if(enemies[i].GetY() > HEIGHT){
                enemies[i].SetLive(false);
            }

        }
    }
}

void EnemyList::DrawEnemy(Enemy enemies[], int size)
{
    for(int i =0; i<size; i++)
    {
        if (enemies[i].GetLive())
        {
            enemies[i].DrawEnemy();
        }
    }
}


void EnemyList::SpawnEnemy(Enemy enemies[], int size)
{
    for(int i =0; i<size; i++)
    {
        if(!enemies[i].GetLive())
        {
            if(rand() % 500 ==0)
            {
                enemies[i].SetLive(true);
                enemies[i].SetX(20+rand() % (WIDTH -20));
                enemies[i].SetY(20);

                break;
            }
        }
    }
}


void EnemyList::CollideEnemy(Enemy enemies[], int eSize, Player &player)
{
   for(int i =0; i<eSize; i++)
   {
       if (enemies[i].GetLive() && enemies[i].explode==false)
       {
           if (enemies[i].GetX() - enemies[i].GetBoundx() < player.GetX() + player.GetBoundx() -50 &&
               enemies[i].GetX() + enemies[i].GetBoundx() > player.GetX() - player.GetBoundx() +60 &&
               enemies[i].GetY() - enemies[i].GetBoundy() < player.GetY() + player.GetBoundy() &&
               enemies[i].GetY() + enemies[i].GetBoundy()-60 > player.GetY() - player.GetBoundy())
           {
               player.lives--;
               enemies[i].explode = true;

           }
       }
   }
}
