/*
** EPITECH PROJECT, 2019
** get_next_line.h
** File description:
** get_next_line.h
*/

#ifndef READ_SIZE
#define READ_SIZE 42
#endif /*READ_SIZE 42*/

#ifndef BUFFER
#define BUFFER gnl->buf
#endif /*BUFFER gnl->buf*/

#ifndef INDEX
#define INDEX gnl->index
#endif /*INDEX gnl->index*/

#ifndef LINE_I
#define LINE_I gnl->index_line
#endif /*INDEX_I gnl->index_line*/

#ifndef SIZE
#define SIZE gnl->size
#endif /*SIZE gnl->size*/

#ifndef __GNL_H__
#define __GNL_H__

typedef struct gnl_s
{
    char *buf;
    int index;
    int index_line;
    int size;
} gnl_t;

#endif /*__GNL_H__*/
