/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:47:37 by scespede          #+#    #+#             */
/*   Updated: 2023/08/10 20:12:03 by scespede         ###   ########.fr       */
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


int	map_add(int fd, t_game *game)
{
	char *line;
	char *all_line;
	line = ft_strdup("");
	all_line = ft_strdup("");
	if(line == NULL || all_line == NULL)
		return (-2);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if(line)
		{
			if(line && line[0] == '\n')
			{
				free(line);
				return (-2);
			}
			all_line = ft_strjoin(all_line, line);
		}
	}
	game->map = ft_split(all_line, '\n');
	free(all_line);
	return (1);
}

int	map_error_size(t_game *game)
{
	size_t len;
	size_t compare;
	int i;
	
	i = 0;
	len = ft_strlen(game->map[0]);
	while (game->map[i])
	{
		compare = ft_strlen(game->map[i]);
		if (compare != len)
			return (-3);
		i++;
	}
	game->lenght_size =  (int)len;
	game->with_size =(int) i;
	return (1);
}
// 0 espacio vacio; 1 muro; C moneda; E salida; P posicion inicial
int  map_tiles_correct(t_game *game)
{
	int	indi;
	int	a;
	indi = 0;
	char *f;

	f = "01CEP";
	while (game->map[indi])
	{
		a = 0;
		while (game->map[indi][a++])
		{
			if (ft_strchr(f, game->map[indi][a]) == NULL)
				return (-4);
		}
		indi++;
	}
	return (1);
}


