/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:47:37 by scespede          #+#    #+#             */
/*   Updated: 2023/08/09 14:09:39 by scespede         ###   ########.fr       */
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
	int		len;

	len = ft_strlen(av[1]);
	printf("%d",len);
	if(!((av[1][len - 1] == 'r') && (av[1][len -2] == 'e') 
				&& (av[1][len - 3] == 'b') && (av[1][len - 4] = '.')))
		return (-1);
	maping  = ft_strdup("");
	line = ft_strdup("");
	fd = open(av[1],O_RDONLY);
	indi = 1;
	while(line)
	{
		free(line);
		line = get_next_line(fd);
		if (line && line[0] == '\n')
			return (-1);
		if (line != NULL)
			maping = ft_strjoin(maping,line);
		indi++;
	}
	game->map = ft_split(maping,'\n');
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
		{
			printf("\n error tamano\n");
			return (-1);
		}
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
			{
				printf("\nerror de mapa caracteres\n");
				return (-1);
			}
		}
		indi++;
	}
	return (1);
}


