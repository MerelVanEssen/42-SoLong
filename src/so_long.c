/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:36:59 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/01/12 12:51:56 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	start_program(t_game *game)
{
	get_keys(game);
	put_images_on_screen(game);
	if (game->data.amount_skull > 0)
		mlx_loop_hook(game->data.ptr, handle_skull, game);
	mlx_loop(game->data.ptr);
	return (0);
}

static void	start_xserver(t_game *game)
{
	game->data.ptr = mlx_init();
	if (!game->data.ptr)
	{
		perror("Error\n");
		exit(free_map(game));
	}
	game->data.win = mlx_new_window(game->data.ptr, game->data.width * SIZE,
			(game->data.height + 1) * SIZE, "So Long");
	if (!game->data.win)
	{
		perror("Error\n");
		mlx_destroy_display(game->data.ptr);
		free(game->data.ptr);
		exit (free_map(game));
	}
	return ;
}

static t_game	start(void)
{
	t_game	new;

	new.data.ptr = NULL;
	new.data.win = NULL;
	new.data.amount_coin = 0;
	new.data.amount_skull = 0;
	new.data.map = NULL;
	new.data.width = 0;
	new.data.height = 0;
	new.data.moves = 0;
	return (new);
}

int	main(int argc, char **argv)
{
	t_game	game;	

	if (argc != 2)
		return (ft_putstr_fd("Error\nNo arg", 2), 1);
	game = start();
	prepare_map(&game, argv[1]);
	start_xserver(&game);
	if (prepare_images(&game))
		return (finish_program(&game, 1));
	if (game.data.amount_skull > 0)
	{
		if (get_img_skull(&game))
		{
			game.data.amount_skull = 0;
			return (finish_program(&game, 2));
		}
		if (get_skulls(&game))
			return (finish_program(&game, 2));
	}
	start_program(&game);
	finish_program(&game, 2);
	return (0);
}
