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
	int error;
	if (ac ==  2)
	{
		//if(map_add(av, game) == -1)
		error = map_add(av, game);
		if (errors_path(error, game) == -1 )
			return (0);
		printf("pokemon");
		error = map_error_size(game);		
		error = map_tiles_correct(game);
		if (errors_path(error, game) == -1)
				return (0);
	}
	return (0);
}
