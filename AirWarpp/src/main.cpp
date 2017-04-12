#include "main.h"
#include "objects.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include<allegro5/allegro_ttf.h>
#include<allegro5/allegro_font.h>
#include "allegro5/allegro_image.h"

#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "EnemyList.h"
#include "Boss.h"

//Variables Globales

enum KEYS{UP, DOWN, LEFT, RIGHT, SPACE};
bool keys[5] = {false, false, false, false, false};

//prototypes


int main(void)
{
    //primitive variables
    bool done = false;
    bool redraw = true;
    const int FPS = 60;
    bool isGameOver = false;


    //object variables


    Bullet bullets[5];
    Bullet bullet(bullets, NUM_BULLETS);
    Enemy enemies[7];
    EnemyList enemylist(enemies, NUM_ENEMIES);


    //Allegro variables
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *eventQueue;
    ALLEGRO_TIMER *timer;
    ALLEGRO_FONT *font18;
    ALLEGRO_BITMAP *playerImage;

    //Initialization Functions

    if(!al_init()){
        return -1;
    }


    display = al_create_display(WIDTH, HEIGHT);

    if(!display){
        return -1;
    }

    srand(time(NULL));

    al_init_primitives_addon();
    al_install_keyboard();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();


    eventQueue = al_create_event_queue();
    timer = al_create_timer(1.0/FPS);

    playerImage = al_load_bitmap("player.png");
    al_convert_mask_to_alpha(playerImage, al_map_rgb(255,0,255));


    Player player("Jugador1", playerImage);


    font18 = al_load_font("SHPinscher-Regular.otf", 24, 0);


    al_register_event_source(eventQueue, al_get_keyboard_event_source());
    al_register_event_source(eventQueue, al_get_timer_event_source(timer));
    al_register_event_source(eventQueue, al_get_display_event_source(display));

    al_start_timer(timer);

    while (!done)
    {
        ALLEGRO_EVENT event;
        al_wait_for_event(eventQueue, &event);

        if (event.type == ALLEGRO_EVENT_TIMER)
        {
            redraw = true;
            if (keys[RIGHT])
                player.MoveRight();
            if (keys[LEFT])
                player.MoveLeft();

            if(!isGameOver)
            {
                bullet.UpdateBullet(bullets, NUM_BULLETS);
                enemylist.SpawnEnemy(enemies, NUM_ENEMIES);
                enemylist.UpdateEnemy(enemies, NUM_ENEMIES);
                bullet.CollideBullet(bullets, NUM_BULLETS, enemies, NUM_ENEMIES, player);
                enemylist.CollideEnemy(enemies, NUM_ENEMIES, player);

                if (player.lives <=0)
                {
                    isGameOver = true;
                }

            }


        }
        else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                done = true;
            }

        if (event.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            switch(event.keyboard.keycode)
            {
            case ALLEGRO_KEY_ESCAPE:
                done = true;
                break;
            case ALLEGRO_KEY_RIGHT:
                keys[RIGHT] = true;
                break;
            case ALLEGRO_KEY_LEFT:
                keys[LEFT] = true;
                break;
            case ALLEGRO_KEY_SPACE:
                keys[SPACE] = true;
                bullet.FireBullet(bullets, NUM_BULLETS, player);
                break;
            }
        }
        else if (event.type == ALLEGRO_EVENT_KEY_UP)
        {
           switch(event.keyboard.keycode)
            {
            case ALLEGRO_KEY_ESCAPE:
                done = true;
                break;
            case ALLEGRO_KEY_RIGHT:
                keys[RIGHT] = false;
                break;
            case ALLEGRO_KEY_LEFT:
                keys[LEFT] = false;
                break;
            case ALLEGRO_KEY_SPACE:
                keys[SPACE] = false;
                break;
            }
        }



        if (redraw && al_is_event_queue_empty(eventQueue))
        {
            redraw = false;

            if(!isGameOver)
            {
                player.Draw();
                bullet.DrawBullet(bullets, NUM_BULLETS);
                enemylist.DrawEnemy(enemies, NUM_ENEMIES);

                al_draw_textf(font18, al_map_rgb(0,255,255), 5, 5, 0, "Player has %i lives Left. Score %i", player.lives, player.score);

            }
            else
            {
                al_draw_text(font18, al_map_rgb(0,255,255), WIDTH/2, HEIGHT/2, ALLEGRO_ALIGN_CENTER, "GAME OVER");
            }
            al_flip_display();
            al_clear_to_color(al_map_rgb(0,0,0));
        }

    }

    //destroy elements

    al_destroy_display(display);
    al_destroy_event_queue(eventQueue);
    //al_destroy_timer(timer);
    al_destroy_bitmap(playerImage);
    //al_destroy_font(font);


    return 0;
}
