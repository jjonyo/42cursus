/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <student.42seoul.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:52:52 by jonghpar          #+#    #+#             */
/*   Updated: 2022/04/19 11:09:16 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	exit(1);
}

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	clear_game(t_game *game)
{
	printf("clear game !! your step : %d\n", game->walk + 1);
	exit(0);
}

int	key_hook(int key, t_game *game)
{
	if (key == KEY_ESC)
		exit_game(game);
	if (key == KEY_W)
		move_player_to_w(game);
	if (key == KEY_S)
		move_player_to_s(game);
	if (key == KEY_A)
		move_player_to_a(game);
	if (key == KEY_D)
		move_player_to_d(game);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (argc != 2)
		error("check the map");
	game = (t_game *)malloc(sizeof(t_game));
	parse_map(argv[1], game);
	check_map(game);
	check_wall(game);
	check_item(game);
	game->mlx = mlx_init();
	game->img = init_img(game->mlx);
	game->win = mlx_new_window(game->mlx, game->width * IMAGE_SIZE,
			game->height * IMAGE_SIZE, "so_long");
	render_image(game);
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 0, &key_hook, game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 0, &exit_game, game);
	mlx_loop(game->mlx);
	return (0);
}
