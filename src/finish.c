/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:29:45 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/01/12 12:13:07 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->data.map[i])
	{
		free (game->data.map[i]);
		i++;
	}
	free(game->data.map);
	return (1);
}

void	*free_images(t_game *game)
{
	if (game->im.coin.img)
		mlx_destroy_image(game->data.ptr, game->im.coin.img);
	if (game->im.wall.img)
		mlx_destroy_image(game->data.ptr, game->im.wall.img);
	if (game->im.down.img)
		mlx_destroy_image(game->data.ptr, game->im.down.img);
	if (game->im.exit.img)
		mlx_destroy_image(game->data.ptr, game->im.exit.img);
	if (game->im.floor.img)
		mlx_destroy_image(game->data.ptr, game->im.floor.img);
	if (game->im.left.img)
		mlx_destroy_image(game->data.ptr, game->im.left.img);
	if (game->im.right.img)
		mlx_destroy_image(game->data.ptr, game->im.right.img);
	if (game->im.up.img)
		mlx_destroy_image(game->data.ptr, game->im.up.img);
	return (NULL);
}

int	finish_program(t_game *game, int nr)
{
	if (game->data.map)
		free_map(game);
	if (nr > 1)
		free_images(game);
	if (game->data.amount_skull > 0 && nr > 1)
	{
		mlx_destroy_image(game->data.ptr, game->im.skull.img);
		free(game->skull);
	}
	mlx_destroy_window(game->data.ptr, game->data.win);
	mlx_destroy_display(game->data.ptr);
	free(game->data.ptr);
	return (1);
}
