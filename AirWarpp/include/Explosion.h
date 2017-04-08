#ifndef EXPLOSION_H
#define EXPLOSION_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

class Explosion
{
    public:
        Explosion();
        virtual ~Explosion();

        int x, y;
        bool live;

        int maxFrame;
        int curFrame;
        int frameCount;
        int frameDelay;
        int frameWidth;
        int frameHeight;
        int animationColumns;
        int animationDirection;

        ALLEGRO_BITMAP *image;

    protected:

    private:
};

#endif // EXPLOSION_H
