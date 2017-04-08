#ifndef ENEMY_H
#define ENEMY_H


class Enemy
{
    public:
        Enemy();
        ~Enemy();

        void DrawEnemy();
        void UpdateEnemy();
        void SpawnEnemy();
        void SetID(int pid);
        void SetX(int px);
        void SetY(int py);
        void SetSpeed(int pspeed);
        void SetLive(bool plive);
        void SetBoundx(int x);
        void SetBoundy(int y);

        int GetID();
        int GetX();
        int GetY();
        int GetSpeed();
        bool GetLive();
        int GetBoundx();
        int GetBoundy();

        int maxFrame;
        int curFrame;
        int frameCount;
        int frameDelay;
        int frameWidth;
        int frameHeight;
        int animationColumns;
        int animationDirection;


    protected:

    private:
        int ID;
        int x, y;
        bool live;
        int speed;
        int boundx;
        int boundy;
};

#endif // ENEMY_H
