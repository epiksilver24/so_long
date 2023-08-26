/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 04:45:10 by scespede          #+#    #+#             */
/*   Updated: 2023/08/27 00:19:27 by scespede         ###   ########.fr       */
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
	game->coin = 0;
	return (game);
}

int main(int ac, char **av )
{
	t_game *game;
	game = ft_lsnew();
	int fd;
	if (ac ==  2)
	{
		game->mlx = mlx_init();
		fd = open(av[1],O_RDONLY);
		if(errors_path(path_extension(av[1]),game) == -1)
			return (0);
		if (errors_path(map_add(fd, game), game) == -1)
			return (0);
		print_map(game->map);
		if (errors_path(map_error_size(game), game) == -1)
			return (0);
		if (errors_path(map_tiles_correct(game), game) == -1)
			return (0);
		if (errors_path(map_farlands(game), game) == -1)
			return (0);
		if (errors_path(map_char_events(game), game) == -1)
			return (0);
	}
	else 
		write(1,"error",5);
	print_map(game->map);
	map_backtraking(game);

	printf("\ncoin cuantitigadfasdfas %i\n", game->coin);

	add_path_img(game);	
	game->mlx_w = mlx_new_window (game->mlx, game->lenght_size  * 40, game->with_size * 40 , "Hello World");
//	draw_window(game);
	fd = 0;
	printf("\n 1 valor de fd %i\n",fd);
	fd = mlx_hook(game->mlx_w, 2, 1L << 0 , (void *) moviment, game);
fd = 	mlx_hook(game->mlx_w, 17, 1L << 0 , (void *)exit, NULL);
	printf("\n 2 valor de fd %i\n",fd);
		if (fd == -1)
		{
			printf("\n 3 valor de fd %i\n",fd);
			return (0);
		}
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
