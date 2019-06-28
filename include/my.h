/*
1;5002;0c** EPITECH PROJECT, 2017
** CPE_matchstick_2017
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

int		main();
int		check_args(int argc);
void	my_putstr(char const *str);
void	my_putchar(char c);
int		check_input();
int		str_is_int(char *str);
int		is_pair(int c);
int     my_put_nbr(int nb);
int     get_random(int min, int max);
char 	*get_next_line(const int fd);

typedef struct game {
	int		game_state;
	int		map_line; 
	int		total_match_number;
	int		map_column;
	int		max_matches;
	char	*matches;
	char	*initial;
} game;

int	check_end(game *game);
void    init_struct(game *game, int line, int match, int column);
int     check_input(int line, int number_match, game *game);
void	update_map(game *game);
int		display_error(char *s, int l, game *game);
void	end_game(int a, game *game);
#endif	/*MY_H_*/
