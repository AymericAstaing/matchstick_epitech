/*
** EPITECH PROJECT, 2018
** get_random.c
** File description:
** CPE_matchstick_2017
*/

#include "my.h"
#include <stdlib.h>

int	get_random(int min, int max)
{
	return (random() % (max + 1 - min) + 0);
}
