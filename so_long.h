/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 04:44:09 by scespede          #+#    #+#             */
/*   Updated: 2023/08/10 15:36:27 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "mlx/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_game
{
	char 	**map;
	int		lenght_size;
	int		with_size;
}	t_game;



int map_add(int fd, t_game *game);
int	path_extension(char *av);
int map_error_size(t_game *game);
int map_tiles_correct(t_game *game);
t_game *ft_lsnew();
int errors_path(int error, t_game *game);
void	free_map(t_game *game, int error);
void print_map(char **map);

#endif
