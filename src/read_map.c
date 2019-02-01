/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** read_map
*/

#include <stddef.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"

#define READ_SIZE 500

void add_obs(int x, int y, char c, list *obs)
{
    if (c == 'O') {
        insert(obs, "assets/Image/bush.png", float_to_vec(x, y),
        int_to_rect(300, 40, 125, 95));
        sfSprite_setScale(obs->first->sprite, float_to_vec(3, 3));
    }
    if (c == 'U') {
        insert(obs, "assets/Image/hole.png", float_to_vec(x, y - 90),
        int_to_rect(0, 0, 430, 300));
    }
}

void add_bear(int x, int y, char c, list *bear)
{
    static int sprite_bear = 3;

    if (c == 'X') {
        insert(bear, "assets/Image/bear.png", float_to_vec(x, y - 220),
        int_to_rect(sprite_bear, 182, 41, 38));
        sfSprite_setScale(bear->first->sprite, float_to_vec(13, 13));
        sprite_bear = (sprite_bear > 135) ? 3 : sprite_bear + 44;
    }
}

void add_bat(int x, int y, char c, list *bat)
{
    static int sprite_bat = 3;

    if (c == 'H') {
        insert(bat, "assets/Image/bat.png", float_to_vec(x, y),
        int_to_rect(sprite_bat, 385, 79, 57));
        sfSprite_setScale(bat->first->sprite, float_to_vec(7, 7));
        sprite_bat = (sprite_bat > 657) ? 3 : sprite_bat + 82;
    }
}

void add_girl(int x, int y, char c, list *girl)
{
    if (c == 'V') {
        insert(girl, "assets/Image/girl.png", float_to_vec(x, y + 40),
        int_to_rect(2, 25, 16, 19));
        sfSprite_setScale(girl->first->sprite, float_to_vec(10, 10));
    }
}

char **read_map(char *str, obstacle_list *list)
{
    char *buffer = malloc(sizeof(char) * READ_SIZE);
    int fd = open(str, O_RDONLY);
    int y = 0;
    int x = 0;
    int len = read(fd, buffer, READ_SIZE);

    buffer[len] = '\0';
    for (int count = 0; buffer[count] != '\0'; count++) {
        x += 200;
        add_obs(x, y, buffer[count], list->obs);
        add_bear(x, y, buffer[count], list->bear);
        add_bat(x, y, buffer[count], list->bat);
        add_girl(x, y, buffer[count], list->girl);
        if (buffer[count] == '\n') {
            y += 250;
            x = 0;
        }
    }
}