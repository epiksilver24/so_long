/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 04:45:10 by scespede          #+#    #+#             */
/*   Updated: 2023/08/27 04:18:36 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <unistd.h>
#include <fcntl.h>

t_game *ft_lsnew()
{
	t_game *game;
	game = malloc(sizeof(*game));
	if(!game)
		return (NULL);
	game->map = NULL;
	game->lenght_size = -1;
	game->with_size = -1;
	game->move	= 0;
	game->coin = 0;
	return (game);
}

int main(int ac, char **av )
{
	t_game *game;
	game = ft_lsnew();
	if (ac !=  2)
		return (0);
	if(	ft_map_path(av[1], game) == 0)
			return (0);
	//game->mlx = mlx_init();
	//print_map(game->map);
	map_backtraking(game);
	start_mlx(game);
	add_path_img(game);	
	//game->mlx_w = mlx_new_window (game->mlx, game->lenght_size  * 40, game->with_size * 40 , "Hello World");
	
	draw_window(game);
	
	mlx_hook(game->mlx_w, 2, 1L << 0 , (void *) moviment, game);
 	mlx_hook(game->mlx_w, 17, 1L << 0 , (void *)exit, NULL);
		mlx_loop(game->mlx);
//	errors_path(-303,game);
	char *checkmalloc;
	printf("\nmalloc 1 bit\n");
	checkmalloc = malloc(1);
	checkmalloc[0] = '\0';
	return (0);
}
int moviment(int keycode, t_game *game)
{
	int works;
//	printf("\ncoin cuantiti %i", game->coin);
//	printf("press key 1");
	if(keycode == 53 )
		exit(0);
	if (keycode == 13 || keycode == 126)
		works  = control_w(game);
	if (keycode == 1 || keycode == 125)
		works  = control_s(game);
	if (keycode == 2 || keycode == 124)
		works  = control_d(game);
	if (keycode == 0 ||  keycode == 123)
		works  = control_a(game);
//	printf("\n posicion pj row = %i col = %i\n exit row = %i col = %i \n\n",game->pjy,game->pjx, game->exitr, game->exitc);
//	if (game->coin == 0 && game->pjy == game->exitr && game->pjx == game->exitc)
//		printf("you win");
	works =  draw_window(game);
	return  (works);
}
