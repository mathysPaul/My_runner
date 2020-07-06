/*
** EPITECH PROJECT, 2020
** my_strlen.c
** File description:
** my_strlen
*/

#include <stddef.h>

int my_strlen(char *str)
{
    int len = 0;

    if (str != NULL)
        while (str[len++] != '\0');
    return (len - 1);
}
