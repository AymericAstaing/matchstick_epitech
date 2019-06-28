/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** CPE_matchstick_2017
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	ia_talk(int c_matches, int c_line)
{
	my_putstr("AI's turn...\n");
	my_putstr("AI removed ");
	my_put_nbr(c_matches);
	my_putstr(" match(es) from line ");
	my_put_nbr(c_line + 1);
	my_putchar('\n');
}

int	ia_input(game *game)
{
	int	choosen_line = -1;
	int	choosen_nbr_matches = 0;
	int	max_matches = 0;

	while (game->matches[choosen_line] == 0)
		choosen_line = get_random(0, (game->map_line) - 1);
	max_matches = game->matches[choosen_line];
	if (max_matches > 1)
		choosen_nbr_matches = get_random(1, max_matches);
	else
		choosen_nbr_matches = max_matches;
	if (choosen_nbr_matches == 0)
		choosen_nbr_matches++;
	ia_talk(choosen_nbr_matches, choosen_line);
	game->matches[choosen_line] = (game->matches[choosen_line]) - choosen_nbr_matches;
	game->initial[choosen_line] = (game->initial[choosen_line]) + choosen_nbr_matches;
	update_map(game);
	return (0);
}

int    user_input(game *game)
{
	char    *s;
	int     l = 0;
	int	e = 0;
	int	j = 0;

	my_putstr("\nYour turn:\nLine: ");
	while (!j) {
		s = get_next_line(0);
		if (e == 0) {
			if (atoi(s) > 0 && atoi(s) <= (game->map_line)) {
				l = atoi(s);
				e = 1;
				my_putstr("Matches: ");
			} else {
				my_putstr("Error: this line is out of range\nLine: ");
			}
		} else {
			if (atoi(s) > 0 && atoi(s) <= (game->matches[l - 1]) && atoi(s) <= game->max_matches) {
				check_input(l, atoi(s), game);
				return (0);
			} else {
				e = 0;
				display_error(s, l, game);
			}
		}
	}
	return (1);
}

int    next_step(game *game)
{
	while (game->game_state != -1) {
		if (game->game_state == 0) {
			if (user_input(game) == 0 && check_end(game) != 1) {
				game->game_state = 1;
			} else {
				end_game(0, game);
				return (2);
			}
		} else  if (game->game_state == 1) {
			if (ia_input(game) == 0 && check_end(game) != 1) {
				game->game_state = 0;
			} else {
				end_game(1, game);
				return (1);
			}
		}

	}
	return (0);
}

int	main(int argc, char *argv[])
{
	game	game;
	int	column = 0;

	if (check_args(argc) == 0)
		return (0);
	column = (2 * atoi(argv[1])) + 1;
	init_struct(&game, atoi(argv[1]), atoi(argv[2]), column);
	for (int i = 1; i < argc; i++) {
		if (str_is_int(argv[i]) == 0) {
			write(2, "Please enter 2 numbers in parameters\n", 39);
			return (84);
		}
	}
	update_map(&game);
	if (next_step(&game) == 2)
		return (2);
	return (1);
}
