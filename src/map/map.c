/*
** EPITECH PROJECT, 2020
** map.c
** File description:
** map game
*/

#include "my.h"

void map(global_t *global)
{
    if ((global->map->sprite_enemy != NULL) &&
        (global->map->sprite_enemy[0] != NULL)) {
        position_enemy(global);
        position_enemy_hit(global);
    }
    if ((global->map->sprite_barrier != NULL) &&
        (global->map->sprite_barrier[0] != NULL))
        position_barrier(global);
    display_enemy(global);
    display_enemy_hit(global);
    display_barrier(global);
}
