/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controlls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 04:28:03 by scespede          #+#    #+#             */
/*   Updated: 2023/08/27 22:27:54 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	control_w(t_game *game)
{
	int	row;
	int	col;

	row = game->pjy;
	col = game->pjx;
	if (game->maps[row - 1][col] != '1')
	{
		row--;
		if (game->maps[row][col] == 'C')
			game->coin--;
		game->maps[row][col] = 'P';
		game->maps[row + 1][col] = '0';
		draw_window(game);
		game->pjy = row;
		return (1);
	}
	return (0);
}

int	control_s(t_game *game)
{
	int	row;
	int	col;

	row = game->pjy;
	col = game->pjx;
	if (game->maps[row + 1][col] != '1')
	{
		row++;
		if (game->maps[row][col] == 'C')
			game->coin--;
		game->maps[row][col] = 'P';
		game->maps[row - 1][col] = '0';
		draw_window(game);
		game->pjy = row;
		return (1);
	}
	return (0);
}

int	control_d(t_game *game)
{
	int	row;
	int	col;

	row = game->pjy;
	col = game->pjx;
	if (game->maps[row][col + 1] != '1')
	{
		col++;
		if (game->maps[row][col] == 'C')
			game->coin--;
		game->maps[row][col] = 'P';
		game->maps[row][col - 1] = '0';
		draw_window(game);
		game->pjx = col;
		return (1);
	}
	return (0);
}

int	control_a(t_game *game)
{
	int	row;
	int	col;

	row = game->pjy;
	col = game->pjx;
	if (game->maps[row][col - 1] != '1')
	{
		col--;
		if (game->maps[row][col] == 'C')
			game->coin--;
		game->maps[row][col] = 'P';
		game->maps[row][col + 1] = '0';
		draw_window(game);
		game->pjx = col;
		return (1);
	}
	return (0);
}
