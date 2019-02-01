/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** function
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

int *create_par(void)
{
    int *par = malloc(sizeof(int) * 3);

    for (int i = 0; i != 3; i++)
        par[i] = 0;
    return (par);
}

void display_sprite(sfRenderWindow *window, struct character *player)
{
    sfSprite_setPosition(player->run->sprite, player->run->position);
    sfSprite_setTextureRect(player->run->sprite, player->run->rectangle);
    sfRenderWindow_drawSprite(window, player->run->sprite, NULL);
}