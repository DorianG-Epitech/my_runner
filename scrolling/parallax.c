/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** parallax
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

float scrolling(sfRenderWindow *window,
struct game_object *object, float speed)
{
    object->position.x-=speed;
    if (object->position.x < -2040)
        object->position.x = 2040;
    sfSprite_setPosition(object->sprite, object->position);
    sfSprite_setTextureRect(object->sprite, object->rectangle);
    sfRenderWindow_drawSprite(window, object->sprite, NULL);
}

void parralax_scroll(sfRenderWindow *window, struct parallax *back)
{
    scrolling(window, back->bg_one, 1);
    scrolling(window, back->bg_two, 1);
    scrolling(window, back->gr_one, 2.5);
    scrolling(window, back->gr_two, 2.5);
}

void front_parralax_scroll(sfRenderWindow *window, struct parallax *back)
{
    scrolling(window, back->fr_one, 5);
    scrolling(window, back->fr_two, 5);
}

struct parallax *init_background(void)
{
    struct parallax *back = malloc(sizeof(*back));

    back->bg_one = create_object("assets/Image/BR1.png",
    float_to_vec(0, 0), int_to_rect(0, 0, 2048, 900));
    back->bg_two = create_object("assets/Image/BR2.png",
    float_to_vec(2040, 0), int_to_rect(0, 0, 2048, 900));
    back->fr_one = create_object("assets/Image/FR1.png",
    float_to_vec(0, 0), int_to_rect(0, 0, 2048, 900));
    back->fr_two = create_object("assets/Image/FR2.png",
    float_to_vec(2040, 0), int_to_rect(0, 0, 2048, 900));
    back->gr_one = create_object("assets/Image/FL1.png",
    float_to_vec(0, 0), int_to_rect(0, 0, 2048, 900));
    back->gr_two = create_object("assets/Image/FL2.png",
    float_to_vec(2040, 0), int_to_rect(0, 0, 2048, 900));
    return (back);
}