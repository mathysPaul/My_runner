/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

int set_struct(global_t *gbl, char *map)
{
    if ((set_map(gbl, map) == 84) || (set_disp(gbl) == 84) ||
        (set_bkg_game(gbl) == 84) || (set_bkg(gbl) == 84))
        return (84);
    return (0);
}

int info_game(int ac, char **av)
{
    int fd;
    char *buffer = malloc(sizeof(char) * 42001);
    int size;

    if ((ac != 1) && (av[1][0] == '-') && (av[1][1] == 'h')) {
        fd = open("src/man/man.txt", O_CREAT | O_RDWR);
        if (fd == -1)
            return (84);
        size = read(fd, buffer, 42000);
        if (size == -1)
            return (84);
        write(1, buffer, size);
        if (close(fd) == -1)
            return (84);
        return (1);
    }
    free(buffer);
    return (0);
}

int window(char *map)
{
    sfEvent event;
    global_t *global = malloc(sizeof(global_t));

    if (set_struct(global, map) == 84)
        return EXIT_FAILURE;
    sfRenderWindow_setFramerateLimit(global->disp->window, 30);
    while (sfRenderWindow_isOpen(global->disp->window)) {
        global->disp->event = &event;
        if (display(global) == 84)
            return (84);
        sfRenderWindow_display(global->disp->window);
    }
    destroy(global);
    return (0);
}

int main(int ac, char **av)
{
    if (ac != 2) {
        write(0, "./my_runner: bad arguments: 0 given but 1 is required\n", 56);
        write(0, "retry with -h\n", 14);
        return (84);
    }
    switch (info_game(ac, av)) {
    case 0 :
        if (window(av[1]) == EXIT_FAILURE)
            return (84);
        break;
    case 1 :
        return (0);
        break;
    case 84 :
        return (84);
        break;
    }
    return (0);
}
