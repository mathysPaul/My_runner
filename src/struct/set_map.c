/*
** EPITECH PROJECT, 2020
** set_map.c
** File description:
** map read
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

char **read_map(char *map)
{
    int fd;
    char **map_array;
    char *buffer = malloc(sizeof(char) * 42001);
    int size;

    fd = open(map, O_RDONLY);
    if (fd == -1)
        return (NULL);
    size = read(fd, buffer, 42000);
    if (size == -1)
        return (NULL);
    if (close(fd) == -1)
        return (NULL);
    buffer[size] = '\0';
    map_array = my_str_to_word_array(buffer);
    free(buffer);
    return (map_array);
}

int set_map(global_t *global, char *map)
{
    char **map_array;

    global->map = malloc(sizeof(map_t));
    if (global->map == NULL)
        return (84);
    if ((map[0] == '-') && (map[1] == 'i'))
        return (infinity_map(global));
    map_array = read_map(map);
    if (map_array == NULL)
        return (84);
    return (create_map(global, map_array));
}
