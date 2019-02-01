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

int hole_or_other(sfRenderWindow *window, struct character *player,
struct parallax *back, obstacle_list *list_obs)
{
    if (determine_end(list_obs, player) == 1) {
        display_after(window, back, list_obs);
        if (player_die(window, player, 0) == 1)
            return (1);
        display_front(window, back);
    }
    if (determine_end(list_obs, player) == 3) {
        display_after(window, back, list_obs);
        if (player_fall(window, player) == 1)
            return (1);
        display_front(window, back);
    }
    return (0);
}