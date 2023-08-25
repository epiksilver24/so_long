/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 02:14:58 by scespede          #+#    #+#             */
/*   Updated: 2023/08/25 04:15:06 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void src_tiles(t_game *game)
{
	int i;
	int j;
	game->wall = mlx_xpm_file_to_image(game->mlx, "sprite/wall.xpm", &i, &j);


}
