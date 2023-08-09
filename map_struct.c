/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:47:37 by scespede          #+#    #+#             */
/*   Updated: 2023/08/08 19:13:09 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"
#include <fcntl.h>

//typedef struct s_game
//{
//	char		**map;
//	int			lenght_size;
//	int 		with_size;
//}	t_game;


int	map_add(char **av, t_game *game)
{
	char	*line;
	int		fd;
	int		indi;
	char	*maping;
	char	**mapa;
	maping = ft_strdup("");
	line = ft_strdup("");
	fd = open(av[1],O_RDONLY);
	indi = 1;
	
	
	while(line)
	{
		free(line);
		line = get_next_line(fd);
		if (line != NULL)
			maping = ft_strjoin(maping,line);
		indi++;
	}

	mapa = ft_split(maping, '\n');
	game->map = mapa;
	return (1);
}
