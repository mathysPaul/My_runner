/*
** EPITECH PROJECT, 2019
** hero.c
** File description:
** hero
*/

#include "my.h"

void sprite_index_value(global_t *global)
{
    sfTime time = sfClock_getElapsedTime(global->hero->clock_sprite);

    if ((sfTime_asSeconds(time) > 0.035) && (global->hero->jump == 0)){
        if (global->hero->index < 16)
            global->hero->index++;
        else
            global->hero->index = 0;
        sfClock_restart(global->hero->clock_sprite);
    }
    if (global->hero->jump == 1) {
        global->hero->index = 17;
        sfClock_restart(global->hero->clock_sprite);
    }
    if (global->hero->slide == 1)
        global->hero->index = 18;
}

void check_end_of_jump(global_t *global)
{
    if (global->hero->position[1].y > global->hero->position[0].y)
        global->hero->jump = 0;
    if (global->hero->jump == 0) {
        global->hero->position[1].y = 0;
        sfSprite_setPosition(global->hero->sprite[global->hero->index],
        global->hero->position[0]);
        sfMusic_pause(global->disp->jump);
    }
}

void jump(global_t *global)
{
    sfTime time = sfClock_getElapsedTime(global->hero->clock_jump);
    float seconds = sfTime_asSeconds(time);
    int y;
    static int hero_posy;

    if (global->hero->jump == 1) {
        if (global->hero->position[1].y == 0)
            hero_posy = global->hero->position[0].y;
        y = 0.0042 * pow(seconds * 700, 2) - 2 * (seconds * 700);
        global->hero->position[1].y = y + hero_posy;
        global->hero->position[1].x = global->hero->position[0].x;
        sfSprite_setPosition(global->hero->sprite[global->hero->index],
        global->hero->position[1]);
    }
    check_end_of_jump(global);
}

void display_life(global_t *global)
{
    int index = 0;
    int life = (global->hero->life / 7);
    sfVector2f position = {0, 0};

    while ((index < life) && (index < 3)) {
        sfSprite_setPosition(global->hero->sprite_life[index], position);
        sfRenderWindow_drawSprite(global->disp->window,
        global->hero->sprite_life[index], NULL);
        index++;
    }
}

void hero(global_t *global)
{
    hit_box_map(global);
    if (global->hero->slide == 1)
        hitbox_enemy_slide(global);
    else
        hitbox_enemy(global);
    hitbox_barrier(global);
    sprite_index_value(global);
    jump(global);
    sfRenderWindow_drawSprite
    (global->disp->window, global->hero->sprite[global->hero->index], NULL);
    sfRenderWindow_drawSprite(global->disp->window, SPRITE_GAME[FOG], NULL);
    display_life(global);
}
