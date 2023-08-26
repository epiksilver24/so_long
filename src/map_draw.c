/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 03:20:47 by scespede          #+#    #+#             */
/*   Updated: 2023/08/27 01:23:52 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


void add_path_img(t_game *game)
{
	int i;
	int j;

	game->wall = mlx_xpm_file_to_image(game->mlx,"sprite/wall.xpm", &i, &j);
	game->coin2 = mlx_xpm_file_to_image(game->mlx,"sprite/item.xpm", &i, &j);
	
	game->pj = mlx_xpm_file_to_image(game->mlx,"sprite/player.xpm", &i, &j);
	game->floor= mlx_xpm_file_to_image(game->mlx,"sprite/floor.xpm", &i, &j);
	game->dorrexit = mlx_xpm_file_to_image(game->mlx,"sprite/exit.xpm", &i, &j);


}


int draw_window(t_game *game)
{
	int row;
	int col;
	row = 0;
	col = 0;

	while (game->maps[row])
	{
		while (game->maps[row][col])
		{
		if (game->maps[row][col] == '1')
				mlx_put_image_to_window(game->mlx,
					game->mlx_w, game->wall, col * 40, row * 40);
		if (game->maps[row][col] == 'C')
				mlx_put_image_to_window(game->mlx,
					game->mlx_w, game->coin2, col * 40, row * 40);
		if (game->maps[row][col] == 'P')
				mlx_put_image_to_window(game->mlx,
					game->mlx_w, game->pj, col * 40, row * 40);
		if (game->maps[row][col] == 'E')
				mlx_put_image_to_window(game->mlx,
					game->mlx_w, game->dorrexit, col * 40, row * 40);
		if (game->maps[row][col] == '0')
				mlx_put_image_to_window(game->mlx,
					game->mlx_w, game->floor, col * 40, row * 40);
			col++;
		}
		col = 0;
		row++;
	}

	if(!(game->pjy == game->exitr && game->pjx == game->exitc))
		mlx_put_image_to_window(game->mlx,
				game->mlx_w, game->dorrexit, game->exitc * 40, game->exitr * 40);


	
printf("\n\n posicion pj row = %i col = %i\n exit row = %i co    l = %i valor moneda %i \n\n",game->pjy, game->pjx, game->exitr, game->exitc , game->coin);


	if (game->coin == 0 && game->pjy == game->exitr && game->pjx == game->exitc)
	{
		printf("you win");
		printf("you win");
		printf("you win");
		printf("you win");
		mlx_destroy_window(game->mlx, game->mlx_w);
		return (-1);
	}
	return (0);
}
