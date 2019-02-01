/*
** EPITECH PROJECT, 2018
** MUL_my_screensaver_2018
** File description:
** initiation
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

sfVector2f float_to_vec(float x, float y)
{
    sfVector2f vec = {x, y};
    return (vec);
}

sfRenderWindow *window_create(int width, int height)
{
    sfVideoMode mode = {width, height, 32};
    sfRenderWindow *window;

    window = sfRenderWindow_create(mode, "My_RUNNER", sfResize | sfClose, NULL);

    return (window);
}

struct game_object *create_object(const char *path_to_spritesheet,
sfVector2f pos, sfIntRect rect)
{
    struct game_object *obj = malloc(sizeof(*obj));

    obj->sprite = sfSprite_create();
    obj->texture = sfTexture_createFromFile(path_to_spritesheet, NULL);
    obj->position = pos;
    obj->rectangle = rect;
    sfSprite_setTexture(obj->sprite, obj->texture, sfFalse);
    sfSprite_setPosition(obj->sprite, obj->position);
    sfSprite_setTextureRect(obj->sprite, obj->rectangle);
    return (obj);
}

struct character *init_player(void)
{
    struct character *player = malloc(sizeof(*player));

    player->run = create_object("assets/Image/char.png",
    float_to_vec(200, 560), int_to_rect(3, 795, 17, 17));
    player->jump = create_object("assets/Image/char.png",
    float_to_vec(200, 560), int_to_rect(3, 818, 17, 17));
    player->roll = create_object("assets/Image/char.png",
    float_to_vec(200, 560), int_to_rect(83, 594, 25, 22));
    sfSprite_setScale(player->run->sprite, float_to_vec(10, 10));
    sfSprite_setScale(player->roll->sprite, float_to_vec(10, 10));
    sfSprite_setScale(player->jump->sprite, float_to_vec(10, 10));
    return (player);
}

sfIntRect int_to_rect(int x, int y, int width, int height)
{
    sfIntRect rectangle = {x, y, width, height};
    
    return (rectangle);
}