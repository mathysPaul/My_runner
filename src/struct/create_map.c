/*
** EPITECH PROJECT, 2020
** create_map.c
** File description:
** create a map
*/

#include "my.h"

int height_map(char **map, int row)
{
    int height = 0;

    while ((map[height] != NULL) && (map[height++][0] != '1'));
    return (HEIGHT_SCREEN - ((height - (row + 1)) * 80));
}

int count_char(char **map, char c)
{
    int count = 0;
    int row = 0;
    int col = 0;

    while (map[row] != NULL) {
        if (map[row][col] == c)
            count++;
        if (map[row][col] == '\0') {
            row++;
            col = 0;
        } else
            col++;
    }
    return (count);
}

void check_element(global_t *global, char **map, int row, int col)
{
    static int barrier = 1;
    static int enemy = 1;

    switch (map[row][col]) {
    case '3':
        BARRIER_POS[barrier].x = col * (WIDTH_SCREEN / 24) + 1920;
        BARRIER_POS[barrier++].y = height_map(map, row) - 10;
        break;
    case '2':
        ENEMY_POS[enemy].x = col * (WIDTH_SCREEN / 24) + 1920;
        ENEMY_POS[enemy++].y = height_map(map, row) - 10;
        break;
    }
}

void find_pos_map(global_t *global, char **map)
{
    int row = 0;
    int col = 0;

    while (map[row] != NULL) {
        check_element(global, map, row, col);
        if (map[row][col] == '\0') {
            row++;
            col = -1;
        }
        col++;
    }
}

int create_map(global_t *global, char **map)
{
    int nb_barrier = count_char(map, '3');
    int nb_enemy = count_char(map, '2');

    BARRIER_POS = malloc(sizeof(sfVector2f *) * (nb_barrier + 1));
    ENEMY_POS = malloc(sizeof(sfVector2f *) * (nb_enemy + 1));
    if ((BARRIER_POS == NULL) || (ENEMY_POS == NULL))
        return (84);
    find_pos_map(global, map);
    BARRIER_POS[0].x = -22;
    BARRIER_POS[0].y = 0;
    ENEMY_POS[0].x = -24;
    ENEMY_POS[0].y = 0;
    if (set_sprite(global, nb_barrier, nb_enemy) == 84)
        return (84);
    global->map->game_time = sfClock_create();
    return (0);
}
