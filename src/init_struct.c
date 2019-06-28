/*
** EPITECH PROJECT, 2018
** init_struct.c
** File description:
** CPE_matchsticl_2017
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

int	get_match_nbr(int line)
{
	int match_nbr = 1;
	int saved_nbr = 3;

	if (line == 1)
		return (line);
	for (int i = 1; i < line; i++) {
		match_nbr += saved_nbr;
		saved_nbr += 2;
	}
	return (match_nbr);
}

void    init_struct(game *game, int line, int match, int column)
{
	int	current_nb = 1;
	int match_nbr = get_match_nbr(line);

	game->max_matches = match;
	game->game_state = 0;
	game->map_column = column;
	game->map_line = line;
	game->matches = malloc(sizeof(char) * match_nbr);
	game->initial = malloc(sizeof(char) * match_nbr);
	for (int i = 0; i < match_nbr; i++)
		game->initial[i] = 0;
	for (int i = 0; i < line; i++) {
		game->matches[i] = current_nb;
		current_nb = current_nb + 2;
	}
}
