/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 01:43:09 by scespede          #+#    #+#             */
/*   Updated: 2023/08/28 01:43:00 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	count_char(t_game *game, char pj2)
{
	int	row;
	int	col;
	int	pj;

	row = -1;
	col = 0;
	pj = 0;
	while (game->map[++row])
	{
		while (game->map[row][col] && pj < 2)
		{
			if (game->map[row][col] == pj2)
				pj++;
			col++;
		}
		col = 0;
	}
	if (pj == 0 || pj > 1)
		return (-8);
	return (0);
}

int	map_char_events(t_game *game)
{
	if (count_char(game, 'P') == -8)
		return (-4);
	else if (count_char(game, 'E') == -8)
		return (-4);
	return (0);
}

int	ft_map_path(char *av, t_game *game)
{
	int	fd;

	fd = open(av, O_RDONLY);
	if (errors_path(path_extension(av), game) == -1)
		return (0);
	if (errors_path(map_add(fd, game), game) == -1)
		return (0);
	if (game->map[0] == NULL)
	{
		errors_path(-9, game);
		return (0);
	}
	if (errors_path(map_error_size(game), game) == -1)
		return (0);
	if (errors_path(map_tiles_correct(game), game) == -1)
		return (0);
	if (errors_path(map_farlands(game), game) == -1)
		return (0);
	if (errors_path(map_char_events(game), game) == -1)
		return (0);
	return (1);
}
