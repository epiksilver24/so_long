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
	int error;
	if (ac ==  2)
	{
		//if(map_add(av, game) == -1)
		fd = open(av[1],O_RDONLY);
		printf("extension\n");
		if(errors_path(path_extension(av[1]),game) == -1)
			return (0);
		printf("add map\n");
		error = map_add(fd, game);
		if (errors_path(error, game) == -1 )
			return (0);

		print_map(game->map);

		//int a;
		//a = 0;
		//while (game->map[a])
		//	free(game->map[a]);
		errors_path(-3, game);
		free(game);
		
		//	printf("error = %d\n",error);
	//	error = map_error_size(game);		
//		error = map_tiles_correct(game);
	//	printf("error = %d",error);

	//	if (errors_path(error, &game) == -1)
	//	{
	//		printf("error");
	//			free(game);
	//			return (0);
	//	}
	}
	return (0);
}
