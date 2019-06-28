/*
** EPITECH PROJECT, 2018
** check_input.c
** File description:
** CPE_matchstick_2017
*/

#include "my.h"
#include "stdio.h"

int	check_input(int line, int number_match, game *game)
{
	if (game->matches[line - 1] < number_match)
		return (0);
	game->matches[line - 1] = (game->matches[line -1]) - number_match;
	game->initial[line - 1] = (game->initial[line -1]) + number_match;
	my_putstr("Player removed ");
	my_put_nbr(number_match);
	my_putstr(" match(es) from line ");
	my_put_nbr(line);
	my_putchar('\n');
	update_map(game);
	my_putchar('\n');
	return (1);
}
