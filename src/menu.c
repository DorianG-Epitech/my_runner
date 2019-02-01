/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** menu
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

struct menu_obj *create_menu(void)
{
    struct menu_obj *object = malloc(sizeof(*object));

    object->menu_background = create_object("assets/Image/menu.png",
    float_to_vec(0, 0), int_to_rect(3, 2, 240, 135));
    sfSprite_setScale(object->menu_background->sprite, float_to_vec(8, 6.7));
    object->play = create_object("assets/Image/button.png",
    float_to_vec(100, 200), int_to_rect(0, 0, 190, 49));
    sfSprite_setScale(object->play->sprite, float_to_vec(2, 2));
    object->how_rest = create_object("assets/Image/button.png",
    float_to_vec(100, 400), int_to_rect(0, 50, 190, 49));
    sfSprite_setScale(object->how_rest->sprite, float_to_vec(2, 2));
    object->exit = create_object("assets/Image/button.png",
    float_to_vec(100, 600), int_to_rect(0, 150, 190, 49));
    sfSprite_setScale(object->exit->sprite, float_to_vec(2, 2));
    object->panel = create_object("assets/Image/panel.png",
    float_to_vec(720, 220), int_to_rect(0, 0, 3000, 2000));
    sfSprite_setScale(object->panel->sprite, float_to_vec(0.3, 0.3));
    object->help = create_object("assets/Image/help.png",
    float_to_vec(230, 70), int_to_rect(0, 0, 720, 305));
    sfSprite_setScale(object->help->sprite, float_to_vec(2.5, 2.5));
    return (object);
}

int detect_click(sfRenderWindow *window, struct game_object *button)
{
    sfIntRect *mouse = malloc(sizeof(*mouse));
    sfIntRect *button_rect = malloc(sizeof(*button_rect));

    mouse->left = sfMouse_getPositionRenderWindow(window).x;
    mouse->top = sfMouse_getPositionRenderWindow(window).y;
    mouse->width = 1;
    mouse->height = 1;
    button_rect->left = button->position.x;
    button_rect->top = button->position.y;
    button_rect->width = button->rectangle.width * 2;
    button_rect->height = button->rectangle.height * 2;
    if (sfIntRect_intersects(mouse, button_rect, NULL))
        button->rectangle.left = 191;
    else
        button->rectangle.left = 0;
    sfSprite_setTextureRect(button->sprite, button->rectangle);
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        sfIntRect_intersects(mouse, button_rect, NULL))
        return (1);
    return (0);
}

int detect_over(sfRenderWindow *window, struct game_object *button)
{
    sfIntRect *mouse = malloc(sizeof(*mouse));
    sfIntRect *button_rect = malloc(sizeof(*button_rect));

    mouse->left = sfMouse_getPositionRenderWindow(window).x;
    mouse->top = sfMouse_getPositionRenderWindow(window).y;
    mouse->width = 1;
    mouse->height = 1;
    button_rect->left = button->position.x;
    button_rect->top = button->position.y;
    button_rect->width = button->rectangle.width * 2;
    button_rect->height = button->rectangle.height * 2;
    if (sfIntRect_intersects(mouse, button_rect, NULL))
        return (1);
    return (0);
}

int display_menu(sfRenderWindow *window, struct menu_obj *menu)
{
    sfRenderWindow_drawSprite(window, menu->menu_background->sprite, NULL);
    sfRenderWindow_drawSprite(window, menu->play->sprite, NULL);
    sfRenderWindow_drawSprite(window, menu->how_rest->sprite, NULL);
    sfRenderWindow_drawSprite(window, menu->exit->sprite, NULL);
    sfRenderWindow_drawSprite(window, menu->panel->sprite, NULL);
    if (detect_over(window, menu->how_rest) == 1)
        sfRenderWindow_drawSprite(window, menu->help->sprite, NULL);
    sfRenderWindow_display(window);
    if (detect_click(window, menu->play) == 1 ||
        sfKeyboard_isKeyPressed(sfKeyReturn))
        return (1);
    if (detect_click(window, menu->exit) == 1 ||
        sfKeyboard_isKeyPressed(sfKeyEscape))
        return (2);
    return (0);
}