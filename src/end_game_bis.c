/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** end_game_bis
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

void display_after(sfRenderWindow *window, struct parallax *back,
obstacle_list *list_obs)
{
    sfRenderWindow_drawSprite(window, back->bg_one->sprite, NULL);
    sfRenderWindow_drawSprite(window, back->bg_two->sprite, NULL);
    sfRenderWindow_drawSprite(window, back->gr_one->sprite, NULL);
    sfRenderWindow_drawSprite(window, back->gr_two->sprite, NULL);
    anim_bear(window, list_obs->bear);
    anim_bat(window, list_obs->bat);
    anim_girl(window, list_obs->girl);
    display(window, list_obs->bat);
    display(window, list_obs->girl);
    display(window, list_obs->bear);
    display(window, list_obs->obs);
}

void display_front(sfRenderWindow *window,
struct parallax *back)
{
    sfRenderWindow_drawSprite(window, back->fr_one->sprite, NULL);
    sfRenderWindow_drawSprite(window, back->fr_two->sprite, NULL);
}

int player_fall(sfRenderWindow *window, struct character *player)
{
    player->run->position.y += 6;
    player->run->position.x += 1;
    sfSprite_setPosition(player->run->sprite, player->run->position);
    sfRenderWindow_drawSprite(window, player->run->sprite, NULL);
    if (player->run->position.y >= 900)
        return (1);
    return (0);
}

void set_draw_win_death(sfRenderWindow *window,
struct game_object *win_lose, struct menu_obj *menu)
{
    sfSprite_setPosition(menu->exit->sprite, menu->exit->position);
    sfSprite_setPosition(menu->how_rest->sprite, menu->how_rest->position);
    sfSprite_setTextureRect(menu->how_rest->sprite, menu->how_rest->rectangle);
    sfRenderWindow_drawSprite(window, win_lose->sprite, NULL);
    sfRenderWindow_drawSprite(window, menu->how_rest->sprite, NULL);
    sfRenderWindow_drawSprite(window, menu->exit->sprite, NULL);
}

int display_win_dead(sfRenderWindow *window,
struct game_object *win_lose, struct menu_obj *menu, int par)
{
    if (par == 1)
        win_lose = create_object("assets/Image/lose.png",
        float_to_vec(230, 70), int_to_rect(0, 0, 720, 305));
    else if (par == 2)
        win_lose = create_object("assets/Image/win.png",
        float_to_vec(230, 70), int_to_rect(0, 0, 720, 305));
    else
        return (0);
    sfSprite_setScale(win_lose->sprite, float_to_vec(2.5, 2.5));
    menu->how_rest->rectangle.top = 100;
    menu->how_rest->position.y = 500;
    menu->how_rest->position.x = 490;
    menu->exit->position.x = menu->how_rest->position.x + 560;
    menu->exit->position.y = menu->how_rest->position.y;
    set_draw_win_death(window, win_lose, menu);
    if (detect_click(window, menu->how_rest) == 1)
        return (1);
    if (detect_click(window, menu->exit) == 1)
        return (2);
    return (0);
}