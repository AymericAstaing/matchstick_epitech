##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## CPE_matchstick_2017
##

CFLAGS  +=      -Wall -Werror -Wextra
CFLAGS  +=      -I./include

SRC     +=      ./src/main.c			\
		./src/is_pair.c			\
		./src/display_error.c		\
		./src/end_game.c		\
		./src/check_end.c		\
		./src/get_next_line.c		\
		./src/get_random.c		\
		./src/my_put_nbr.c		\
		./src/check_args.c		\
		./src/update_map.c		\
		./src/init_struct.c		\
		./src/check_input.c		\
		./src/str_is_int.c		\
		./src/my_putchar.c		\
		./src/my_putstr.c

NAME    =       matchstick

all:            $(NAME)

$(NAME):
	gcc -g3 -o $(NAME) $(SRC) $(CFLAGS)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re:     fclean all

.PHONY: clean fclean re all
