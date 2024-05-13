/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:44:47 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/01/12 12:12:47 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	load_images(t_game *game, char *path)
{
	t_img	img;

	img.fault = 0;
	img.img = mlx_xpm_file_to_image(game->data.ptr, path,
			&img.height, &img.width);
	if (!img.img)
	{
		perror("Error\n");
		img.fault = 1;
		return (img);
	}
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	return (img);
}

static int	remove_previous_img(t_game *game, int nr)
{
	if (nr >= 7)
		mlx_destroy_image(game->data.ptr, game->im.right.img);
	if (nr >= 6)
		mlx_destroy_image(game->data.ptr, game->im.left.img);
	if (nr >= 5)
		mlx_destroy_image(game->data.ptr, game->im.exit.img);
	if (nr >= 4)
		mlx_destroy_image(game->data.ptr, game->im.floor.img);
	if (nr >= 3)
		mlx_destroy_image(game->data.ptr, game->im.coin.img);
	if (nr >= 2)
		mlx_destroy_image(game->data.ptr, game->im.wall.img);
	if (nr >= 1)
		mlx_destroy_image(game->data.ptr, game->im.down.img);
	return (1);
}

int	prepare_images(t_game *game)
{
	game->im.down = load_images(game, "./images/down.xpm");
	if (game->im.down.fault == 1)
		return (remove_previous_img(game, 0));
	game->im.wall = load_images(game, "./images/wall.xpm");
	if (game->im.wall.fault == 1)
		return (remove_previous_img(game, 1));
	game->im.coin = load_images(game, "./images/coin.xpm");
	if (game->im.coin.fault == 1)
		return (remove_previous_img(game, 2));
	game->im.floor = load_images(game, "./images/floor.xpm");
	if (game->im.floor.fault == 1)
		return (remove_previous_img(game, 3));
	game->im.exit = load_images(game, "./images/exit.xpm");
	if (game->im.exit.fault == 1)
		return (remove_previous_img(game, 4));
	game->im.left = load_images(game, "./images/left.xpm");
	if (game->im.left.fault == 1)
		return (remove_previous_img(game, 5));
	game->im.right = load_images(game, "./images/right.xpm");
	if (game->im.right.fault == 1)
		return (remove_previous_img(game, 6));
	game->im.up = load_images(game, "./images/up.xpm");
	if (game->im.up.fault == 1)
		return (remove_previous_img(game, 7));
	return (0);
}
