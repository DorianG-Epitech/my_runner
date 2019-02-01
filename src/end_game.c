/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** end_game
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

int determine_end(obstacle_list *list_obs, struct character *player)
{
    if (collide(list_obs, player) == 1)
        return (1);
    if (collide(list_obs, player) == 2)
        return (3);
    if (check_win(player, list_obs->girl) == 1)
        return (2);
    return (0);
}

int check_win(struct character *player, list *list)
{
    element *girl = malloc(sizeof(*girl));

    girl = list->first;
    if (girl == NULL)
        return (0);
    while (girl != NULL) {
        if (player->jump->position.x + player->jump->rectangle.width * 10 >=
            girl->position.x)
            return (1);
        girl = girl->next;
    }
    return (0);
}

void move_dead_player(sfRenderWindow *window,
struct character *player, float step, int rect)
{
    player->run->position.y = (20 * (step * step)) + 10;
    if (player->run->position.y >= 570)
        player->run->position.y = 570;
    else {
        player->run->position.x -= 1.5;
    }
    if (rect % 40 == 0 && rect < 210)
        player->run->rectangle.left += 56;
    else if (rect >= 210) {
        player->run->rectangle.width = 44;
        player->run->rectangle.left = 236;
        player->run->rectangle.top = 140;
    }
    sfSprite_setPosition(player->run->sprite, player->run->position);
    sfSprite_setTextureRect(player->run->sprite, player->run->rectangle);
    sfRenderWindow_drawSprite(window, player->run->sprite, NULL);
}

int player_die(sfRenderWindow *window, struct character *player, int reset)
{
    static float step = 0;
    static int tmp = 0;
    static int rect = 0;

    if (reset == 1) {
        step = 0;
        tmp = 0;
        rect = 0;
        return (0);
    }
    if (tmp == 0) {
        player->run->rectangle = int_to_rect(3, 117, 53, 21);
        step = (player->jump->position.y >= 530) ? -5 : -3;
        tmp++;
    }
    step = step + 0.05;
    rect++;
    move_dead_player(window, player, step, rect);
    if (rect >= 210)
        return (1);
    return (0);
}

int player_win(sfRenderWindow *window, struct character *player, int reset)
{
    static int *par = NULL;

    if (reset == 1) {
        par = create_par();
        return (0);
    }
    (par == NULL) ? par = create_par() : par;
    if (par[0] == 0) {
        player->run->rectangle = int_to_rect(3, 3, 17, 19);
        par[0]++;
    }
    par[1]++;
    if (par[1] % 20 == 0)
        player->run->rectangle.left += 20;
    else if (par[1] >= 310) {
        par[1] = 0;
        player->run->rectangle.left = 3;
        par[2] = 1;
    }
    display_sprite(window, player);
    return (par[2]);
}