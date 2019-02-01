/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** score
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

char *my_strcpy(char *dest, char const *src)
{
    int count = 0;
    while (src[count] != '\0') {
        dest[count] = src[count];
        count++;
    }
    dest[count] = '\0';
    return (dest);
}

char *my_strcat(char *dest, char const *src)
{
    int count = 0;
    while (dest[count] != '\0') {
        count = count + 1;
    }
    int a = 0;
    while (src[a] != '\0') {
        dest[count] = src[a];
        count++;
        a++;
    }
    dest[count] = '\0';
    return (dest);
}

char *my_itoa(int nb)
{
    int len = 0;
    char *str;

    for (int a = nb; a > 9; len++)
        a = a / 10;
    str = malloc(sizeof(char) * len + 1);
    str[len + 1] = '\0';
    for (int i = len; i >= 0; i--) {
        str[i] = 48 + (nb % 10);
        nb = nb / 10;
    }
    return (str);
}

void display_score(sfRenderWindow *window, sfText *text, sfFont *font, int par)
{
    static int score = 0;
    char *str = my_strcpy(str, "Score : ");

    if (par == 1) {
        score = 0;
        return;
    }
    sfText_setString(text, my_strcat(str, my_itoa(score)));
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
    sfText_setPosition(text, float_to_vec(25, 0));
    sfRenderWindow_drawText(window, text, NULL);
    score++;
}