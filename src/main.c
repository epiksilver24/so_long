/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 04:45:10 by scespede          #+#    #+#             */
/*   Updated: 2023/08/26 03:29:55 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <unistd.h>
#include <fcntl.h>

int closes(int keycode);
//typedef struct s_game
//{
//	int			**map;
//	int			lenght_size;
//	int			with_size;
//}	t_game;

t_game *ft_lsnew()
{
	t_game *game;
	game = malloc(sizeof(*game));
	if(!game)
		return (NULL);
	game->map = NULL;
	game->lenght_size = -1;
	game->with_size = -1;
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
	// backtraking
	print_map(game->map);
	map_backtraking(game);
//	printf("valor de p row %i, col %i",game->pr,game->pc);	
	print_map(game->map);
	print_map(game->maps);


	int i;
	int j;
 	void *img_ptr ;
	i = 32;
	j = 32;
	add_path_img(game);	
	game->mlx_w = mlx_new_window (game->mlx, game->lenght_size  * 40, game->with_size * 40 , "Hello World");
	printf("valor main game %p",game);
	draw_window(game);
	img_ptr = 	mlx_xpm_file_to_image(game->mlx, "sprite/wall.xpm", &i, &j);
//	printf("valor de img %p",img_ptr);
//	mlx_put_image_to_window(game->mlx, game->mlx_w, img_ptr, (1 *50), (1 * 50));
	mlx_hook(game->mlx_w, 17, 1L << 0 , (void *)exit, NULL);
	mlx_hook(game->mlx_w, 2, 1L << 0 , (void *) closes, NULL);
	mlx_loop(game->mlx);
	//printf("pokemon negro");

	//map_backtraking(game);
//	errors_path(-303,game);
	char *checkmalloc;
	printf("\nmalloc 1 bit\n");
	checkmalloc = malloc(1);
	checkmalloc[0] = '\0';



	return (0);
}

int closes(int keycode)
{
	printf("\n%i",keycode);
	if(keycode == 53)
		exit(0);
	return  (0);
}
