/*
** EPITECH PROJECT, 2020
** high_score.c
** File description:
** change high score in man.txt (-h)
*/

#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int my_atoi_absolute_value(char *str)
{
    int nb = 0;
    int i = 0;

    while ((str[i] != '\0') && (str[i] >= '0') && (str[i] <= '9')) {
        if (nb != 0)
            nb *= 10;
        nb += str[i] - '0';
        i++;
    }
    return (nb);
}

int my_digitlen(char *str)
{
    int len = 0;
    int index = 0;

    while (str[index] != '\0') {
        if ((str[index] >= '0') && (str[index] <= '9'))
            len++;
        index++;
    }
    return (len);
}

char *write_new_high_score(global_t *global)
{
    int fd = open("src/man/man.txt", O_CREAT | O_RDWR);
    char *line = NULL;
    char *score;
    char buffer[542];
    int new_highscore = global->disp->score;
    int len = 5;

    if (fd == -1)
        return (NULL);
    read(fd, buffer, 534);
    write(fd, "HIGH SCORE : ", 13);
    score = my_itoa(global->disp->score);
    while (new_highscore != 0) {
        new_highscore /= 10;
        len--;
    }
    write(fd, "0000000", len);
    write(fd, score, my_strlen(score));
    return (line);
}

void check_high_score(global_t *global)
{
    int len = my_digitlen(global->disp->high_score);
    int index = my_strlen(global->disp->high_score);
    char *high_score = malloc(sizeof(char) * (len + 1));
    int high_score_nb;

    index--;
    high_score[len--] = '\0';
    while (len >= 0)
        high_score[len--] = global->disp->high_score[index--];
    high_score_nb = my_atoi_absolute_value(high_score);
    if (high_score_nb < global->disp->score)
        write_new_high_score(global);
}
