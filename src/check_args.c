/*
** EPITECH PROJECT, 2018
** check_args.c
** File description:
** CPE_matchstick_2017
*/

#include "my.h"
#include <stdlib.h>

int	check_args(int argc)
{
	if (argc != 3) {
		my_putstr("Please enter two requested parameters");
		my_putstr("(number of lines (1-100), max matches per turn).\n");
		return (0);
	}
       	return (1);
}
