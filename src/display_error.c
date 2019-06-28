/*
** EPITECH PROJECT, 2018
** display_error.c
** File description:
** CPE_matchstick_2017
*/

#include "my.h"
#include <stdlib.h>

int    display_error(char *s, int l, game *game)
{
	if (str_is_int(s) == 0) {
		my_putstr("Error: invalid input");
		my_putstr("(positive number expected)\nLine: ");
		return (0);
	}
	if (atoi(s) <= 0) {
		my_putstr("Error: you have to remove at ");
		my_putstr("least one match\nLine: ");
		return (0);
	}
	if (atoi(s) > game->max_matches) {
		my_putstr("Error: you cannot remove more than ");
		my_put_nbr(game->max_matches);
		my_putstr(" matches per turn\nLine: ");
		return (0);
	}
	if (atoi(s) > (game->matches[l - 1])) {
		my_putstr("Error: not enough matches on this line\nLine: ");
		return (0);
	}
	return (0);
}
