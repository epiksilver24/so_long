/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 04:44:09 by scespede          #+#    #+#             */
/*   Updated: 2023/08/09 13:48:25 by scespede         ###   ########.fr       */
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



int map_add(char **av, t_game *game);
int map_error_size(t_game *game);
int map_tiles_correct(t_game *game);
t_game *ft_lsnew();

#endif
