/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** obstacle
*/

#include <stddef.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "my.h"

void obstacle_move(sfRenderWindow *window, list *list)
{
    element *obstacle = malloc(sizeof(*obstacle));
    obstacle = list->first;

    if (obstacle == NULL)
        return;

    while (obstacle != NULL) {
        obstacle->position.x-=2.5;
        sfSprite_setPosition(obstacle->sprite, obstacle->position);
        sfSprite_setTextureRect(obstacle->sprite, obstacle->rectangle);
        sfRenderWindow_drawSprite(window, obstacle->sprite, NULL);
        obstacle = obstacle->next;
    }
}