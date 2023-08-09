/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:53:15 by scespede          #+#    #+#             */
/*   Updated: 2023/05/10 01:32:29 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*srt;

	srt = (char *) s;
	while (n-- > 0)
	{
		if (*srt == (char) c)
			return (srt);
		srt++;
	}
	return (NULL);
}
