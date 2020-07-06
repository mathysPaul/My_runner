/*
** EPITECH PROJECT, 2020
** infinity_map.c
** File description:
** an infinity map
*/

#include "my.h"

void element_pos(global_t *global, int nb_barrier, int nb_enemy)
{
    int col = 0;
    int row = 0;
    int barrier = 0;
    int enemy = 0;

    while (barrier <= nb_barrier) {
        col = rand() % 30;
        row = (rand() % 3) + 1;
        BARRIER_POS[barrier].x = col * (WIDTH_SCREEN / 24) + 1920;
        BARRIER_POS[barrier++].y = HEIGHT_SCREEN - (80 * row);
    }
    while (enemy <= nb_enemy) {
        col = rand() % 30;
        row = (rand() % 4) + 1;
        ENEMY_POS[enemy].x = col * (WIDTH_SCREEN / 24) + 1920;
        ENEMY_POS[enemy++].y = HEIGHT_SCREEN - (80 * row);
    }
}

int infinity_map(global_t *global)
{
    int nb_barrier;
    int nb_enemy;

    srand(time(0));
    nb_barrier = (rand() % 42) + 1;
    nb_enemy = (rand() % 22) + 2;
    BARRIER_POS = malloc(sizeof(sfVector2f *) * (nb_barrier + 1));
    ENEMY_POS = malloc(sizeof(sfVector2f *) * (nb_enemy + 1));
    if ((BARRIER_POS == NULL) || (ENEMY_POS == NULL))
        return (84);
    element_pos(global, nb_barrier, nb_enemy);
    BARRIER_POS[0].x = -22;
    BARRIER_POS[0].y = 0;
    ENEMY_POS[0].x = -24;
    ENEMY_POS[0].y = 0;
    if (set_sprite(global, nb_barrier, nb_enemy) == 84)
        return (84);
    global->map->game_time = sfClock_create();
    return (0);
}

