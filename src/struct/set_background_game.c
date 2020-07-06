/*
** EPITECH PROJECT, 2019
** set background
** File description:
** set background move win, lose, ...
*/

#include "my.h"

int set_bkg_texture_game(global_t *global)
{
    int index = 0;
    int index_p = 0;
    char *plan[] = {"asset/picture/10Sky.png", "asset/picture/09Forest.png",
                    "asset/picture/08Forest.png", "asset/picture/07Forest.png",
                    "asset/picture/06Forest.png", "asset/picture/05Parti.png",
                    "asset/picture/04Forest.png", "asset/picture/03Parti.png",
                    "asset/picture/02Bushes.png", "asset/picture/01Mist.png",
                    NULL};

    while (plan[index_p] != NULL) {
        TEXTURE_GAME[index] = sfTexture_createFromFile(plan[index_p], NULL);
        if (!TEXTURE_GAME[index++])
            return (84);
        TEXTURE_GAME[index] = sfTexture_createFromFile(plan[index_p++], NULL);
        if (!TEXTURE_GAME[index++])
            return (84);
    }
    TEXTURE_GAME[index] = NULL;
    return (0);
}

int set_bkg_sprite_game(global_t *global)
{
    int index = 0;
    sfIntRect rect = {0, 0, 1920, 1080};

    while (TEXTURE_GAME[index] != NULL) {
        SPRITE_GAME[index] = sfSprite_create();
        if (!SPRITE_GAME [index])
            return (84);
        sfSprite_setTexture(SPRITE_GAME[index], TEXTURE_GAME[index], sfTrue);
        sfSprite_setTextureRect(SPRITE_GAME[index], rect);
        index++;
    }
    SPRITE_GAME[index] = NULL;
    return (0);
}

int set_bkg_position_game(global_t *global)
{
    global->background->position = malloc(sizeof(sfVector2f *) * 2);
    if (global->background->position == NULL)
        return (84);
    global->background->position[0].x = 1920;
    global->background->position[0].y = 0;
    global->background->position[1].x = 0;
    global->background->position[1].y = 0;
    return (0);
}

void set_bkg_sprite_position_game(global_t *global)
{
    int index = 0;
    sfVector2f position = {0, 0};

    while (SPRITE_GAME[index] != NULL) {
        if ((index % 2) == 0) {
            position.x = 0;
            sfSprite_setPosition(SPRITE_GAME[index], position);
        } else {
            position.x = 1920;
            sfSprite_setPosition(SPRITE_GAME[index], position);
        }
        index++;
    }
    sfSprite_setPosition(SPRITE_GAME[19], global->background->position[1]);
}

int set_bkg_game(global_t *global)
{
    global->background = malloc(sizeof(background_t));
    if (global->background == NULL)
        return (84);
    TEXTURE_GAME = malloc(sizeof(sfTexture *) * 21);
    if (TEXTURE_GAME == NULL)
        return (84);
    SPRITE_GAME = malloc(sizeof(sfSprite *) * 21);
    if ((SPRITE_GAME == NULL) ||
        ((set_bkg_position_game(global) == 84) ||
        (set_bkg_texture_game(global) == 84) ||
        (set_bkg_sprite_game(global) == 84)))
        return (84);
    set_bkg_sprite_position_game(global);
    global->background->clock = sfClock_create();
    return (0);
}
