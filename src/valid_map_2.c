/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:17:08 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/01/12 11:43:58 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	visit(char c)
{
	if (c == '0')
		return ('.');
	else if (c == 'E')
		return ('F');
	else if (c == 'C')
		return ('M');
	else if (c == 'P')
		return ('S');
	return (c);
}

void	recursive_search(t_game *game, int x, int y)
{
	if (game->data.map[y][x] == 'C')
		game->found.coins++;
	if (game->data.map[y][x] == 'E')
	{
		game->found.exit++;
		return ;
	}
	if (game->data.map[y][x] == '1' || game->data.map[y][x] == 'M'
		|| game->data.map[y][x] == 'S' || game->data.map[y][x] == '.')
		return ;
	else
		game->data.map[y][x] = visit(game->data.map[y][x]);
	recursive_search(game, x, y + 1);
	recursive_search(game, x, y - 1);
	recursive_search(game, x + 1, y);
	recursive_search(game, x - 1, y);
	return ;
}

static void	find_start(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (game->data.map[j])
	{
		i = 0;
		while (game->data.map[j][i])
		{
			if (game->data.map[j][i] == 'P')
			{
				game->pers.y = j;
				game->pers.x = i;
				return ;
			}
			i++;
		}
		j++;
	}
	return ;
}

int	check_reach(t_game *game)
{
	int	y;
	int	x;

	game->found.coins = 0;
	game->found.exit = 0;
	find_start(game);
	y = game->pers.y;
	x = game->pers.x;
	recursive_search(game, x, y);
	if (game->found.coins != game->data.amount_coin)
		return (ft_putstr_fd("Error\nCoin not reacheble\n", 2), 1);
	if (game->found.exit < 1)
		return (ft_putstr_fd("Error\nExit not reacheble\n", 2), 1);
	return (0);
}
