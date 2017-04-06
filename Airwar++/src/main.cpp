#include "main.h"
#include<allegro5/allegro.h>
#include<allegro5/allegro_native_dialog.h>
#include <iostream>
#include<allegro5/allegro_ttf.h>
#include<allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>


using namespace std;

int main(){

    const float FPS = 60.0;

    enum Direction {UP, DOWN, LEFT, RIGHT};

     if(!al_init()){
        al_show_native_message_box(NULL, NULL, NULL, "Could not initialize Allegro 5", NULL, NULL);
        return -1;
    }

    al_set_new_display_flags(ALLEGRO_WINDOWED);
    ALLEGRO_DISPLAY *display = al_create_display(800,600);
    al_set_window_position(display,200,200);
    al_set_window_title(display, "AIRWAR++");

    if(!display){
        al_show_native_message_box(display, "Sample Title", "Display Setting" , "Could not create window", NULL, NULL);
        return -1;
    }


    // Dibujar texto-------------------------------------------
    /*al_init_font_addon();
    al_init_ttf_addon();

    ALLEGRO_FONT *font = al_load_font("SHPinscher-Regular.otf",36, NULL);
    al_draw_text(font, al_map_rgb(44,117,255), 800/2 , 600/2, ALLEGRO_ALIGN_CENTER, "AIRWAR 1234567898");

    */

    bool done = false, draw = true;
    int x= 10 , y = 10;
    int Speed = 5;
    int dir = DOWN;

    al_init_primitives_addon();
    al_install_keyboard();


    ALLEGRO_TIMER *timer = al_create_timer(1.0/FPS);
    ALLEGRO_EVENT_QUEUE *eventQueue = al_create_event_queue();

    al_register_event_source(eventQueue, al_get_keyboard_event_source());
    al_register_event_source(eventQueue, al_get_timer_event_source(timer));


    al_start_timer(timer);




    while(!done){

        ALLEGRO_EVENT events;
        al_wait_for_event(eventQueue, &events);

        if(events.type == ALLEGRO_EVENT_KEY_DOWN){
            switch(events.keyboard.keycode){
            case ALLEGRO_KEY_DOWN:
                dir = DOWN;
                break;
            case ALLEGRO_KEY_UP:
                dir = UP;
                break;
            case ALLEGRO_KEY_RIGHT:
                dir = RIGHT;
                break;
            case ALLEGRO_KEY_LEFT:
                dir = LEFT;
                break;
            case ALLEGRO_KEY_ESCAPE:
                done = true;
                break;

            }
        }

        if (events.type == ALLEGRO_EVENT_TIMER){
            switch(dir){
                case DOWN:
                    y += Speed;
                    break;
                case UP:
                    y -= Speed;
                    break;
                case RIGHT:
                    x += Speed;
                    break;
                case LEFT:
                    x -= Speed;
                    break;
            }
            draw = true;
        }

        if (draw){

            al_draw_filled_rectangle(x, y, x+20, y+20,  al_map_rgb(255,98,100));
            al_flip_display();
            al_clear_to_color(al_map_rgb(0,0,0));


        }

    }







    al_destroy_event_queue(eventQueue);
    //al_destroy_font(font);        destruye la fuente de texto
    al_destroy_display(display);

    return 0;
}
