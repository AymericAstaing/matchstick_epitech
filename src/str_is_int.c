/*
** EPITECH PROJECT, 2018
** str_is_int.c
** File description:
** CPE_matchstick_2017
*/

#include "my.h"

int	str_is_int(char *str)
{
	for (int i = 0; str[i]; i++) {
		if (str[i] < 48 || str[i] > 57)
			return (0);
	}
	return (1);
}
