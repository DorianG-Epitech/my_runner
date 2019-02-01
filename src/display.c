/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Base
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

int window_open(sfRenderWindow *window, struct character *player,
struct parallax *back, obstacle_list *list_obs)
{
    if (determine_end(list_obs, player) == 0) {
        parralax_scroll(window, back);
        obstacle_move(window, list_obs->obs);
        player_action(window, player, list_obs->bear);
        animation(window, list_obs);
        front_parralax_scroll(window, back);
    }
    if (hole_or_other(window, player, back, list_obs) == 1)
        return (1);
    if (determine_end(list_obs, player) == 2) {
        display_after(window, back, list_obs);
        if (player_win(window, player, 0) == 1)
            return (2);
        display_front(window, back);
    }
    return (0);
}

struct object_t *create_all_object(void)
{
    struct object_t *object = malloc(sizeof(*object));

    object->player = init_player();
    object->back = init_background();
    object->list_obs = init_obs_list();
    object->menu = create_menu();
    return (object);
}

int end_window(sfRenderWindow *window, int end, struct object_t *object)
{
    int reset = 0;
    if (end == 1 || end == 2) {
        display_front(window, object->back);
        reset = display_win_dead(window,
        object->win_lose, object->menu, end);
        if (reset == 1)
            bear_die(object->list_obs->bear, window, 1);
        return (reset);
    }
    return (0);
}

void my_runner(sfRenderWindow *window, char *map, sfMusic *music)
{
    struct object_t *object = create_all_object();
    static int men = 0;
    
    read_map(map, object->list_obs);
    for (int end = 0; sfRenderWindow_isOpen(window);
    sfRenderWindow_display(window)) {
        if (men == 0)
            men = display_menu(window, object->menu);
        else if (men == 2)
            return;
        else
            end = window_open(window, object->player,
            object->back, object->list_obs);
        if (end_window(window, end, object) == 1) {
            player_win(window, object->player, 1);
            player_die(window, object->player, 1);
            my_runner(window, map, music);
            return;
        } else if (end_window(window, end, object) == 2)
            return;
    }
}

int main(int argc, char **argv)
{
    sfMusic *music = sfMusic_createFromFile("assets/music.ogg");

    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
    sfRenderWindow *window = window_create(2000, 900);
    my_runner(window, argv[1], music);
    sfMusic_destroy(music);
    sfRenderWindow_destroy(window);
}