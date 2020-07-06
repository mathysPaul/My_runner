/*
** EPITECH PROJECT, 2019
** set hero
** File description:
** set struct of hero
*/

#include "my.h"

void set_array_sprite(global_t *global)
{
    int index = 0;
    sfIntRect rect = {0, 0, 150, 220};

    while (index < 18) {
        global->hero->sprite[index] = sfSprite_create();
        sfSprite_setTexture(global->hero->sprite[index],
        global->hero->texture, sfTrue);
        sfSprite_setTextureRect(global->hero->sprite[index++], rect);
        rect.left += 150;
    }
    rect.width += 50;
    global->hero->sprite[index] = sfSprite_create();
    sfSprite_setTexture(global->hero->sprite[index],
    global->hero->texture, sfTrue);
    sfSprite_setTextureRect(global->hero->sprite[index++], rect);
    global->hero->sprite[index] = NULL;
}

void set_position(global_t *global)
{
    global->hero->position[0].x = 100;
    global->hero->position[0].y = HEIGHT_SCREEN - 200;
    global->hero->position[1].x = 100;
    global->hero->position[1].y = 0;
    global->hero->position[2].x = 0;
    global->hero->position[2].y = 0;
}

void set_sprite_life(global_t *global)
{
    int index = 0;
    sfIntRect rect = {0, 0, 1920, 1080};
    global->hero->texture_life = sfTexture_createFromFile
    ("asset/picture/life.png", NULL);

    while (index < 3) {
        global->hero->sprite_life[index] = sfSprite_create();
        sfSprite_setTexture(global->hero->sprite_life[index],
        global->hero->texture_life, sfTrue);
        sfSprite_setTextureRect(global->hero->sprite_life[index++], rect);
    }
}

int set_asset(global_t *global)
{
    const char *skin[] = {"asset/picture/Chibi.png",
    "asset/picture/ReverseChibi.png"};
    global->hero->position = malloc(sizeof(sfVector2f) * 3);
    if (global->hero->position == NULL)
        return (84);
    set_position(global);
    global->hero->texture = sfTexture_createFromFile
    (skin[global->disp->skin - 1], NULL);
    global->hero->sprite = malloc(sizeof(sfSprite *) * 20);
    global->hero->sprite_life = malloc(sizeof(sfSprite *) * 4);
    if ((!global->hero->texture) ||
        (global->hero->sprite == NULL) ||
        (global->hero->sprite_life == NULL))
        return (84);
    set_sprite_life(global);
    set_array_sprite(global);
    return (0);
}

int set_hero(global_t *global)
{
    global->hero = malloc(sizeof(hero_t));
    if (global->hero == NULL)
        return (84);
    global->hero->move = 0;
    global->hero->index = 0;
    global->hero->jump = 0;
    global->hero->slide = 0;
    global->hero->life = 0;
    global->hero->clock_sprite = sfClock_create();
    global->hero->clock_jump = sfClock_create();
    if (set_asset(global) == 84)
        return (84);
    return (0);
}
