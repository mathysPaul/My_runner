/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#define HERO_POS global->hero->position
#define INDEX_HERO global->hero->index
#define HERO global->hero->sprite
#define BARRIER global->map->sprite_barrier
#define FOG 19
#define TEXTURE_GAME global->background->texture_game
#define SPRITE_GAME global->background->sprite_game
#define WIDTH_SCREEN 1920
#define HEIGHT_SCREEN 1010
#define BARRIER_POS global->map->position_barrier
#define ENEMY_POS global->map->position_enemy

#ifndef MY_H_
#define MY_H_
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "struct.h"
#include <math.h>
/*main*/
int set_struct(global_t *, char *);
int info_game(int, char **);
int window(char *);
/*set*/
int set_map(global_t *, char *);
int infinity_map(global_t *);
int create_map(global_t *, char **);
int set_sprite(global_t *, int, int);
int set_bkg(global_t *);
int set_bkg_game(global_t *);
int set_disp(global_t *);
int set_hero(global_t *);
/*destroy*/
void destroy(global_t *);
/*display*/
int display(global_t *);
/*event*/
void event(global_t *);
void player_move(global_t *global);
void player_jump_slide(global_t *global);
/*game*/
void background_play(global_t *);
void hero(global_t *);
void hitbox_enemy(global_t *global);
void hitbox_barrier(global_t *global);
void hitbox_enemy_slide(global_t *global);
void hit_box_map(global_t *global);
void play(global_t *);
char **information_in_array(global_t *global);
void display_information(global_t *global);
void check_high_score(global_t *global);
/*map*/
void position_barrier(global_t *);
void display_barrier(global_t *);
void position_enemy(global_t *);
void display_enemy(global_t *);
void position_enemy_hit(global_t *);
void display_enemy_hit(global_t *);
void map(global_t *);
/*lib*/
char **my_str_to_word_array(char *);
char *my_itoa(int);
char *get_next_line(int);
int my_strcmp(char *, char *, char);
char *my_strcat(char *, char *);
int my_strlen(char *);
#endif
