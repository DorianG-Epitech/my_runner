/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** bear
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

int bear_lose(struct game_object *player, list *list)
{
    element *bear = malloc(sizeof(*bear));

    bear = list->first;
    if (bear == NULL)
        return (0);
    while (bear != NULL) {
        if (player->position.x + player->rectangle.width + 50
        >= bear->position.x &&
        player->position.x + player->rectangle.width + 50
        < bear->position.x + bear->rectangle.width) {
            bear->position.y = 279;
            sfSprite_setPosition(bear->sprite, bear->position);
            return (1);
        }
        bear = bear->next;
    }
    return (0);
}

int my_linked_list_size(list *list)
{
    element *element = malloc(sizeof(*element));
    int len = 0;

    if ((element = list->first) == NULL)
        return (-1);
    for (len; element != NULL; element = element->next)
        len++;
    return (len);
}

void move_dead_bear(element *bear, float *step, int *frame)
{
    for (int i = 0; bear != NULL; i++) {
        if (bear->position.y != 280) {
            bear->rectangle.left = (frame[i] == 0) ? 399 : bear->rectangle.left;
            frame[i]++;
            bear->rectangle.left =
            (frame[i] < 200 && frame[i] % 50 == 0 && bear->position.y != 300) ?
        bear->rectangle.left + 44 : bear->rectangle.left;
            step[i] += 0.02;
            bear->position.y = (50 * (step[i] * step[i])) + 100;
            bear->position.y = (bear->position.y > 300) ?
        300 : bear->position.y;
            bear->position.x = (bear->position.y != 300) ?
        bear->position.x + 3 : bear->position.x;
            sfSprite_setPosition(bear->sprite, bear->position);
            sfSprite_setTextureRect(bear->sprite, bear->rectangle);
        }
        bear = bear->next;
    }
}

void bear_die(list *list, sfRenderWindow *window, int reset)
{
    element *bear = malloc(sizeof(*bear));
    int len = my_linked_list_size(list);
    static int verify = 0;
    static float *step;
    static int *frame;
    
    if (reset == 1 || len == -1) {
        verify = 0;
        return;
    }
    if (verify == 0) {
        frame = malloc(sizeof(float) * len);
        step = malloc(sizeof(float) * len);
        for (int i = 0; i != len; i++) {
            step[i] = -2;
            frame[i] = 0;
        }
        verify++;
    }
    bear = list->first;
    move_dead_bear(bear, step, frame);
}