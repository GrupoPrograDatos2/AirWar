#ifndef ENEMYLIST_H
#define ENEMYLIST_H

#include "Enemy.h"
#include "Player.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "allegro5/allegro_image.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

class EnemyList
{
    public:
        EnemyList(Enemy enemies[], int size, ALLEGRO_BITMAP *pimage, ALLEGRO_BITMAP *pexpimage, ALLEGRO_SAMPLE *pexpsound);
        virtual ~EnemyList();

        void DrawEnemy(Enemy enemies[], int size);
        void UpdateEnemy(Enemy enemies[], int size);
        void SpawnEnemy(Enemy enemies[], int size);
        void CollideEnemy(Enemy enemies[],int eSize, Player &player);

    protected:

    private:
};

#endif // ENEMYLIST_H
