/*
** EPITECH PROJECT, 2020
** hit_box.c
** File description:
** hit box
*/

#include "my.h"

void hitbox_enemy(global_t *global)
{
    int index = 0;
    int enemy_posx;
    int enemy_posy;
    int x;
    int y;

    while (global->map->sprite_enemy[index] != NULL) {
        enemy_posx = sfSprite_getPosition(global->map->sprite_enemy[index]).x;
        enemy_posy = sfSprite_getPosition(global->map->sprite_enemy[index]).y;
        x = sfSprite_getPosition(HERO[INDEX_HERO]).x - enemy_posx;
        y = sfSprite_getPosition(HERO[INDEX_HERO]).y - enemy_posy;
        if ((x >= -125) && (x < 55) && (y >= -120) && (y <= 30)) {
            global->hero->life++;
            sfRenderWindow_drawSprite(global->disp->window,
            global->map->sprite_enemy_hit[index], NULL);
        }
        index++;
    }
}

int hitbox_barrier_index(global_t *global, int index)
{
    int barrier_posx;
    int barrier_posy;
    int x;
    int y;
    static int check = 0;

    barrier_posx = sfSprite_getPosition(BARRIER[index]).x;
    barrier_posy = sfSprite_getPosition(BARRIER[index]).y;
    x = sfSprite_getPosition(global->hero->sprite[INDEX_HERO]).x - barrier_posx;
    y = sfSprite_getPosition(global->hero->sprite[INDEX_HERO]).y;
    if ((x >= -125) && (x < 55) && ((y + 220) < barrier_posy) &&
        (global->hero->position[0].y > barrier_posy - 192)) {
        global->hero->position[0].y = barrier_posy - 192;
        check = 1;
    }
    if ((check == 1) && ((x >= -125) && (x < 55)) &&
        (barrier_posy == global->hero->position[0].y + 192))
        return (1);
    return (0);
}

void hitbox_barrier(global_t *global)
{
    int index = 0;
    int check = 0;

    while (global->map->sprite_barrier[index] != NULL) {
        if (hitbox_barrier_index(global, index) == 1)
            check = 1;
        index++;
    }
    if (check == 0)
        global->hero->position[0].y =  HEIGHT_SCREEN - 200;
}

void hitbox_enemy_slide(global_t *global)
{
    int index = 0;
    int enemy_posx;
    int enemy_posy;
    int x;
    int y;

    while (global->map->sprite_enemy[index] != NULL) {
        enemy_posx = sfSprite_getPosition(global->map->sprite_enemy[index]).x;
        enemy_posy = sfSprite_getPosition(global->map->sprite_enemy[index]).y;
        x = sfSprite_getPosition(HERO[INDEX_HERO]).x - enemy_posx;
        y = sfSprite_getPosition(HERO[INDEX_HERO]).y - enemy_posy;
        if ((x >= -200) && (x < 80) && (y >= -120) && (y < -50)) {
            global->hero->life++;
            sfRenderWindow_drawSprite(global->disp->window,
            global->map->sprite_enemy_hit[index], NULL);
        }
        index++;
    }
}

void hit_box_map(global_t *global)
{
    if (global->hero->move == 1) {
        global->hero->position[0].x += 9;
        if (global->hero->position[0].x > 1800)
            global->hero->position[0].x = 1800;
    }
    if (global->hero->move == 2) {
        global->hero->position[0].x -= 9;
        if (global->hero->position[0].x < 0)
            global->hero->position[0].x = 0;
    }
}
