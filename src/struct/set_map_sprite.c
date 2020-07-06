/*
** EPITECH PROJECT, 2020
** set_sprite.c
** File description:
** set sprite of map
*/

#include "my.h"

int set_sprite_barrier(global_t *global, int nb_barrier)
{
    int index = 0;
    sfIntRect rect = {160, 0, 80, 80};

    while (index < nb_barrier) {
        global->map->sprite_barrier[index] = sfSprite_create();
        if (!global->map->sprite_barrier[index])
            return (84);
        sfSprite_setTexture(global->map->sprite_barrier[index],
        global->map->texture, sfTrue);
        sfSprite_setTextureRect(global->map->sprite_barrier[index], rect);
        sfSprite_setPosition(global->map->sprite_barrier[index],
        BARRIER_POS[index + 1]);
        index++;
    }
    global->map->sprite_barrier[index] = NULL;
    return (0);
}

int set_sprite_enemy(global_t *global, int nb_enemy)
{
    int index = 0;
    sfIntRect rect = {0, 0, 80, 80};

    while (index < nb_enemy) {
        global->map->sprite_enemy[index] = sfSprite_create();
        if (!global->map->sprite_enemy[index])
            return (84);
        sfSprite_setTexture(global->map->sprite_enemy[index],
        global->map->texture, sfTrue);
        sfSprite_setTextureRect(global->map->sprite_enemy[index], rect);
        sfSprite_setPosition(global->map->sprite_enemy[index],
        ENEMY_POS[index + 1]);
        index++;
    }
    global->map->sprite_enemy[index] = NULL;
    return (0);
}

int set_sprite_enemy_hit(global_t *global, int nb_enemy)
{
    int index = 0;
    sfIntRect rect = {80, 0, 80, 80};

    while (index < nb_enemy) {
        global->map->sprite_enemy_hit[index] = sfSprite_create();
        if (!global->map->sprite_enemy[index])
            return (84);
        sfSprite_setTexture(global->map->sprite_enemy_hit[index],
        global->map->texture, sfTrue);
        sfSprite_setTextureRect(global->map->sprite_enemy_hit[index], rect);
        sfSprite_setPosition(global->map->sprite_enemy_hit[index],
        ENEMY_POS[index + 1]);
        index++;
    }
    global->map->sprite_enemy_hit[index] = NULL;
    return (0);
}

int set_sprite(global_t *global, int nb_barrier, int nb_enemy)
{
    global->map->texture = sfTexture_createFromFile
    ("asset/picture/Element.png", NULL);
    global->map->sprite_barrier = malloc(sizeof(sfSprite *) * (nb_barrier + 1));
    global->map->sprite_enemy = malloc(sizeof(sfSprite *) * (nb_enemy + 1));
    global->map->sprite_enemy_hit = malloc(sizeof(sfSprite *) * (nb_enemy + 1));
    if ((!global->map->texture) ||
        (global->map->sprite_enemy == NULL) ||
        (global->map->sprite_enemy_hit == NULL) ||
        (global->map->sprite_barrier == NULL) ||
        (set_sprite_enemy(global, nb_enemy) == 84) ||
        (set_sprite_enemy_hit(global, nb_enemy) == 84) ||
        (set_sprite_barrier(global, nb_barrier) == 84))
        return (84);
    return (0);
}
