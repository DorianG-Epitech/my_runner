/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** linked_list
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

obstacle_list *init_obs_list(void)
{
    obstacle_list *list = malloc(sizeof(*list));

    list->obs = malloc(sizeof(*list->obs));
    list->bear = malloc(sizeof(*list->bear));
    list->bat = malloc(sizeof(*list->bat));
    list->girl = malloc(sizeof(*list->girl));
    list->obs->first = NULL;
    list->bear->first = NULL;
    list->bat->first = NULL;
    list->girl->first = NULL;
    return (list);
}

list *init_obstacle(const char *patch,
sfVector2f pos, sfIntRect rect)
{
    list *list = malloc(sizeof(*list));
    element *element = malloc(sizeof(*element));

    element->sprite = sfSprite_create();
    element->texture = sfTexture_createFromFile(patch, NULL);
    element->position = pos;
    element->rectangle = rect;
    element->next = NULL;
    list->first = element;
    sfSprite_setTexture(element->sprite, element->texture, sfFalse);
    sfSprite_setPosition(element->sprite, element->position);
    sfSprite_setTextureRect(element->sprite, element->rectangle);
    return (list);
}

void delete_el(list *list)
{
    if (list->first != NULL) {
        element *del = list->first;
        list->first = list->first->next;
        free(del);
    }
}

void display(sfRenderWindow *window, list *list)
{
    element *element = list->first;

    while (element != NULL) {
        sfRenderWindow_drawSprite(window, element->sprite, NULL);
        element = element->next;
    }
}

void insert(list *list, const char *patch,
sfVector2f pos, sfIntRect rect)
{
    element *new = malloc(sizeof(*new));

    new->sprite = sfSprite_create();
    new->texture = sfTexture_createFromFile(patch, NULL);
    new->position = pos;
    new->rectangle = rect;
    new->next = list->first;
    list->first = new;
    sfSprite_setTexture(new->sprite, new->texture, sfFalse);
    sfSprite_setPosition(new->sprite, new->position);
    sfSprite_setTextureRect(new->sprite, new->rectangle);
}