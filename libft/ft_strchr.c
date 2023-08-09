/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:54:23 by scespede          #+#    #+#             */
/*   Updated: 2023/06/09 16:41:10 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int charac)
{
	while (*str)
	{
		if (*str == (char) charac)
			return ((char *)str);
		str++;
	}
	if (*str == (char) charac)
		return ((char *) str);
	return (0);
}
//
//int main ()
//{
//	char a[] = "pokemon";
//
//	
//	printf("valor de a %s",ft_strchr(a,107));
//}
