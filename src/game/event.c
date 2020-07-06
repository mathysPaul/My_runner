/*
** EPITECH PROJECT, 2019
** event
** File description:
** event
*/

#include <stdio.h>
#include "my.h"

void close_window(global_t *global)
{
    static int check = 0;

    if ((global->disp->event->type == sfEvtClosed) ||
        ((global->disp->event->type == sfEvtKeyPressed) &&
        (global->disp->event->key.code == sfKeyEscape))) {
        sfRenderWindow_close(global->disp->window);
        if (check == 0) {
            check_high_score(global);
            check = 1;
        }
    }
}

void volume_music(global_t *global)
{
    static float volume = 40;

    if ((global->disp->event->type == sfEvtKeyPressed) &&
        (global->disp->event->key.code == sfKeyP) &&
        (volume <= 95))
        volume += 5;
    if ((global->disp->event->type == sfEvtKeyPressed) &&
        (global->disp->event->key.code == sfKeyM) &&
        (volume >= 5))
        volume -= 5;
    sfMusic_setVolume(global->disp->music, volume);
    sfMusic_setVolume(global->disp->jump, volume + 20);
}

void button_menu(global_t *global)
{
    int x = 0;
    int y = 0;
    sfVector2u s = sfRenderWindow_getSize(global->disp->window);

    if ((global->disp->event->type == sfEvtMouseButtonPressed) &&
        (global->disp->check_menu == 0) && (global->disp->skin != 0)) {
        x = global->disp->event->mouseButton.x;
        y = global->disp->event->mouseButton.y;
        if ((s.x * 0.965 > x) && (x > s.x * 0.77) &&
            (s.y * 0.98 > y) && (y > s.y * 0.83))
            global->disp->check_menu = 1;
    }
}

void skin_menu(global_t *global)
{
    if ((global->disp->menu == 1) &&
        (global->disp->event->type == sfEvtKeyPressed) &&
        ((global->disp->event->key.code == sfKeyNum1) ||
        (global->disp->event->key.code == sfKeyNumpad1)))
        global->disp->skin = 1;
    if ((global->disp->menu == 1) &&
        (global->disp->event->type == sfEvtKeyPressed) &&
        ((global->disp->event->key.code == sfKeyNum2) ||
        (global->disp->event->key.code == sfKeyNumpad2)))
        global->disp->skin = 2;
}

void event(global_t *global)
{
    skin_menu(global);
    if (global->disp->menu == 0) {
        volume_music(global);
        player_move(global);
        player_jump_slide(global);
    }
    button_menu(global);
    close_window(global);
}
