/*
** EPITECH PROJECT, 2019
** play.c
** File description:
** the gameplay
*/

#include "my.h"

char *elapsed_time(global_t *global)
{
    sfTime time_elapsed = sfClock_getElapsedTime(global->disp->time);
    int seconds_elapsed = sfTime_asSeconds(time_elapsed);
    char *seconds = my_itoa(seconds_elapsed % 60);
    char *minuts = my_itoa(seconds_elapsed / 60);
    char *info_time;

    info_time = my_strcat((seconds_elapsed / 60 <= 9)
    ? "TIME : 0" : "TIME : ", minuts);
    info_time = my_strcat(info_time, (seconds_elapsed % 60 <= 9) ? ":0" : ":");
    info_time = my_strcat(info_time, seconds);
    free(seconds);
    free(minuts);
    return (info_time);
}

char **information_in_array(global_t *global)
{
    char *score = my_itoa(global->disp->score);
    char *info_score = my_strcat("SCORE : ", score);
    char **info = malloc(sizeof(char *) * 3);

    if (info == NULL)
        return (NULL);
    info[0] = elapsed_time(global);
    info[1] = info_score;
    info[2] = global->disp->high_score;
    free(score);
    return (info);
}

void destroy_text(sfText* text, sfFont* font, char **info)
{
    sfText_destroy(text);
    sfFont_destroy(font);
    if (info != NULL) {
        free(info[0]);
        free(info[1]);
        free(info);
    }
}

void display_information(global_t *global)
{
    int index = 0;
    char **info = information_in_array(global);
    sfFont* font = sfFont_createFromFile("asset/font/AdventPro.ttf");
    sfText* text = sfText_create();
    sfVector2f position[] = {{7, 7}, {(1920 - 210)/2, 7}, {(1920 - 350), 7}};
    sfColor color = {25, 106, 255, 255};

    while ((info != NULL) && (index < 3)) {
        sfText_setString(text, info[index]);
        sfText_setFont(text, font);
        sfText_setFillColor(text, color);
        sfText_setCharacterSize(text, 42);
        sfText_setPosition(text, position[index++]);
        sfRenderWindow_drawText(global->disp->window, text, NULL);
    }
    destroy_text(text, font, info);
}
