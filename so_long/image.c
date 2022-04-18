/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <student.42seoul.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 02:14:16 by jonghpar          #+#    #+#             */
/*   Updated: 2022/04/19 02:24:01 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_game *game, int h, int w)
{
	int		idx;

	idx = h * game->width + w;
	if (game->str[idx] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img.dest,
			w * IMAGE_SIZE, h * IMAGE_SIZE);
	else if (game->str[idx] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img.target,
			w * IMAGE_SIZE, h * IMAGE_SIZE);
	else if (game->str[idx] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img.wall,
			w * IMAGE_SIZE, h * IMAGE_SIZE);
	else if (game->str[idx] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->img.player,
			w * IMAGE_SIZE, h * IMAGE_SIZE);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->img.space,
			w * IMAGE_SIZE, h * IMAGE_SIZE);
}

void	render_image(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			put_image(game, i, j);
			j++;
		}
		i++;
	}
}
