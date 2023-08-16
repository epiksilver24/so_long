/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 04:45:10 by scespede          #+#    #+#             */
/*   Updated: 2023/08/10 20:12:15 by scespede         ###   ########.fr       */
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
		errors_path(-303,game);
//		free(game);
	}
	char *checkmalloc;
	printf("\nmalloc 1 bit\n");
	checkmalloc = malloc(1);
	checkmalloc[0] = '\0';
	return (0);
}
