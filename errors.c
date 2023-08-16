/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:21:58 by scespede          #+#    #+#             */
/*   Updated: 2023/08/10 20:07:50 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int errors_path(int error, t_game *game)
{
	if (error < 0)
	{
	if (error == -1)
		write(1,"error file",10);
	else if (error == -2)
		write(1,"error create malloc",19);
	else if (error == -3)
		free_map(game, error);
	else if (error == -4)
		free_map(game, error);
	else if (error == -5)
		write(1,"error n",7);
	else if (error == -7)
		free_map(game,error);
	else if (error == -303)
		free_map(game,error);
	free(game->map);
//	exit(EXIT_FAILURE);

	return (-1);
	}
	return (1);
}

void	free_map(t_game *game, int error)
{
	int b;

	b = -1;
	while (game->map[++b])
		free(game->map[b]);
//	free(game->map);
	write(1,"error ", 6);
	if (error == -4)
		write(1,"mapa caracteres",15);
	else if (error == -3)
		write(1,"mapa dimension",14);
	else if (error == -7)
		write(1,"farlands error",14);
	else if (error == -303)
		write(1,"limpiando mapa",14);
}

