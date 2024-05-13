/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:28:48 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/01/12 11:35:32 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_newlines(char *str)
{
	int	i;
	int	two_nl;

	i = 0;
	two_nl = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
		{
			two_nl = 1;
			while (1)
			{
				if (str[i] != '\n' && str[i] != '\0')
					return (ft_putstr_fd("Error\nHole in map\n", 2), 1);
				else if (str[i] == '\0')
					return (0);
				i++;
			}
		}
		i++;
	}
	if (two_nl == 1)
		return (ft_putstr_fd("Error\nHole in map\n", 2), 1);
	return (0);
}

static char	*get_size(t_game *game, int fd)
{
	char	*str;
	char	*temp;
	char	*all;

	all = get_next_line(fd);
	if (all == 0)
		return (perror("Error\n"), NULL);
	game->data.width = ft_strlen(all) - 1;
	while (1)
	{
		game->data.height++;
		str = get_next_line(fd);
		if (str == 0)
			break ;
		temp = ft_strjoin(all, str);
		free(str);
		free(all);
		if (!temp)
			return (perror("Error\n"), NULL);
		all = temp;
	}
	if (check_newlines(all))
		return (free(all), NULL);
	return (all);
}

static int	check_shape(char **map, t_game *game)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) != (size_t)game->data.width)
			return (ft_putstr_fd("Error\nNo rectangular shape\n", 2), 1);
		i++;
	}
	game->data.height = i - 1;
	return (0);
}

void	prepare_map(t_game *game, char *ber)
{
	int		fd;
	char	*str;

	fd = open(ber, O_RDONLY);
	if (fd < 1)
	{
		perror("Error\n");
		exit (1);
	}
	str = get_size(game, fd);
	close(fd);
	if (!str)
		exit (1);
	game->data.map = ft_split(str, '\n');
	free(str);
	if (!game->data.map)
	{
		perror("Error\n");
		exit (1);
	}
	if (check_shape(game->data.map, game) || check_icons(game)
		|| check_wall(game) || check_reach(game))
		exit (free_map(game));
	ft_printf("Valid map\n");
	return ;
}
