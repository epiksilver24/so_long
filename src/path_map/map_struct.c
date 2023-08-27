/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:47:37 by scespede          #+#    #+#             */
/*   Updated: 2023/08/28 00:22:49 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	map_add(int fd, t_game *game)
{
	char	*line;
	char	*all_line;

	line = ft_strdup("");
	all_line = ft_strdup("");
	if (line == NULL || all_line == NULL)
		return (-2);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line)
		{
			if (line && line[0] == '\n')
			{
				free(line);
				free(all_line);
				return (-2);
			}
			all_line = ft_strjoin(all_line, line);
		}
	}
	game->map = ft_split(all_line, '\n');
	game->maps = ft_split(all_line, '\n');
	free(all_line);
	return (1);
}

int	map_error_size(t_game *game)
{
	size_t	len;
	size_t	compare;
	int		i;

	i = 0;
	printf("valor de map %p", game->map[0]);
	len = ft_strlen(game->map[0]);
	while (game->map[i])
	{
		compare = ft_strlen(game->map[i]);
		if (compare != len)
			return (-3);
		i++;
	}
	game->lenght_size = (int)len;
	game->with_size = (int) i;
	return (1);
}

int	map_tiles_correct(t_game *game)
{
	int	indi;
	int	a;
	char	*f;

	indi = 0;
	game->coin = 0; 
	f = "01CEP";
	while (game->map[indi])
	{
		a = 0;
		while (game->map[indi][a++])
		{
			if (game->map[indi][a] == 'C')
				game->coin++;
		}
		indi++;
	}
	return (1);
}

int	map_farlands(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	col = -1;
	while (game->map[row][++col])
		if (game->map[row][col] != '1')
			return (-7);
	col--;
	row = -1;
	while (game->map[++row])
		if (game->map[row][col] != '1')
			return (-7);
	row--;
	while (col >= 0)
	{
		if (game->map[row][col] != '1')
			return (-7);
		col--;
	}
	col = 0;
	while (row >= 0)
	{
		if (game->map[row][col] != '1')
			return (-7);
		row--;
	}
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
