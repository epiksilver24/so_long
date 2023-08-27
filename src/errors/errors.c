/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:21:58 by scespede          #+#    #+#             */
/*   Updated: 2023/08/27 07:16:30 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	sout_errors(t_game *game, int error);
static void	free_map(t_game *game);

int	errors_path(int error, t_game *game)
{
	if (error < 0)
	{
		if (error == -1)
			write(1, "error file", 10);
		else if (error == -2)
			write(1, "error create malloc", 19);
		else if (error == -3)
			sout_errors(game, error);
		else if (error == -4)
			sout_errors(game, error);
		else if (error == -5)
			write(1, "error n", 7);
		else if (error == -7)
			sout_errors(game, error);
		else if (error == -303)
			sout_errors(game, error);
		free(game->map);
		free(game->maps);
		free(game);
		return (-1);
	}
	return (1);
}

static void	sout_errors(t_game *game, int error)
{
	free_map(game);
	write(1, "error ", 6);
	if (error == -4)
		write(1, "mapa caracteres", 15);
	else if (error == -3)
		write(1, "mapa dimension", 14);
	else if (error == -7)
		write(1, "farlands error", 14);
	else if (error == -303)
		write(1, "limpiando mapa", 14);
}

static void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	i = 0;
	while (game->maps[i])
	{
		free(game->maps[i]);
		i++;
	}
}
