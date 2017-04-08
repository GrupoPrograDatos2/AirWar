#ifndef PLAYER_H
#define PLAYER_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include <string>

using namespace std;



class Player
{
    public:
        Player(string, ALLEGRO_BITMAP *pimage);

        void Draw();
        void MoveUp();
        void MoveDown();
        void MoveLeft();
        void MoveRight();

        int GetY();
        int GetX();
        int GetBoundx();
        int GetBoundy();
        void SetLives(int plives);
        int GetLives();

        int lives;
        int score;

        int maxFrame;
        int curFrame;
        int frameCount;
        int frameDelay;
        int frameWidth;
        int frameHeight;
        int animationColumns;
        int animationDirection;

        int animationRow;

        ALLEGRO_BITMAP *image;


        ~Player();

    protected:


    private:
        string ID;
        int x, y, speed;
        int boundx, boundy;


};

#endif // PLAYER_H
