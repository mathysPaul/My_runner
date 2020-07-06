/*
** EPITECH PROJECT, 2019
** set background
** File description:
** set background move win, lose, ...
*/

#include "my.h"

int set_bkg_texture(global_t *global)
{
    int index = 0;
    int index_plan = 0;
    char *plan[] = {"asset/picture/game_over.png",
    "asset/picture/Menu.png", NULL};

    while (plan[index_plan] != NULL) {
        global->background->texture[index] =
            sfTexture_createFromFile(plan[index_plan++], NULL);
        if (!global->background->texture[index++])
            return (84);
    }
    global->background->texture[index] = NULL;
    return (0);
}

int set_bkg_sprite(global_t *global)
{
    int index = 0;
    sfIntRect rect = {0, 0, 1920, 1080};

    while (global->background->texture[index] != NULL) {
        global->background->sprite[index] = sfSprite_create();
        if (!global->background->sprite[index])
            return (84);
        sfSprite_setTexture(global->background->sprite[index],
                            global->background->texture[index], sfTrue);
        sfSprite_setTextureRect(global->background->sprite[index], rect);
        index++;
    }
    global->background->sprite[index] = NULL;
    return (0);
}

int set_bkg(global_t *gbl)
{
    gbl->background->texture = malloc(sizeof(sfTexture *) * 3);
    if (gbl->background->texture == NULL)
        return (84);
    gbl->background->sprite = malloc(sizeof(sfSprite *) * 3);
    if ((gbl->background->sprite == NULL) ||
        ((set_bkg_texture(gbl) == 84) ||
        (set_bkg_sprite(gbl) == 84)))
        return (84);
    return (0);
}
