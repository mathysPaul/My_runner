/*
** EPITECH PROJECT, 2020
** my_str_to_word_array.c
** File description:
** str to word array
*/

#include <stdlib.h>
#include <stddef.h>

int count_line(char *str)
{
    int count = 1;
    int index = 0;

    if (str == NULL)
        return (-1);
    while (str[index] != '\0') {
        if (str[index] == '\n')
            count++;
        index++;
    }
    return (count);
}

int linelen(char *str, int index)
{
    while ((str[index] != '\n') && (str[index] != '\0'))
        index++;
    return (index + 1);
}

char **create_array(char *str, char **array, int number_line)
{
    int row = 0;
    int col = 0;
    int index = 0;

    while (row < number_line) {
        array[row] = malloc(sizeof(char) * linelen(str, index));
        if (array[row] == NULL)
            return (NULL);
        while ((str[index] != '\n') && (str[index] != '\0'))
            array[row][col++] = str[index++];
        array[row++][col] = '\0';
        col = 0;
        index++;
    }
    array[row] = NULL;
    return (array);
}

char **my_str_to_word_array(char *str)
{
    int number_line = count_line(str);
    char **array;

    if (number_line == -1)
        return (NULL);
    array = malloc(sizeof(char *) * (number_line + 1));
    if (array == NULL)
        return (NULL);
    array = create_array(str, array, number_line);
    return (array);
}
