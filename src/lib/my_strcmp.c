/*
** EPITECH PROJECT, 2020
** my_strcmp.c
** File description:
** my string compare
*/

#include <stddef.h>

int my_strcmp(char *str1, char *str2, char c)
{
    int index = 0;

    if ((str1 == NULL) || (str2 == NULL))
        return (-1);
    while ((str1[index] != '\0') && (str1[index] != c) &&
    (str2[index] != '\0') && (str1[index] == str2[index])) {
        index++;
    }
    if ((str1[index] == c) && (str2[index] == '\0'))
        return (0);
    return (str1[index] - str2[index]);
}
