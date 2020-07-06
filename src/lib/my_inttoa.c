/*
** EPITECH PROJECT, 2019
** rush3
** File description:
** rush3 opposit rush1
*/

#include "my.h"
#include <stdio.h>

int len_nb(int nb)
{
    int i = 0;

    if (nb == 0)
        i = 1;
    while (nb != 0) {
        nb /= 10;
        i++;
    }
    return (i);
}

int d_modulo(int nb)
{
    int d = 1;

    if (nb == 0)
        d = 1;
    while ((nb / d) != 0)
        d *= 10;
    return (d);
}

char *my_itoa(int nb)
{
    int i = 0;
    int d = d_modulo(nb);
    char *str_nb;

    str_nb = malloc(sizeof(char) * len_nb(nb) + 1);
    if (nb == 0)
        str_nb[i++] = '0';
    while (d != 1) {
        nb = nb % d;
        str_nb[i] = '0' + (nb / (d / 10));
        d /= 10;
        i++;
    }
    str_nb[i] = '\0';
    return (str_nb);
}
