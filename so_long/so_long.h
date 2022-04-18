/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <student.42seoul.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:20:04 by jonghpar          #+#    #+#             */
/*   Updated: 2022/04/19 02:43:08 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "./mlx/mlx.h"
# include "./gnl/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct s_img {
	void	*player;
	void	*target;
	void	*dest;
	void	*space;
	void	*wall;
}				t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		width;
	int		height;
	int		walk;
	int		gain;
	int		collection;
	char	*str;
}			t_game;

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3
# define X_EVENT_KEY_EXIT		17
# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

# define PLAYER_PATH "./img/player.xpm"
# define TARGET_PATH "./img/collection.xpm"
# define DEST_PATH "./img/dest.xpm"
# define SPACE_PATH "./img/space.xpm"
# define WALL_PATH "./img/wall.xpm"
# define IMAGE_SIZE 64

char	*sl_ft_strdup(char *s);
int		sl_ft_strlcpy(char *dst, char *src, int len);
char	*sl_ft_strjoin(char *s1, char *s2);
t_img	init_img(void *mlx);
void	parse_map(char *path, t_game *game);
void	check_wall(t_game *game);
void	check_item(t_game *game);
void	check_map(t_game *game);
void	move_player_to_w(t_game *game);
void	move_player_to_s(t_game *game);
void	move_player_to_a(t_game *game);
void	move_player_to_d(t_game *game);
void	put_image(t_game *game, int h, int w);
void	render_image(t_game *game);
void	error(char *msg);
int		exit_game(t_game *game);
int		clear_game(t_game *game);
int		key_hook(int key, t_game *game);
#endif
