/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <student.42seoul.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 02:12:23 by jonghpar          #+#    #+#             */
/*   Updated: 2022/04/19 02:25:28 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_player(t_game *game)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(game->str);
	while (i < len)
	{
		if (game->str[i] == 'P')
			break ;
		i++;
	}
	return (i);
}

void	move_player_to_w(t_game *game)
{
	int		pos;
	int		next_pos;
	char	next;

	pos = find_player(game);
	next_pos = pos - game->width;
	next = game->str[next_pos];
	if (next == 'C')
		game->gain++;
	if (next == 'E' && game->gain == game->collection)
		clear_game(game);
	else if (next != 'E' && next != '1')
	{
		game->str[pos] = '0';
		game->str[next_pos] = 'P';
		game->walk++;
		printf("step : %d\n", game->walk);
		render_image(game);
	}
}

void	move_player_to_s(t_game *game)
{
	int		pos;
	int		next_pos;
	char	next;

	pos = find_player(game);
	next_pos = pos + game->width;
	next = game->str[next_pos];
	if (next == 'C')
		game->gain++;
	if (next == 'E' && game->gain == game->collection)
		clear_game(game);
	else if (next != 'E' && next != '1')
	{
		game->str[pos] = '0';
		game->str[next_pos] = 'P';
		game->walk++;
		printf("step : %d\n", game->walk);
		render_image(game);
	}
}

void	move_player_to_a(t_game *game)
{
	int		pos;
	int		next_pos;
	char	next;

	pos = find_player(game);
	next_pos = pos - 1;
	next = game->str[next_pos];
	if (next == 'C')
		game->gain++;
	if (next == 'E' && game->gain == game->collection)
		clear_game(game);
	else if (next != 'E' && next != '1')
	{
		game->str[pos] = '0';
		game->str[next_pos] = 'P';
		game->walk++;
		printf("step : %d\n", game->walk);
		render_image(game);
	}
}

void	move_player_to_d(t_game *game)
{
	int		pos;
	int		next_pos;
	char	next;

	pos = find_player(game);
	next_pos = pos + 1;
	next = game->str[next_pos];
	if (next == 'C')
		game->gain++;
	if (next == 'E' && game->gain == game->collection)
		clear_game(game);
	else if (next != 'E' && next != '1')
	{
		game->str[pos] = '0';
		game->str[next_pos] = 'P';
		game->walk++;
		printf("step : %d\n", game->walk);
		render_image(game);
	}
}
