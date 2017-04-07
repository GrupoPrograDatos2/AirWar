#include "EnemyList.h"
#include "objects.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>

#include "Enemy.h"

EnemyList::EnemyList(Enemy enemies[], int size)
{
    for(int i =0; i < size; i++)
    {
        enemies[i].SetID(ENEMY);
        enemies[i].SetLive(false);
        enemies[i].SetSpeed(4);
        enemies[i].SetBoundx(18);
        enemies[i].SetBoundy(18);
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
       if (enemies[i].GetLive())
       {
           if (enemies[i].GetX() - enemies[i].GetBoundx() < player.GetX() + player.GetBoundx() &&
               enemies[i].GetX() + enemies[i].GetBoundx() > player.GetX() - player.GetBoundx() &&
               enemies[i].GetY() - enemies[i].GetBoundy() < player.GetY() + player.GetBoundy() &&
               enemies[i].GetY() + enemies[i].GetBoundy() > player.GetY() - player.GetBoundy())
           {
               player.lives--;
               enemies[i].SetLive(false);
               std::cout << player.lives;
           }
       }
   }
}
