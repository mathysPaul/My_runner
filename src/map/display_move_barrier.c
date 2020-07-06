/*
** EPITECH PROJECT, 2020
** display_move_barrier.c
** File description:
** display and move the barrier on the screen
*/

#include "my.h"

int find_last_barrier(global_t *global)
{
    int index = 0;
    int x = 0;
    int last_barrier = 0;

    while (global->map->sprite_barrier[index] != NULL) {
        if (BARRIER_POS[index + 1].x > x) {
            last_barrier = index;
            x = BARRIER_POS[index + 1].x;
        }
        index++;
    }
    return (last_barrier);
}

void position_barrier(global_t *global)
{
    int index = find_last_barrier(global);
    sfVector2f pos;

    if (sfSprite_getPosition(global->map->sprite_barrier[index]).x <= -1920) {
        index = 0;
        global->disp->win = 1;
        while (global->map->sprite_barrier[index] != NULL) {
            pos =  global->map->position_barrier[index + 1];
            sfSprite_setPosition(global->map->sprite_barrier[index], pos);
            index++;
        }
    }
}

void display_barrier(global_t *global)
{
    int index = 0;

    if (global->map->sprite_barrier == NULL)
        return;
    while (global->map->sprite_barrier[index] != NULL) {
        sfSprite_move(global->map->sprite_barrier[index],
        global->map->position_barrier[0]);
        sfRenderWindow_drawSprite(global->disp->window,
        global->map->sprite_barrier[index++], NULL);
    }
}
