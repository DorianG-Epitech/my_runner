/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my
*/

#include <stddef.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

enum e_type {
    CHARACTER,
    BACKGROUND,
    GROUND
};

struct game_object {
    enum e_type type;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfIntRect rectangle;
};

struct character {
    struct game_object *run;
    struct game_object *jump;
    struct game_object *roll;
};

struct parallax {
    struct game_object *bg_one;
    struct game_object *bg_two;
    struct game_object *fr_one;
    struct game_object *fr_two;
    struct game_object *gr_one;
    struct game_object *gr_two;
};

struct menu_obj {
    struct game_object *menu_background;
    struct game_object *play;
    struct game_object *how_rest;
    struct game_object *exit;
    struct game_object *panel;
    struct game_object *help;
};

typedef struct element element;
typedef struct list list;
typedef struct obstacle_list obstacle_list;

struct element {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfIntRect rectangle;
    struct element *next;
};

struct list {
    element *first;
};

struct obstacle_list {
    list *obs;
    list *bear;
    list *bat;
    list *girl;
};

struct object_t {
    struct character *player;
    struct parallax *back;
    struct menu_obj *menu;
    struct game_object *win_lose;
    obstacle_list *list_obs;
    list *button;
};

struct character *init_player(void);
struct parallax *init_background(void);
sfVector2f float_to_vec(float x, float y);
sfRenderWindow *window_create(int width, int height);
sfIntRect int_to_rect(int x, int y, int width, int height);
void destroy_object(struct game_object *obj);
struct game_object *create_object(const char *path_to_spritesheet,
sfVector2f pos, sfIntRect rect);
int player_action(sfRenderWindow *window,
struct character *player, list *bear);
int player_roll(sfRenderWindow *window, struct game_object *char_roll);
int player_jump(sfRenderWindow *window,
struct game_object *char_jump);
struct parallax *init_background(void);
void parralax_scroll(sfRenderWindow *window, struct parallax *back);
void front_parralax_scroll(sfRenderWindow *window, struct parallax *back);
float scrolling(sfRenderWindow *window,
struct game_object *object, float speed);
list *init_obstacle(const char *patch,
sfVector2f pos, sfIntRect rect);
void delete_el(list *list);
void display(sfRenderWindow *window, list *list);
void insert(list *list, const char *patch,
sfVector2f pos, sfIntRect rect);
int player_lose(struct character *player, list *obstacle);
void obstacle_move(sfRenderWindow *window, list *list);
void destroy_obstacle(list *list);
char **read_map(char *str, obstacle_list *list);
sfIntRect *int_to_rect_arr(int x, int y, int width, int height);
int anim_bat(sfRenderWindow *window, list *list);
int anim_bear(sfRenderWindow *window, list *list);
void change_frame(sfRenderWindow *window, element *element, int par);
void bear_die(list *list, sfRenderWindow *window, int reset);
int bear_lose(struct game_object *player, list *list);
void animation(sfRenderWindow *window, obstacle_list *list);
obstacle_list *init_obs_list(void);
int collide(obstacle_list *list, struct character *player);
void display_score(sfRenderWindow *window, sfText *text, sfFont *font, int par);
int anim_girl(sfRenderWindow *window, list *list);
int check_win(struct character *player, list *list);
int player_die(sfRenderWindow *window, struct character *player, int reset);
int player_win(sfRenderWindow *window, struct character *player, int reset);
int determine_end(obstacle_list *list_obs, struct character *player);
int display_menu(sfRenderWindow *window, struct menu_obj *menu);
struct menu_obj *create_menu(void);
int detect_click(sfRenderWindow *window, struct game_object *button);
int display_win_dead(sfRenderWindow *window,
struct game_object *win_lose, struct menu_obj *menu, int par);
int player_fall(sfRenderWindow *window, struct character *player);
void display_front(sfRenderWindow *window,
struct parallax *back);
void display_after(sfRenderWindow *window, struct parallax *back,
obstacle_list *list_obs);
int *create_par(void);
void display_sprite(sfRenderWindow *window, struct character *player);
int hole_or_other(sfRenderWindow *window, struct character *player,
struct parallax *back, obstacle_list *list_obs);