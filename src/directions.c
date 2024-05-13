/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 10:47:09 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/01/12 12:03:23 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <time.h>

static int	crash(t_game *game, int y, int x)
{
	int	nr;

	if (game->data.amount_skull == 0)
		return (0);
	nr = 0;
	while (nr < game->data.amount_skull)
	{
		if (game->skull[nr].y == y && game->skull[nr].x == x)
		{
			ft_printf("GAME OVER!\n");
			exit (finish_program(game, 2));
		}
		nr++;
	}
	return (0);
}

int	go_left(t_game *game, int y, int x, char **map)
{
	crash(game, y, x - 1);
	if (map[y][x - 1] == '1' || map[y][x - 1] == 'E')
	{
		if (map[y][x - 1] == 'E' && game->data.amount_coin == 0)
		{
			ft_printf("FINISH!\n");
			exit(finish_program(game, 2));
		}
		return (0);
	}
	else if (map[y][x - 1] == '.' || map[y][x - 1] == 'M')
	{
		if (game->data.map[y][x - 1] == 'M')
			game->data.amount_coin--;
		game->pers.x--;
	}
	game->data.map[y][x] = '.';
	mlx_put_image_to_window(game->data.ptr, game->data.win, game->im.left.img,
		game->pers.x * SIZE, game->pers.y * SIZE);
	place_image(game, game->pers.y * SIZE, (game->pers.x + 1) * SIZE,
		game->data.map[game->pers.y][game->pers.x + 1]);
	game->data.moves++;
	ft_printf("Moves: %d\n", game->data.moves);
	return (0);
}

int	go_right(t_game *game, int y, int x, char **map)
{
	crash(game, y, x + 1);
	if (map[y][x + 1] == '1' || map[y][x + 1] == 'E')
	{
		if (map[y][x + 1] == 'E' && game->data.amount_coin == 0)
		{
			ft_printf("FINISH!\n");
			exit(finish_program(game, 2));
		}
		return (0);
	}
	else if (map[y][x + 1] == '.' || map[y][x + 1] == 'M')
	{
		if (game->data.map[y][x + 1] == 'M')
			game->data.amount_coin--;
		game->pers.x++;
	}
	game->data.map[y][x] = '.';
	mlx_put_image_to_window(game->data.ptr, game->data.win, game->im.right.img,
		game->pers.x * SIZE, game->pers.y * SIZE);
	place_image(game, game->pers.y * SIZE, (game->pers.x - 1) * SIZE,
		game->data.map[game->pers.y][game->pers.x - 1]);
	game->data.moves++;
	ft_printf("Moves: %d\n", game->data.moves);
	return (0);
}

int	go_up(t_game *game, int y, int x, char **map)
{
	crash(game, y - 1, x);
	if (map[y - 1][x] == '1' || map[y - 1][x] == 'E')
	{
		if (map[y - 1][x] == 'E' && game->data.amount_coin == 0)
		{
			ft_printf("FINISH!\n");
			exit(finish_program(game, 2));
		}
		return (0);
	}
	else if (map[y - 1][x] == '.' || map[y - 1][x] == 'M')
	{
		if (game->data.map[y - 1][x] == 'M')
			game->data.amount_coin--;
		game->pers.y--;
	}
	game->data.map[y][x] = '.';
	mlx_put_image_to_window(game->data.ptr, game->data.win, game->im.up.img,
		game->pers.x * SIZE, game->pers.y * SIZE);
	place_image(game, (game->pers.y + 1) * SIZE, game->pers.x * SIZE,
		game->data.map[game->pers.y + 1][game->pers.x]);
	game->data.moves++;
	ft_printf("Moves: %d\n", game->data.moves);
	return (0);
}

int	go_down(t_game *game, int y, int x, char **map)
{
	crash(game, y + 1, x);
	if (map[y + 1][x] == '1' || map[y + 1][x] == 'E')
	{
		if (map[y + 1][x] == 'E' && game->data.amount_coin == 0)
		{
			ft_printf("FINISH!\n");
			exit(finish_program(game, 2));
		}
		return (0);
	}
	else if (map[y + 1][x] == '.' || map[y + 1][x] == 'M')
	{
		if (game->data.map[y + 1][x] == 'M')
			game->data.amount_coin--;
		game->pers.y++;
	}
	game->data.map[y][x] = '.';
	mlx_put_image_to_window(game->data.ptr, game->data.win, game->im.down.img,
		game->pers.x * SIZE, game->pers.y * SIZE);
	place_image(game, (game->pers.y - 1) * SIZE, game->pers.x * SIZE,
		game->data.map[game->pers.y - 1][game->pers.x]);
	game->data.moves++;
	ft_printf("Moves: %d\n", game->data.moves);
	return (0);
}
