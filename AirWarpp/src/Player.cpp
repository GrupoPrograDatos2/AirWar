#include "Player.h"
#include "objects.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

Player::Player(string id, ALLEGRO_BITMAP *pimage, ALLEGRO_BITMAP *pexpimage, ALLEGRO_SAMPLE *pexpsound) //Constructor
{

    live = true;
    score = 0;
    x = WIDTH/2;
    y = HEIGHT-50;
    lives = 3;
    speed = 4;
    boundx = al_get_bitmap_width(pimage);
    boundy = al_get_bitmap_height(pimage);



    image = pimage;

    frameWidth = al_get_bitmap_width(pimage);
    frameHeight = al_get_bitmap_height(pimage);


    expimage = pexpimage;

    expsound = pexpsound;

    eframeWidth = 100;
    eframeHeight = 100;
    maxFrame = 36;
    curFrame = 0;
    frameCount = 0;
    frameDelay = 1;


}

Player::~Player() //Destructor
{

}


void Player::Draw()
{
    if (live == true)
    {
        if(lives <=0)
        {
            speed = 0;
            int fx = (curFrame) * eframeWidth;


            al_draw_bitmap_region(expimage, fx, 0, eframeWidth, eframeHeight, x+30 - eframeWidth/2, y+30 - eframeHeight/2, 0);

            Update();
        }

        else
        {
            al_draw_bitmap(image, x, y, 0);
        }
    }

}

void Player::Update()
{
    if (live)
        {
            if(++frameCount>= frameDelay)
            {
                curFrame += 1;

                if (curFrame ==1) al_play_sample(expsound, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);

                if(curFrame >= maxFrame)
                {
                    curFrame =0;
                    live = false;
                }
                frameCount = 0;

            }
        }
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
    if(x > WIDTH-65)
        x = WIDTH-65;
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
