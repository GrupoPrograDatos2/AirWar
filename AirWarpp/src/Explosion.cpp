#include "Explosion.h"
#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"


Explosion::Explosion()
{
    image = al_load_bitmap("explosion.png");
    al_convert_mask_to_alpha(image, al_map_rgb(255,255,255));
}

Explosion::Explosion(Explosion explosions[], int size, ALLEGRO_BITMAP *pimage)
{
    for(int i = 0; i < size; i++)
    {
      explosions[i].live = false;
      explosions[i].maxFrame = 36;
      explosions[i].curFrame=0;
      explosions[i].frameCount = 0;
      explosions[i].frameDelay = 1;
      explosions[i].frameWidth = 100;
      explosions[i].frameHeight = 100;

      explosions[i].image = pimage;

    }

}

Explosion::~Explosion()
{

}


void Explosion::Draw(Explosion explosions[], int size)
{
    for(int i = 0; i < size; i++)
    {
        if(explosions[i].live){
            int fx = (explosions[i].curFrame) * explosions[i].frameWidth;
            int fy = (100);

            al_draw_bitmap_region(explosions[i].image, fx, fy, explosions[i].frameWidth, explosions[i].frameHeight, explosions[i].x - explosions[i].frameWidth/2, explosions[i].y - explosions[i].frameHeight/2, 0);
        }
    }

}

void Explosion::Update(Explosion explosions[], int size)
{
    for(int i = 0; i < size; i++)
    {
        if (explosions[i].live)
        {
            if(++explosions[i].frameCount>= explosions[i].frameDelay)
            {
                explosions[i].curFrame += 1;

                if(explosions[i].curFrame >= explosions[i].maxFrame)
                {
                    explosions[i].curFrame =0;
                    explosions[i].live = false;
                }
                explosions[i].frameCount = 0;
            }
        }
    }

}

void Explosion::Start(Explosion explosions[], int size, int x, int y)
{
    for(int i = 0; i < size; i++)
    {
        if (!explosions[i].live)
        {
            explosions[i].live = true;
            explosions[i].x = x;
            explosions[i].y = y;
        }
    }

}
