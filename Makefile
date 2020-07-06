##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c			\
		src/struct/set.c		\
		src/struct/set_hero.c		\
		src/struct/set_background.c	\
		src/struct/set_background_game.c\
		src/struct/set_map.c		\
		src/struct/infinity_map.c	\
		src/struct/create_map.c		\
		src/struct/set_map_sprite.c	\
		src/struct/destroy.c		\
		src/game/high_score.c		\
		src/game/display.c		\
		src/game/event.c		\
		src/game/event_game.c		\
		src/game/display_info.c		\
		src/game/background_game.c	\
		src/game/hero.c			\
		src/game/hit_box.c		\
		src/map/map.c			\
		src/map/display_move_enemy.c	\
		src/map/display_move_enemy_hit.c\
		src/map/display_move_barrier.c	\
		src/lib/my_str_to_word_array.c	\
		src/lib/my_inttoa.c		\
		src/lib/get_next_line.c		\
		src/lib/my_strcat.c		\
		src/lib/my_strlen.c		\
		src/lib/my_strcmp.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

RM	=	rm -f

CFLAGS	= 	-W -Wall -Wextra -I./include

NAME	=	my_runner

ifeq ($(debug), 1)
	CFLAGS += -g
endif

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
