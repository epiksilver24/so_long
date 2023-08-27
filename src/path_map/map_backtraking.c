/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_backtraking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 06:18:47 by scespede          #+#    #+#             */
/*   Updated: 2023/08/28 01:03:50 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	serch_player(char **map, t_game *game)
{
	int	row;
	int	col;

	game->coin = 0; 
	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] == 'P')
			{
				game->pr = row;
				game->pc = col;
			}
			if (map[row][col] == 'C')
				game->coin++;
			col++;
		}
		row++;
	}
}

void	serch_exitrc(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (game->maps[row])
	{
		col = 0;
		while (game->maps[row][col])
		{
			if (game->maps[row][col] == 'E')
			{
				game->exitr = row;
				game->exitc = col;
			}
			if (game->maps[row][col] == 'C')
				game->coin++;
			col++;
		}
		row++;
	}
}

int	bt_confirm(t_game *game, int i, int j)
{
	while (game->map[i][j] != '1' && game->map[i][j] != 'X') 
	{
		if (game->map[i][j] == 'P')
		{
			game->pjy = i;
			game->pjx = j;
		}
		if (game->map[i][j] == 'C')
			game->coin--;
		if (game->map[i][j] == 'E')
			game->exit++;
		game->map[i][j] = 'X';
		bt_confirm(game, i + 1, j);
		bt_confirm(game, i - 1, j);
		bt_confirm(game, i, j + 1);
		bt_confirm(game, i, j - 1);
	}
	return (0);
}

void	map_backtraking(t_game *game)
{
	serch_player(game->map, game);
	game->exit = 0;
	bt_confirm(game, game->pr, game->pc);
	if (game->coin != 0)
	{
		ft_putstr_fd("error map no coint correct", 1);
		destroy_game(game);
	}
	if (game->exit != 1)
	{
		ft_putstr_fd("error map no exit correct", 1);
		destroy_game(game);
	}
	serch_exitrc(game);
}
