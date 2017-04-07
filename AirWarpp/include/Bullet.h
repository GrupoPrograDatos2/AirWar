#ifndef BULLET_H
#define BULLET_H
#include "Player.h"
#include "Enemy.h"


class Bullet
{
    public:
        Bullet(Bullet bullet[], int size);
        Bullet();

        void DrawBullet(Bullet bullet[], int size);
        void FireBullet(Bullet bullet[], int size, Player player);
        void UpdateBullet(Bullet bullet[], int size);
        void CollideBullet(Bullet bullet[], int bSize, Enemy enemies[], int eSize, Player &player);

        ~Bullet();

    protected:

    private:
        int ID;
        int x, y;
        bool live;
        int speed;
};

#endif // BULLET_H
