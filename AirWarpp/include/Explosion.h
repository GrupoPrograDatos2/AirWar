#ifndef EXPLOSION_H
#define EXPLOSION_H


#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"



class Explosion
{
    public:
        Explosion(Explosion explosions[], int size, ALLEGRO_BITMAP *pimage);

        Explosion();
        virtual ~Explosion();
        float x, y, velX, velY;
        int dirX, dirY;

        int maxFrame;
        int curFrame;
        int frameCount;
        int frameDelay;
        int frameWidth;
        int frameHeight;
        int animationColumns;
        int animationDirection;
        bool live;

        ALLEGRO_BITMAP *image;

        void Update(Explosion explosions[], int size);
        void Draw(Explosion explosions[], int size);
        void Start(Explosion explosions[], int size, int x, int y);

    protected:

    private:
};

#endif // SPRITE_H
