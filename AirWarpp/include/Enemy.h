#ifndef ENEMY_H
#define ENEMY_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "allegro5/allegro_image.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>


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
        void SetImage(ALLEGRO_BITMAP *pimage, ALLEGRO_BITMAP *pexpimage);

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
        int eframeWidth;
        int eframeHeight;

        bool explode;

        ALLEGRO_SAMPLE *expsound;
        ALLEGRO_BITMAP *image;
        ALLEGRO_BITMAP *expimage;

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
