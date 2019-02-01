##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## 103Cipher
##

SRC	=	obstacle/obstacle.c			\
		src/player.c			\
		scrolling/parallax.c			\
		src/initialisation.c	\
		src/display.c			\
		src/linked_list.c		\
		src/read_map.c			\
		obstacle/bear_bat.c			\
		obstacle/animation.c			\
		obstacle/collide.c			\
		obstacle/collide_bis.c			\
		src/score.c \
		src/end_game.c	\
		src/end_game_bis.c	\
		src/menu.c\
		src/function.c	\

OBJ = $(SRC:.c=.o)

NAME = my_runner

CFLAGS = -lm -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio -I./include -g

$(NAME) :	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

all: $(NAME)

clean :
		$(RM) -f *~
		$(RM) $(OBJ)
		$(RM) $(NAME)

fclean :clean
		$(RM) $(NAME)

re : fclean all
