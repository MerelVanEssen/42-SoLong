/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:15:12 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/01/12 11:43:45 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_wrong_icon(char c, t_game *game, int *person, int *exit)
{
	int	ex;
	int	per;

	ex = 0;
	per = 0;
	if (c == 'E')
		ex++;
	else if (c == 'P')
		per++;
	else if (c == 'C')
		game->data.amount_coin++;
	else if (c == 'B')
		game->data.amount_skull++;
	if (c == '0' || c == '1' || c == 'E'
		|| c == 'P' || c == 'C' || c == 'B')
	{
		*exit += ex;
		*person += per;
		return (0);
	}
	return (1);
}

int	check_icons(t_game *game)
{
	int	exit;
	int	person;
	int	i;
	int	j;

	exit = 0;
	person = 0;
	j = 0;
	while (game->data.map[j])
	{
		i = 0;
		while (game->data.map[j][i])
		{
			if (is_wrong_icon(game->data.map[j][i], game, &person, &exit))
				return (ft_putstr_fd("Error\nWrong icon\n", 2), 1);
			i++;
		}
		j++;
	}
	if (game->data.amount_coin < 1 || exit != 1 || person != 1)
		return (ft_putstr_fd("Error\nFail icons\n", 2), 1);
	return (0);
}

int	check_wall(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (game->data.map[j])
	{
		i = 0;
		while (game->data.map[j][i])
		{
			if (i == 0 || j == 0 || i == game->data.width
				|| j == game->data.height)
			{
				if (game->data.map[j][i] != '1')
					return (ft_putstr_fd("Error\nWrong wall\n", 2), 1);
			}
			i++;
		}
		j++;
	}
	return (0);
}
