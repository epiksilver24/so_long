/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:35:09 by scespede          #+#    #+#             */
/*   Updated: 2023/05/26 11:56:49 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		count;
	char		*d;
	char		*s;

	d = (char *) dst;
	s = (char *) src;
	count = 0;
	if (!dst && !src)
		return (dst);
	while (count < n)
	{
		d[count] = s[count];
		src++;
		count++;
	}
	return ((void *)d);
}
