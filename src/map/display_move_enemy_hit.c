/*
** EPITECH PROJECT, 2020
** display_move_enemy.c
** File description:
** display and move the enemy
*/

#include "my.h"

int find_last_enemy_hit(global_t *global)
{
    int index = 0;
    int x = 0;
    int last_enemy = 0;

    while (global->map->sprite_enemy_hit[index] != NULL) {
        if (ENEMY_POS[index + 1].x > x) {
            last_enemy = index;
            x = ENEMY_POS[index + 1].x;
        }
        index++;
    }
    return (last_enemy);
}

void position_enemy_hit(global_t *global)
{
    int index = find_last_enemy_hit(global);
    sfVector2f pos;

    if (sfSprite_getPosition(global->map->sprite_enemy_hit[index]).x <= -960) {
        index = 0;
        while (global->map->sprite_enemy_hit[index] != NULL) {
            pos =  global->map->position_enemy[index + 1];
            sfSprite_setPosition(global->map->sprite_enemy_hit[index], pos);
            index++;
        }
        global->disp->score += 10;
    }
}

void display_enemy_hit(global_t *global)
{
    int index = 0;

    if (global->map->sprite_enemy_hit == NULL)
        return;
    while (global->map->sprite_enemy_hit[index] != NULL) {
        sfSprite_move(global->map->sprite_enemy_hit[index],
        global->map->position_enemy[0]);
        index++;
    }
}
