/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:17:42 by scespede          #+#    #+#             */
/*   Updated: 2023/05/26 11:50:00 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*a;
	char	*b;
	size_t	count;

	count = 0;
	a = (char *)s1;
	b = (char *)s2;
	while (n-- > 0)
	{
		if (a[count] != b[count])
			return ((unsigned char)a[count] - (unsigned char)b[count]);
		count++;
	}
	return (0);
}
//
//int main ()//
//{  
//	char s1[10] = "pokemon";
//
//	char s2[10]	= "pokemon";
//
//
//	 printf("mi funcionsadas\nnum= %d ",ft_memcmp(s1,s2,5) );
//
//}
