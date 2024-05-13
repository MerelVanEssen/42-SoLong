/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_to_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 08:05:57 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/01/12 11:07:28 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_image(t_game *game, int y, int x, char c)
{
	void	*ptr;
	void	*win;

	ptr = game->data.ptr;
	win = game->data.win;
	if (c == '.' || c == '0' || c == 'S')
		mlx_put_image_to_window(ptr, win, game->im.floor.img, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(ptr, win, game->im.exit.img, x, y);
	else if (c == 'M')
		mlx_put_image_to_window(ptr, win, game->im.coin.img, x, y);
	else if (c == '1')
		mlx_put_image_to_window(ptr, win, game->im.wall.img, x, y);
	else if (c == 'B')
		mlx_put_image_to_window(ptr, win, game->im.skull.img, x, y);
	return ;
}

void	put_images_on_screen(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= game->data.height)
	{
		while (game->data.map[i][j])
		{
			if (i == game->pers.y && j == game->pers.x)
				mlx_put_image_to_window(game->data.ptr, game->data.win,
					game->im.down.img, j * SIZE, i * SIZE);
			else
				place_image(game, i * SIZE, j * SIZE, game->data.map[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
}
