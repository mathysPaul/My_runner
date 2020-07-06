/*
** EPITECH PROJECT, 2020
** event_game.c
** File description:
** event in game
*/

#include "my.h"

void player_move(global_t *global)
{
    if ((global->disp->event->type == sfEvtKeyPressed) &&
        (global->disp->event->key.code == sfKeyD))
        global->hero->move = 1;
    if ((global->disp->event->type == sfEvtKeyReleased) &&
        ((global->disp->event->key.code == sfKeyQ) ||
        (global->disp->event->key.code == sfKeyD)))
        global->hero->move = 0;
    if ((global->disp->event->type == sfEvtKeyPressed) &&
        (global->disp->event->key.code == sfKeyQ))
        global->hero->move = 2;
}

void player_jump_slide(global_t *global)
{
    if ((global->hero->jump != 1) &&
        (global->disp->event->type == sfEvtKeyPressed) &&
        (global->disp->event->key.code == sfKeyS))
        global->hero->slide = 1;
    if ((global->hero->jump == 0) &&
        (global->disp->event->type == sfEvtKeyPressed) &&
        ((global->disp->event->key.code == sfKeySpace) ||
        (global->disp->event->key.code == sfKeyZ))) {
        sfMusic_play(global->disp->jump);
        sfClock_restart(global->hero->clock_jump);
        global->hero->jump = 1;
        global->hero->slide = 0;
    }
    if ((global->disp->event->type == sfEvtKeyReleased) &&
        (global->disp->event->key.code == sfKeyS))
        global->hero->slide = 0;
}
