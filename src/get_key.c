/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:44:27 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/01/12 11:38:32 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "time.h"

int	putnr(t_game *game)
{
	char	*str;

	mlx_put_image_to_window(game->data.ptr, game->data.win,
		game->im.wall.img, 0, 0);
	mlx_string_put(game->data.ptr, game->data.win, 5, 15, 0, "Moves");
	str = ft_itoa(game->data.moves + 1);
	if (!str)
	{
		perror("Error\n");
		exit(finish_program(game, 2));
	}
	mlx_string_put(game->data.ptr, game->data.win, 5, 30, 0, str);
	free (str);
	return (0);
}

static int	key_press(int keysym)
{
	if (keysym == XK_Left || keysym == XK_a
		|| keysym == XK_Up || keysym == XK_w
		|| keysym == XK_Right || keysym == XK_d
		|| keysym == XK_Down || keysym == XK_s)
		return (1);
	return (0);
}

static int	handle_key(int keysym, t_game *game)
{
	if (key_press(keysym))
		putnr(game);
	if (keysym == XK_Escape)
		exit (finish_program(game, 2));
	if (keysym == XK_Left || keysym == XK_a)
	{
		if (go_left(game, game->pers.y, game->pers.x, game->data.map))
			exit (finish_program(game, 2));
	}
	if (keysym == XK_Up || keysym == XK_w)
	{
		if (go_up(game, game->pers.y, game->pers.x, game->data.map))
			exit (finish_program(game, 2));
	}
	if (keysym == XK_Right || keysym == XK_d)
	{
		if (go_right(game, game->pers.y, game->pers.x, game->data.map))
			exit (finish_program(game, 2));
	}
	if (keysym == XK_Down || keysym == XK_s)
	{
		if (go_down(game, game->pers.y, game->pers.x, game->data.map))
			exit (finish_program(game, 2));
	}
	return (0);
}

static int	fin(t_game *game)
{
	finish_program(game, 2);
	exit (1);
}

int	get_keys(t_game *game)
{
	mlx_key_hook(game->data.win, handle_key, game);
	mlx_hook(game->data.win, DestroyNotify, StructureNotifyMask, fin, game);
	return (0);
}
