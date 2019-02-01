/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** collide
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

int check_obs_intersect(element *obs, sfIntRect *rect1, sfIntRect *rect2)
{
    while (obs != NULL) {
        if (obs->rectangle.top != 0) {
            rect2->left = obs->position.x;
            rect2->top = obs->position.y;
            rect2->width = obs->rectangle.width * 2;
        } else {
            rect2->left = obs->position.x + 40;
            rect2->top = obs->position.y - 20;
            rect2->width = obs->rectangle.width - 80;
        }
        rect2->height = obs->rectangle.height * 2;
        if (sfIntRect_intersects(rect1, rect2, NULL) == 1 &&
            sfSprite_getPosition(obs->sprite).y == 660)
            return (2);
        if (sfIntRect_intersects(rect1, rect2, NULL) == 1)
            return (1);
        obs = obs->next;
    }
    return (0);
}

int check_bat_intersect(element *obs, sfIntRect *rect1, sfIntRect *rect2)
{
    while (obs != NULL) {
        rect2->left = obs->position.x;
        rect2->top = obs->position.y;
        rect2->width = obs->rectangle.width * 3.5;
        rect2->height = obs->rectangle.height * 5;
        if (sfIntRect_intersects(rect1, rect2, NULL) == 1)
            return (1);
        obs = obs->next;
    }
    return (0);
}

int check_bear_intersect(element *obs, sfIntRect *rect1, sfIntRect *rect2)
{
    while (obs != NULL) {
        if (obs->position.y != 280) {
            obs = obs->next;
            continue;
        }
        rect2->left = obs->position.x + 20;
        rect2->top = obs->position.y;
        rect2->width = obs->rectangle.width;
        rect2->height = obs->rectangle.height * 10;
        if (sfIntRect_intersects(rect1, rect2, NULL) == 1)
            return (1);
        obs = obs->next;
    }
    return (0);
}

void create_array(sfIntRect *rect, struct character *player)
{
    rect->left = player->jump->position.x;
    rect->top = player->jump->position.y;
    rect->width = player->jump->rectangle.width * 5;
    rect->height = player->jump->rectangle.height * 5;
}

int collide(obstacle_list *list, struct character *player)
{
    element *obs = malloc(sizeof(*obs));
    sfIntRect *rect1 = malloc(sizeof(*rect1));
    sfIntRect *rect2 = malloc(sizeof(*rect2));

    create_array(rect1, player);
    obs = list->obs->first;
    if (check_obs_intersect(obs, rect1, rect2) == 1)
        return (1);
    obs = list->obs->first;
    if (check_obs_intersect(obs, rect1, rect2) == 2)
        return (2);
    obs = list->bat->first;
    if (check_bat_intersect(obs, rect1, rect2) == 1)
        return (1);
    obs = list->bear->first;
    if (check_bear_intersect(obs, rect1, rect2) == 1)
        return (1);
    return (0);
}