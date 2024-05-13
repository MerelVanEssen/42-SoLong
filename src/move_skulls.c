/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_skulls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:33:02 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/01/12 11:44:04 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	replace_images(t_game *game, int y, int x, int nr)
{
	mlx_put_image_to_window(game->data.ptr, game->data.win, game->im.skull.img,
		game->skull[nr].x * SIZE, game->skull[nr].y * SIZE);
	mlx_put_image_to_window(game->data.ptr, game->data.win, game->im.floor.img,
		x * SIZE, y * SIZE);
	usleep(200000);
	return ;
}

static int	good(t_game *game, int y, int x, int nr_skull)
{
	int	nr;

	nr = 0;
	while (nr < game->data.amount_skull && nr != nr_skull)
	{
		if (game->skull[nr].y == y && game->skull[nr].x == x)
			return (0);
		nr++;
	}
	if (game->data.map[y][x] == '1' || game->data.map[y][x] == 'M'
		|| game->data.map[y][x] == 'E')
		return (0);
	return (1);
}

int	die_check(t_game *game, int y, int x, int nr)
{
	if (game->pers.x == game->skull[nr].x
		&& game->pers.y == game->skull[nr].y)
	{
		replace_images(game, y, x, nr);
		usleep(300000);
		ft_printf("GAME OVER!\n");
		exit (finish_program(game, 2));
	}
	return (0);
}

static int	move_skull(t_game *game, int y, int x, int nr)
{
	if ((game->data.moves + nr) % 7 == 0 && good(game, y, x + 1, nr))
	{
		game->skull[nr].x++;
		die_check(game, y, x, nr);
		replace_images(game, y, x, nr);
	}
	else if ((game->data.moves + nr) % 3 == 0 && good(game, y, x - 1, nr))
	{
		game->skull[nr].x--;
		die_check(game, y, x, nr);
		replace_images(game, y, x, nr);
	}
	else if ((game->data.moves + nr) % 5 == 0 && good(game, y + 1, x, nr))
	{
		game->skull[nr].y++;
		die_check(game, y, x, nr);
		replace_images(game, y, x, nr);
	}
	else if ((game->data.moves + nr) % 4 == 0 && good(game, y - 1, x, nr))
	{
		game->skull[nr].y--;
		die_check(game, y, x, nr);
		replace_images(game, y, x, nr);
	}
	return (0);
}

int	handle_skull(t_game *game)
{
	int	nr;

	nr = 0;
	while (nr < game->data.amount_skull)
	{
		game->data.map[game->skull[nr].y][game->skull[nr].x] = '.';
		move_skull(game, game->skull[nr].y, game->skull[nr].x, nr);
		nr++;
	}
	return (0);
}
