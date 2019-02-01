/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** player
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

int player_jump(sfRenderWindow *window,
struct game_object *char_jump)
{
    static int rect = 0;
    static float sec = -2;

    sec += 0.02;
    rect++;
    if (rect % 30 == 0)
        char_jump->rectangle.left += 20;
    char_jump->position.y = (100 * (sec * sec)) + 100;
    sfSprite_setPosition(char_jump->sprite, char_jump->position);
    sfSprite_setTextureRect(char_jump->sprite, char_jump->rectangle);
    sfRenderWindow_drawSprite(window, char_jump->sprite, NULL);
    if (char_jump->position.y >= 560) {
        char_jump->rectangle.left = 3;
        sec = -2;
        rect = 0;
        return (0);
    }
    return (1);
}

void player_run(sfRenderWindow *window, struct game_object *char_run)
{
    static int i = 0;

    i++;
    if (i == 30) {
        char_run->rectangle.left+=20;
        i = 0;
    }
    if (char_run->rectangle.left >= 160)
        char_run->rectangle.left = 3;
    sfSprite_setTextureRect(char_run->sprite, char_run->rectangle);
    sfRenderWindow_drawSprite(window, char_run->sprite, NULL);
}

int player_roll(sfRenderWindow *window, struct game_object *char_roll)
{
    static int i = 0;
    
    i++;
    if (i == 30) {
        char_roll->rectangle.left += 27;
        i = 0;
    }
    if (char_roll->rectangle.left >= 200) {
        i = 0;
        char_roll->rectangle.left = 83;
        sfSprite_setTextureRect(char_roll->sprite, char_roll->rectangle);
        return (0);
    }
    sfSprite_setPosition(char_roll->sprite, char_roll->position);
    sfSprite_setTextureRect(char_roll->sprite, char_roll->rectangle);
    sfRenderWindow_drawSprite(window, char_roll->sprite, NULL);
    return (2);
}

int user_input(void)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace) ||
    sfKeyboard_isKeyPressed(sfKeyUp)) {
        return (1);
    } else if (sfKeyboard_isKeyPressed(sfKeyLShift) ||
        sfKeyboard_isKeyPressed(sfKeyDown))
        return (2);
    else
        return (0);
}

int player_action(sfRenderWindow *window,
struct character *player, list *bear)
{
    static int i = 0;
    static int step = 0;

    if (step == 0)
        player_run(window, player->run);
    if (step == 1) {
        step = player_jump(window, player->jump);
        return (0);
    }
    if (step == 2) {
        step = player_roll(window, player->roll);
        if (bear_lose(player->roll, bear) == 1) {
            return (1);
        }
        return (0);
    }
    step = user_input();
    return (0);
}