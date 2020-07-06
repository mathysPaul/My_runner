/*
** EPITECH PROJECT, 2019
** display.c
** File description:
** display
*/

#include "my.h"

void draw_score(global_t *global)
{
    sfFont* font = sfFont_createFromFile("asset/font/AdventPro.ttf");
    sfText* text = sfText_create();
    sfVector2f position = {((1920 - 250) / 2), (1080 - 220)};
    sfColor color = {232, 243, 255, 255};

    sfText_setString(text, my_strcat("SCORE : ", my_itoa(global->disp->score)));
    sfText_setFont(text, font);
    sfText_setFillColor(text, color);
    sfText_setCharacterSize(text, 54);
    sfText_setPosition(text, position);
    sfRenderWindow_drawText(global->disp->window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
}

void game_over(global_t *global)
{
    static int check = 0;

    sfMusic_pause(global->disp->jump);
    sfMusic_pause(global->disp->music);
    if (check == 0) {
        check_high_score(global);
        check = 1;
    }
    sfRenderWindow_drawSprite(global->disp->window,
    global->background->sprite[0], NULL);
    draw_score(global);
}

int menu(global_t *global)
{
    sfRenderWindow_drawSprite(global->disp->window,
    global->background->sprite[1], NULL);
    if ((global->disp->skin != 0) &&
        (global->disp->check_menu == 1)) {
        if (set_hero(global) != 84)
            global->disp->menu = 0;
        else
            return (84);
    }
    return (0);
}

void play(global_t *global)
{
    background_play(global);
    map(global);
    hero(global);
    display_information(global);
}

int display(global_t *global)
{
    sfRenderWindow_clear(global->disp->window, sfBlack);
    while (sfRenderWindow_pollEvent(global->disp->window, global->disp->event))
        event(global);
    if (global->disp->menu == 0) {
        if (global->hero->life > 21)
            game_over(global);
        else
            play(global);
    } else {
        if (menu(global) == 84)
            return (84);
    }
    return (0);
}
