/*
** EPITECH PROJECT, 2018
** update_map.c
** File description:
** CPE_matchstick_2017
*/

#include "my.h"
#include <stdio.h>

void	print_char(int l, int c, int m_line, int m_col)
{
	if (l == 0 || l == m_line - 1)
		my_putchar('*');
	else if (c == 0 || c == m_col)
		my_putchar('*');
	else
		my_putchar(' ');
}

void	update_map(game *game)
{
	int     g = ((game->map_column) / 2);
	int	l = (game->map_line) + 2;
	int	c = (game->map_column) - 1;
	int	n_g = 0;

	for (int i = 0; i < l; i++) {
		for (int e = 0; e < (c + 1); e++) {
			if (i > 0)
				n_g = (c - (g + (game->initial[i - 1])));
			if (i > 0 && i < l && i <= l - 2 && e > g && e < n_g) {
				my_putchar('|');
			} else {
				print_char(i, e, l, c);
			}
		}
		g--;
		my_putchar('\n');
	}
}
