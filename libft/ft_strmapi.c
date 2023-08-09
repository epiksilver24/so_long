/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:02:12 by scespede          #+#    #+#             */
/*   Updated: 2023/05/26 12:02:13 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	count;

	str = ft_strdup(s);
	if (!str)
		return (NULL);
	count = 0;
	while (str[count])
	{
		str[count] = (*f)(count, s[count]);
		count++;
	}
	return (str);
}
