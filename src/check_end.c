/*
** EPITECH PROJECT, 2018
** check_end.c
** File description:
** CPE_matchstick_2017
*/

#include "my.h"

int	check_end(game *game)
{
	int	line = (game->map_line) - 1;
	int	end = game->map_line;

	for (int i = 0; i <= line; i++) {
		if (game->matches[i] == 0)
			end--;
	}
	if (end == 0)
		return (1);
	return (0);
}
