/*
** EPITECH PROJECT, 2019
** push_swap.c
** File description:
** push swap
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int write_score(char **str)
{
    int index = 1;
    int fd = open("score.txt", O_CREAT | O_RDWR);

    if (fd == -1)
        return (84);
    while (str[index] != NULL) {
        write(fd, str[index], my_strlen(str[index]));
        write(fd, " ", 1);
        index++;
    }
    return (0);
}

int main(int ac, char **av)
{
    write_score(av);
    return (0);
}
