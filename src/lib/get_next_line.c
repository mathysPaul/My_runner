/*
** EPITECH PROJECT, 2019
** get_next_line.c
** File description:
** get next line
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

gnl_t *read_fd(int fd, gnl_t *gnl)
{
    char *buffer = malloc(sizeof(char) * (READ_SIZE + 1));

    if (buffer == NULL)
        return (NULL);
    SIZE = read(fd, buffer, READ_SIZE);
    if ((fd == 0) && (SIZE == 0) && (LINE_I != 0)) {
        free(buffer);
        return (gnl);
    } else if ((SIZE == -1) || (SIZE == 0)) {
        free (buffer);
        free(BUFFER);
        BUFFER = NULL;
    } else {
        buffer[SIZE] = '\0';
        free(BUFFER);
        BUFFER = buffer;
        INDEX = 0;
    }
    return (gnl);
}

char *realloc_line(char *line, int len_line)
{
    int index = 0;
    char *new_line = malloc(sizeof(char) * len_line + 1);

    if (new_line == NULL) {
        free(line);
        free(new_line);
        return (NULL);
    }
    while (index < (len_line - READ_SIZE)) {
        new_line[index] = line[index];
        index++;
    }
    free(line);
    return (new_line);
}

gnl_t *start_buffer(int fd, gnl_t *gnl)
{
    if (gnl == NULL) {
        gnl = malloc(sizeof(gnl_t));
        if (gnl == NULL)
            return (NULL);
        BUFFER = NULL;
        LINE_I = 0;
        INDEX = 0;
    }
    if ((BUFFER == NULL) || (INDEX >= READ_SIZE) || (BUFFER[INDEX] == '\0')) {
        gnl = read_fd(fd, gnl);
        if (gnl == NULL)
            return (NULL);
        LINE_I = ((INDEX >= SIZE) && (BUFFER != NULL)) ? LINE_I-1 : LINE_I;
        INDEX = ((INDEX >= SIZE) && (BUFFER != NULL)) ? INDEX-1 : INDEX;
    }
    if ((BUFFER == NULL) && (LINE_I == 0)) {
        free(gnl);
        return (NULL);
    }
    return (gnl);
}

char *copy_line(gnl_t *gnl, int fd, char *line, int len_line)
{
    while ((BUFFER != NULL) && (BUFFER[INDEX] != '\n') &&
    (BUFFER[INDEX] != '\0')) {
        line[LINE_I++] = BUFFER[INDEX++];
        gnl = start_buffer(fd, gnl);
        if (LINE_I == len_line) {
            len_line += READ_SIZE;
            line = realloc_line(line, len_line);
        }
        if (line == NULL)
            return (NULL);
    }
    line[LINE_I] = '\0';
    return (line);
}

char *get_next_line(int fd)
{
    static gnl_t *gnl = NULL;
    int len_line = READ_SIZE;
    char *line = malloc(sizeof(char) * (READ_SIZE + 1));

    gnl = start_buffer(fd, gnl);
    if ((line == NULL) || (gnl == NULL) ||
    (fd <= -1) || (BUFFER[INDEX] == '\0')) {
        free(line);
        return (NULL);
    }
    line = copy_line(gnl, fd, line, len_line);
    LINE_I = 0;
    INDEX++;
    return (line);
}
