/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 03:26:00 by scespede          #+#    #+#             */
/*   Updated: 2023/08/27 03:40:10 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void start_mlx(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_w = mlx_new_window(game->mlx, game->lenght_size * 40, 
			game->with_size * 40, "so_long");
}
