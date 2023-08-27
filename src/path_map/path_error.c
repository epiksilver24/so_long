/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 06:42:27 by scespede          #+#    #+#             */
/*   Updated: 2023/08/27 06:47:18 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	path_extension(char *av)
{
	int	len;

	len = ft_strlen(av);
	if (!((av[len - 1] == 'r') && (av[len -2] == 'e')))
		if (((av[len - 3] == 'b') && (av[len - 4] == '.')))
			return (-1);
	return (1);
}
