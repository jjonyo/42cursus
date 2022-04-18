/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <student.42seoul.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 02:06:43 by jonghpar          #+#    #+#             */
/*   Updated: 2022/04/19 02:42:19 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_map(char *path, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd <= 0)
		error("file open error");
	line = get_next_line(fd);
	game->width = ft_strlen(line) - 1;
	game->height = 1;
	game->gain = 0;
	game->str = sl_ft_strdup(line);
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		game->str = sl_ft_strjoin(game->str, line);
		game->height++;
	}
	close(fd);
}

t_img	init_img(void *mlx)
{
	t_img	ret;
	int		width;
	int		height;

	ret.player = mlx_xpm_file_to_image(mlx, PLAYER_PATH, &width, &height);
	ret.target = mlx_xpm_file_to_image(mlx, TARGET_PATH, &width, &height);
	ret.space = mlx_xpm_file_to_image(mlx, SPACE_PATH, &width, &height);
	ret.dest = mlx_xpm_file_to_image(mlx, DEST_PATH, &width, &height);
	ret.wall = mlx_xpm_file_to_image(mlx, WALL_PATH, &width, &height);
	return (ret);
}

void	check_wall(t_game *game)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(game->str);
	while (i < len)
	{
		if (i < game->width)
		{
			if (game->str[i] != '1')
				error("invalid map foramt");
		}
		else if (i % game->width == 0 || i % game->width == game->width - 1)
		{
			if (game->str[i] != '1')
				error("invalid map foramt");
		}
		else if (i >= len - game->width)
		{
			if (game->str[i] != '1')
				error("invalid map foramt");
		}
		i++;
	}
}

void	check_item(t_game *game)
{
	int		i;
	int		exit_count;
	int		player_count;

	i = 0;
	exit_count = 0;
	player_count = 0;
	game->collection = 0;
	while (i++ < ft_strlen(game->str))
	{
		if (game->str[i] == 'E')
			exit_count++;
		else if (game->str[i] == 'P')
			player_count++;
		else if (game->str[i] == 'C')
			game->collection++;
	}
	if (exit_count == 0)
		error("Map must have at least one exit");
	if (game->collection == 0)
		error("Map must have at least one collection");
	if (player_count != 1)
		error("Map must have one starting position");
}

void	check_map(t_game *game)
{
	char	*c;

	if (game->width * game->height != ft_strlen(game->str))
		error("Map must be rectangular");
	c = game->str;
	while (*c)
	{
		if (*c != '1' && *c != '0' && *c != 'E' && *c != 'P' && *c != 'C')
			error("Invalid character in Map");
		c++;
	}	
}
