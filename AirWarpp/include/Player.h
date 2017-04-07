#ifndef PLAYER_H
#define PLAYER_H


#include <string>

using namespace std;



class Player
{
    public:
        Player(string);

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


        ~Player();

    protected:


    private:
        string ID;
        int x, y, speed;
        int boundx, boundy;


};

#endif // PLAYER_H