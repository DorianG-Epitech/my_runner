/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** animation
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

void change_frame(sfRenderWindow *window, element *element, int par)
{
    if (element->position.y != 280 && par == 0)
        return;
    if (par == 0) {
        element->rectangle.left += 44;
        if (element->rectangle.left > 135)
            element->rectangle.left = 3;
    } else if (par == 1) {
        element->rectangle.left += 82;
        if (element->rectangle.left > 657)
            element->rectangle.left = 2;
    } else if (par == 2) {
        element->rectangle.left += 18;
        if (element->rectangle.left > 145)
            element->rectangle.left = 2;
    }
    sfSprite_setTextureRect(element->sprite, element->rectangle);
    sfRenderWindow_drawSprite(window, element->sprite, NULL);
}

int anim_bear(sfRenderWindow *window, list *list)
{
    element *element = malloc(sizeof(*element));
    static int tim = 0;

    tim++;
    if (tim < 30)
        return (0);
    else
        tim = 0;
    element = list->first;
    if (element == NULL)
        return (0);
    while (element != NULL) {
        change_frame(window, element, 0);
        element = element->next;
    }
    return (1);
}

int anim_bat(sfRenderWindow *window, list *list)
{
    element *element = malloc(sizeof(*element));
    static int tim = 0;

    tim++;
    if (tim < 15)
        return (0);
    else
        tim = 0;
    element = list->first;
    if (element == NULL)
        return (0);
    while (element != NULL) {
        change_frame(window, element, 1);
        element = element->next;
    }
    return (1);
}

int anim_girl(sfRenderWindow *window, list *list)
{
    element *element = malloc(sizeof(*element));
    static int tim = 0;

    tim++;
    if (tim < 15)
        return (0);
    else
        tim = 0;
    element = list->first;
    if (element == NULL)
        return (0);
    while (element != NULL) {
        change_frame(window, element, 2);
        element = element->next;
    }
    return (1);
}

void animation(sfRenderWindow *window, obstacle_list *list)
{
    anim_bear(window, list->bear);
    anim_bat(window, list->bat);
    anim_girl(window, list->girl);
    obstacle_move(window, list->girl);
    obstacle_move(window, list->bat);
    obstacle_move(window, list->bear);
    bear_die(list->bear, window, 0);
}