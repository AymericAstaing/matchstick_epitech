/*
** EPITECH PROJECT, 2018
** end_game.c
** File description:
** CPE_matchstick_2017
*/

#include "my.h"

void	end_game(int a, game *game)
{
	if (a == 0) {
		my_putstr("You lost, too bad...\n");
		game->game_state = -1;
	} else {
		my_putstr("I lost... snif... but I'll get you next time!!\n");
		game->game_state = -1;
	}
}
