/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:37:12 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/01/12 11:43:13 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <X11/X.h>
# include <errno.h>
# include <X11/keysym.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

# ifndef SIZE
#  define SIZE 40
# endif

typedef struct s_img
{
	int		fault;
	void	*img;
	int		height;
	int		width;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_im
{
	t_img	wall;
	t_img	coin;
	t_img	exit;
	t_img	floor;
	t_img	pers;
	t_img	skull;
	t_img	left;
	t_img	right;
	t_img	up;
	t_img	down;
}	t_im;

typedef struct s_found
{
	int		coins;
	int		exit;
}	t_found;

typedef struct s_pers
{
	int	y;
	int	x;
	int	coins;
}	t_pers;

typedef struct s_skull
{
	int	y;
	int	x;
}	t_skull;

typedef struct s_data
{
	void	*ptr;
	void	*win;
	int		amount_coin;
	int		amount_skull;
	char	**map;
	int		width;
	int		height;
	int		moves;
}	t_data;

typedef struct s_game
{
	t_data	data;
	t_im	im;
	t_pers	pers;
	t_skull	*skull;
	t_found	found;
}	t_game;

int		main(int argc, char **argv);
void	place_image(t_game *game, int y, int x, char c);

// prepare map
void	prepare_map(t_game *game, char *ber);

// get images
t_img	load_images(t_game *game, char *path);
int		prepare_images(t_game *game);

// images to window
void	put_images_on_screen(t_game *game);
void	place_image(t_game *game, int y, int x, char c);

// get keys
int		get_keys(t_game *game);

// directions
int		go_left(t_game *game, int y, int x, char **map);
int		go_right(t_game *game, int y, int x, char **map);
int		go_up(t_game *game, int y, int x, char **map);
int		go_down(t_game *game, int y, int x, char **map);

// validate 1
int		check_icons(t_game *game);
int		check_wall(t_game *game);

// validate 2
int		check_reach(t_game *game);

// finish
int		finish_program(t_game *game, int nr);
void	*free_images(t_game *game);
int		free_map(t_game *game);

// skull
int		get_skulls(t_game *game);
int		get_img_skull(t_game *game);

// move skulls
int		handle_skull(t_game *game);

#endif