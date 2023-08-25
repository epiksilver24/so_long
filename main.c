/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 04:45:10 by scespede          #+#    #+#             */
/*   Updated: 2023/08/25 04:15:02 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <fcntl.h>

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
	game->mlx_w = mlx_new_window (game->mlx, (game->lenght_size * 32) , (game->with_size * 32) , "Hello World");
	src_tiles(game);
	mlx_put_image_to_window(game->mlx, game->mlx_w, "sprite/wall.xpm", 32 , 32 );
	mlx_loop(game->mlx_w);
	//map_backtraking(game);
	errors_path(-303,game);
	char *checkmalloc;
	printf("\nmalloc 1 bit\n");
	checkmalloc = malloc(1);
	checkmalloc[0] = '\0';
	return (0);
}
