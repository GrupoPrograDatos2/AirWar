#ifndef ENEMYLIST_H
#define ENEMYLIST_H

#include "Enemy.h"
#include "Player.h"

class EnemyList
{
    public:
        EnemyList(Enemy enemies[], int size);
        virtual ~EnemyList();

        void DrawEnemy(Enemy enemies[], int size);
        void UpdateEnemy(Enemy enemies[], int size);
        void SpawnEnemy(Enemy enemies[], int size);
        void CollideEnemy(Enemy enemies[],int eSize, Player &player);

    protected:

    private:
};

#endif // ENEMYLIST_H
