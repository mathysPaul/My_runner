/*
** EPITECH PROJECT, 2019
** background game
** File description:
** the game du -sh .
*/

#include "my.h"

void position_background(global_t *global)
{
    int index = 0;
    float posx;

    while (SPRITE_GAME[index] != NULL) {
        posx = sfSprite_getPosition(SPRITE_GAME[index]).x;
        if (posx <= -1920)
            sfSprite_setPosition(SPRITE_GAME[index],
            global->background->position[0]);
        if ((posx <= -1920) && (index == 17))
            global->disp->score += 10;
        index++;
    }
}

void background_play(global_t *global)
{
    int index = 0;
    int x;

    position_background(global);
    while ((index < 16) && (SPRITE_GAME[index] != NULL)) {
        sfSprite_move(SPRITE_GAME[index],
        global->background->position[1]);
        sfRenderWindow_drawSprite(global->disp->window,
        SPRITE_GAME[index++], NULL);
        x = global->background->position[1].x;
        global->background->position[1].x = ((index % 2) == 0) ? x - 2 : x;
    }
    global->background->position[1].x = 0;
}
