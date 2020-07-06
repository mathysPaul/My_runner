/*
** EPITECH PROJECT, 2020
** my_strcat.c
** File description:
** it's not a realy strcat (it alloc a memory)
*/

#include "my.h"
#include <stdlib.h>

char *my_strcat(char *str1, char *str2)
{
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);
    char *result = malloc(sizeof(char) * (len1 + len2 + 1));
    int index = 0;

    if (len2 < 0) {
        free(result);
        return (str1);
    }
    if (result == NULL)
        return (NULL);
    while (index < (len1 + len2)) {
        if (index < len1)
            result[index] = str1[index];
        if (index >= len1)
            result[index] = str2[index - len1];
        index++;
    }
    result[index] = '\0';
    return (result);
}
