#include "Player.h"
#include "objects.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

Player::Player(string id, ALLEGRO_BITMAP *pimage) //Constructor
{
    score = 0;
    x = WIDTH/2;
    y = HEIGHT-40;
    lives = 3;
    speed = 4;
    boundx = 6;
    boundy = 7;


    maxFrame = 3;
    curFrame = 0;
    frameCount = 0;
    frameDelay = 50;
    frameWidth = 75;
    frameHeight = 125;
    animationColumns = 3;
    animationDirection = 1;

    animationRow = 1;

    image = pimage;

}

Player::~Player() //Destructor
{

}


void Player::Draw()
{

  //al_draw_filled_rectangle(x, y, x+20, y+20, al_map_rgb(0,255,0));

  int fx = (curFrame % animationColumns) * frameWidth;
  int fy = (animationRow * frameHeight-50)-74;

  al_draw_bitmap_region(image, fx, fy, frameWidth, frameHeight, x - frameWidth/2, (y - frameHeight/2), 0);
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
