#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>


class Background
{
    public:
        Background();
        Background(float px, float py, float pvelX, float pvelY, int pwidth, int pheight, int pdirx, int pdiry, ALLEGRO_BITMAP *pimage);
        virtual ~Background();

        float x, y, velX, velY;
        int dirX, dirY;

        int width, height;

        ALLEGRO_BITMAP *image;


        void UpdateBackground();
        void DrawBackground();



    protected:

    private:
};

#endif // BACKGROUND_H
