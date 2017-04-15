#ifndef PLAYER_H
#define PLAYER_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "allegro5/allegro_image.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#include <string>

using namespace std;



class Player
{
    public:
        Player(string id, ALLEGRO_BITMAP *pimage, ALLEGRO_BITMAP *pexpimage, ALLEGRO_SAMPLE *pexpsound);

        void Draw();
        void MoveLeft();
        void MoveRight();

        int GetY();
        int GetX();
        int GetBoundx();
        int GetBoundy();
        void SetLives(int plives);
        int GetLives();
        void Update();

        int lives;
        int score;

        int frameWidth;
        int frameHeight;

        int maxFrame;
        int curFrame;
        int frameDelay;
        int frameCount;
        int eframeHeight;
        int eframeWidth;

        bool escudo;
        bool laser;
        bool misiles;

        ALLEGRO_BITMAP *image;
        ALLEGRO_BITMAP *expimage;
        ALLEGRO_SAMPLE *expsound;
        bool live;


        ~Player();

    protected:


    private:
        string ID;
        int x, y, speed;
        int boundx, boundy;


};

#endif // PLAYER_H
