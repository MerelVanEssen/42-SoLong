/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skull.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:07:19 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/01/12 11:41:14 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_img_skull(t_game *game)
{
	game->im.skull = load_images(game, "./images/skull.xpm");
	if (game->im.skull.fault == 1)
		return (1);
	return (0);
}

static int	make_skulls(t_game *game)
{
	int	skulls;

	skulls = game->data.amount_skull;
	game->skull = (t_skull *)malloc(sizeof(t_skull) * skulls);
	if (!game->skull)
		return (perror("Error\n"), 1);
	return (0);
}

int	get_skulls(t_game *game)
{
	int	i;
	int	j;
	int	nr;

	if (make_skulls(game))
		return (1);
	j = 0;
	nr = 0;
	while (game->data.map[j])
	{
		i = 0;
		while (game->data.map[j][i])
		{
			if (game->data.map[j][i] == 'B')
			{
				game->skull[nr].y = j;
				game->skull[nr].x = i;
				nr++;
			}
			i++;
		}
		j++;
	}
	return (0);
}
