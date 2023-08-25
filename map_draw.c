/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 03:20:47 by scespede          #+#    #+#             */
/*   Updated: 2023/08/25 04:15:04 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void draw_window(t_game *game)
{
	int i;
	int j;

	i = 0;
	j = 0;

			mlx_put_image_to_window(game->mlx,game->mlx_w, game->wall, i * 32 , j *32);

}
