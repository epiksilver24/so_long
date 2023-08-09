/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:47:37 by scespede          #+#    #+#             */
/*   Updated: 2023/08/09 10:35:39 by scespede         ###   ########.fr       */
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
		if (line != NULL)
			maping = ft_strjoin(maping,line);
		indi++;
	}
	game->map = ft_split(maping,'\n');
	return (1);
}
