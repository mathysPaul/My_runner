/*
** EPITECH PROJECT, 2019
** set.c
** File description:
** set struct
*/

#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/*
** to_clean is a variable to call get_next_line until the end
** of the file because get_next_line need to go to the end to free
** everything.
*/

char *find_high_score(void)
{
    int fd = open("src/man/man.txt", O_CREAT | O_RDWR);
    char *line = NULL;
    char *to_clean;

    if (fd == -1)
        return (NULL);
    line = get_next_line(fd);
    while ((line != NULL) && (my_strcmp(line, "HIGH SCORE :", ':') != 0)) {
        free(line);
        line = get_next_line(fd);
    }
    if (line != NULL) {
        to_clean = get_next_line(fd);
        while (to_clean != NULL) {
            free(to_clean);
            to_clean = get_next_line(fd);
        }
    }
    return (line);
}

int sound(global_t *global)
{
    global->disp->music = sfMusic_createFromFile("asset/music/SNA.ogg");
    global->disp->jump = sfMusic_createFromFile("asset/music/Jump.ogg");
    if ((!global->disp->music) || (!global->disp->jump))
        return (84);
    sfMusic_setLoop(global->disp->music, sfTrue);
    sfMusic_play(global->disp->music);
    sfMusic_setLoop(global->disp->jump, sfTrue);
    sfMusic_pause(global->disp->jump);
    sfMusic_setVolume(global->disp->music, 10);
    sfMusic_setVolume(global->disp->jump, 10);
    return (0);
}

int  set_disp(global_t *global)
{
    sfVideoMode mode = {1920, 1080, 32};

    global->disp = malloc(sizeof(display_t));
    if (global->disp == NULL)
        return (84);
    global->disp->menu = 1;
    global->disp->check_menu = 0;
    global->disp->skin = 0;
    global->disp->error = 0;
    global->disp->score = 0;
    global->disp->high_score = find_high_score();
    global->disp->time = sfClock_create();
    global->disp->window = sfRenderWindow_create
    (mode, "GAME", sfResize | sfClose, NULL);
    if (sound(global) == 84)
        return (84);
    return (0);
}
