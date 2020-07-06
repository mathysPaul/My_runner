/*
** EPITECH PROJECT, 2019
** struct.h
** File description:
** struct.h
*/

#include "my.h"
#include <SFML/Audio.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector3.h>
#include <stddef.h>

#ifndef __BACKGROUND_H_
#define __BACKGROUND_H_
typedef struct background_s
{
    sfVector2f *position;
    sfTexture **texture_game;
    sfSprite **sprite_game;
    sfTexture **texture;
    sfSprite **sprite;
    sfClock *clock;
} background_t;
#endif /* __BACKGROUND_H_ */

#ifndef __HERO_H_
#define __HERO_H_
typedef struct hero_s
{
    int index;
    int jump;
    int slide;
    int move;
    sfClock *clock_sprite;
    sfClock *clock_jump;
    sfVector2f *position;
    sfTexture *texture;
    sfSprite **sprite;
    sfTexture *texture_life;
    sfSprite **sprite_life;
    int life;
} hero_t;
#endif /* __HERO_H_ */

#ifndef __DISPLAY_H_
#define __DISPLAY_H_
typedef struct display_s
{
    sfRenderWindow *window;
    sfEvent *event;
    int error;
    char *high_score;
    int score;
    int win;
    int menu;
    int check_menu;
    int set_hero;
    int skin;
    sfClock *time;
    sfMusic *music;
    sfMusic *jump;
} display_t;
#endif /* __DISPLAY_H_ */

#ifndef __MAP_H_
#define __MAP_H_
typedef struct map_s
{
    sfVector2f *position_barrier;
    sfVector2f *position_enemy;
    sfTexture *texture;
    sfSprite **sprite_barrier;
    sfSprite **sprite_enemy_hit;
    sfSprite **sprite_enemy;
    sfClock *game_time;
} map_t;
#endif /* __MAP_H_ */

#ifndef __GLOBAL_H_
#define __GLOBAL_H_
typedef struct global_s
{
    background_t *background;
    hero_t *hero;
    display_t *disp;
    map_t *map;
} global_t;
#endif /* __GLOBAL_H_ */
