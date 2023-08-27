/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 01:43:09 by scespede          #+#    #+#             */
/*   Updated: 2023/08/27 02:31:39 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_map_path(char *av, t_game *game)
{
	int fd;

	fd = open(av,O_RDONLY);
	if(errors_path(path_extension(av),game) == -1)
		return (0);
	if (errors_path(map_add(fd, game), game) == -1)
		return (0);
	if (errors_path(map_error_size(game), game) == -1)
		return (0);
	if (errors_path(map_tiles_correct(game), game) == -1)
		return (0);
	if (errors_path(map_farlands(game), game) == -1)
		return (0);
	if (errors_path(map_char_events(game), game) == -1)
			return (0);
	return (1);
}
