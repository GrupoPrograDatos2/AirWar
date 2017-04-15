#include "main.h"
#include "objects.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include "allegro5/allegro_image.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "EnemyList.h"
#include "Background.h"


//Variables Globales

enum KEYS{UP, DOWN, LEFT, RIGHT, SPACE};
enum STATE{MENU, PLAYING, GAMEOVER};
bool keys[5] = {false, false, false, false, false};


void ChangeState(int &state, int newState);


int main(void)
{
    //primitive variables
    bool done = false;
    bool redraw = true;
    const int FPS = 60;
    int state = -1;



    //Allegro variables
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *eventQueue;
    ALLEGRO_TIMER *timer;
    ALLEGRO_FONT *font18;
    ALLEGRO_BITMAP *playerimage;
    ALLEGRO_BITMAP *enemyimage;
    ALLEGRO_BITMAP *expimage;
    ALLEGRO_BITMAP *bgimage;
    ALLEGRO_BITMAP *mgimage;
    ALLEGRO_BITMAP *fgimage;
    ALLEGRO_BITMAP *menuimg = NULL;
    ALLEGRO_BITMAP *gameoverimg = NULL;
    ALLEGRO_SAMPLE *shootsound;
    ALLEGRO_SAMPLE *expsound;






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
    al_install_audio();
    al_init_acodec_addon();


    bgimage = al_load_bitmap("starBG.png");
    al_convert_mask_to_alpha(bgimage, al_map_rgb(255,255,255));

    fgimage = al_load_bitmap("starFG.png");
    al_convert_mask_to_alpha(fgimage, al_map_rgb(255,255,255));

    mgimage = al_load_bitmap("starMG.png");
    al_convert_mask_to_alpha(mgimage, al_map_rgb(255,255,255));


    playerimage = al_load_bitmap("player.png");
    al_convert_mask_to_alpha(playerimage, al_map_rgb(255,255,255));

    enemyimage = al_load_bitmap("enemy.png");
    al_convert_mask_to_alpha(enemyimage, al_map_rgb(255,255,255));

    expimage = al_load_bitmap("explosion.png");
    al_convert_mask_to_alpha(expimage, al_map_rgb(255,255,255));

    menuimg = al_load_bitmap("menu.png");
    gameoverimg = al_load_bitmap("gameover.png");


    al_reserve_samples(10);

    shootsound = al_load_sample("shoot.wav");
    expsound = al_load_sample("explosion.wav");



    eventQueue = al_create_event_queue();
    timer = al_create_timer(1.0/FPS);

        //object variables




    ChangeState(state , MENU);


    Background BG(0, 0, 0, 1, 600,800, 1, 1, bgimage);
    Background MG(0, 0, 0, 3, 600,1600, 1, 1, mgimage);
    Background FG(0, 0, 0, 5, 600,800, 1, 1, fgimage);

    Bullet bullets[5];
    Bullet bullet(bullets, NUM_BULLETS);
    Enemy enemies[8];
    EnemyList enemylist(enemies, NUM_ENEMIES, enemyimage, expimage, expsound);


    Player player("Jugador1", playerimage, expimage, expsound);


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


            if (state==MENU)
            {

            }
            else if(state == PLAYING)
            {

                BG.UpdateBackground();
                MG.UpdateBackground();
                FG.UpdateBackground();
                bullet.UpdateBullet(bullets, NUM_BULLETS);
                enemylist.SpawnEnemy(enemies, NUM_ENEMIES);
                enemylist.UpdateEnemy(enemies, NUM_ENEMIES);
                bullet.CollideBullet(bullets, NUM_BULLETS, enemies, NUM_ENEMIES, player);
                enemylist.CollideEnemy(enemies, NUM_ENEMIES, player);


                if (player.live == false)
                {
                    ChangeState(state, GAMEOVER);
                }
            }
            else if(state == GAMEOVER)
            {

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

                if(state == MENU)
                    ChangeState(state, PLAYING);

                if(state == PLAYING)
                {
                    bullet.FireBullet(bullets, NUM_BULLETS, player);

                    if (player.live)
                        al_play_sample(shootsound,1,0,1.5, ALLEGRO_PLAYMODE_ONCE, NULL);


                }

                if (state == GAMEOVER){
                    player.live = true;
                    player.SetLives(3);

                    ChangeState(state, MENU);
                }

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


            if (state==MENU)
            {
                al_draw_bitmap(menuimg,0,0,0);
            }
            else if(state == PLAYING)
            {
                BG.DrawBackground();
                MG.DrawBackground();
                FG.DrawBackground();
                player.Draw();
                bullet.DrawBullet(bullets, NUM_BULLETS);
                enemylist.DrawEnemy(enemies, NUM_ENEMIES);


                al_draw_textf(font18, al_map_rgb(0,255,255), 5, 5, 0, "Player has %i lives Left. Score %i", player.lives, player.score);

            }
            else if(state == GAMEOVER)
            {
                al_draw_bitmap(gameoverimg,0,0,0);
                al_draw_textf(font18, al_map_rgb(0,255,255), WIDTH/2, HEIGHT/2, ALLEGRO_ALIGN_CENTER, "Final Score %i", player.score);

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
    al_destroy_sample(shootsound);
    al_destroy_display(display);
    al_destroy_event_queue(eventQueue);
    al_destroy_bitmap(bgimage);
    al_destroy_bitmap(mgimage);
    al_destroy_bitmap(fgimage);
    al_destroy_bitmap(gameoverimg);
    al_destroy_bitmap(menuimg);
    //al_destroy_timer(timer);
    al_destroy_bitmap(playerimage);
    al_destroy_bitmap(enemyimage);
    al_destroy_bitmap(expimage);
    //al_destroy_font(font);



    return 0;
}

void ChangeState(int &state, int newState)
{
    if (state==MENU)
    {

    }
    else if(state == PLAYING)
    {

    }
    else if(state == GAMEOVER)
    {

    }

    state = newState;

    if (state==MENU)
    {

    }
    else if(state == PLAYING)
    {

       /* ALLEGRO_BITMAP *playerimage;
        ALLEGRO_BITMAP *enemyimage;
        ALLEGRO_BITMAP *expimage;
        ALLEGRO_BITMAP *bgimage;
        ALLEGRO_BITMAP *menuimg = NULL;
        ALLEGRO_BITMAP *gameoverimg = NULL;
        ALLEGRO_SAMPLE *shootsound;
        ALLEGRO_SAMPLE *expsound;

        bgimage = al_load_bitmap("starBG.png");
        al_convert_mask_to_alpha(bgimage, al_map_rgb(255,255,255));

        playerimage = al_load_bitmap("player.png");
        al_convert_mask_to_alpha(playerimage, al_map_rgb(255,255,255));

        enemyimage = al_load_bitmap("enemy.png");
        al_convert_mask_to_alpha(enemyimage, al_map_rgb(255,255,255));

        expimage = al_load_bitmap("explosion.png");
        al_convert_mask_to_alpha(expimage, al_map_rgb(255,255,255));

        menuimg = al_load_bitmap("menu.png");
        gameoverimg = al_load_bitmap("gameover.png");


        Bullet bullets[5];
        Bullet bullet(bullets, NUM_BULLETS);
        Enemy enemies[8];
        EnemyList enemylist(enemies, NUM_ENEMIES, enemyimage, expimage, expsound);
        Player player("Jugador1", playerimage, expimage, expsound);

        al_reserve_samples(10);

        shootsound = al_load_sample("shoot.wav");
        expsound = al_load_sample("explosion.wav");*/

    }
    else if(state == GAMEOVER)
    {

    }

}
