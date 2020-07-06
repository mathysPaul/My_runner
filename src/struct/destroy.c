/*
** EPITECH PROJECT, 2019
** destroy
** File description:
** destroy
*/

#include "my.h"

void background_destroy(global_t *global)
{
    int index = 0;

    free(global->background->position);
    while (TEXTURE_GAME[index] != NULL)
        sfTexture_destroy(TEXTURE_GAME[index++]);
    free(TEXTURE_GAME);
    index = 0;
    while (SPRITE_GAME[index] != NULL)
        sfSprite_destroy(SPRITE_GAME[index++]);
    free(SPRITE_GAME);
    sfClock_destroy(global->background->clock);
    free(global->background);
}

void hero_destroy(global_t *global)
{
    int index = 0;

    if (global->hero == NULL)
        return;
    while (global->hero->sprite[index] != NULL)
        sfSprite_destroy(global->hero->sprite[index++]);
    free(global->hero->sprite);
    free(global->hero->position);
    sfTexture_destroy(global->hero->texture);
    sfClock_destroy(global->hero->clock_sprite);
    sfClock_destroy(global->hero->clock_jump);
    free(global->hero);
}

void disp_destroy(global_t *global)
{
    sfRenderWindow_destroy(global->disp->window);
    sfMusic_destroy(global->disp->music);
    sfMusic_destroy(global->disp->jump);
    free(global->disp);
}

void destroy(global_t *global)
{
    background_destroy(global);
    hero_destroy(global);
    disp_destroy(global);
    free(global);
}
