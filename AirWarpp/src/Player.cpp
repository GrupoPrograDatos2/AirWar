#include "Player.h"
#include "objects.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

Player::Player(string id) //Constructor
{
    score = 0;
    x = WIDTH/2;
    y = HEIGHT-40;
    lives = 3;
    speed = 7;
    boundx = 6;
    boundy = 7;

}

Player::~Player() //Destructor
{

}


void Player::Draw()
{

  al_draw_filled_rectangle(x, y, x+20, y+20, al_map_rgb(0,255,0));
}

void Player::MoveLeft()
{
    x -= speed;
    if(x < 0)
        x = 0;
}

void Player::MoveRight()
{
    x += speed;
    if(x > WIDTH-20)
        x = WIDTH-20;
}



int Player::GetY()
{
    return y;
}

int Player::GetX()
{
    return x;
}

int Player::GetBoundx()
{
    return boundx;
}
int Player::GetBoundy()
{
    return boundy;
}

void Player::SetLives(int plives)
{
    lives = plives;
}

int Player::GetLives()
{
    return lives;
}
