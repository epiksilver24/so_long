/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:06:32 by scespede          #+#    #+#             */
/*   Updated: 2023/05/26 11:52:41 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(const char *dest, const char *src, size_t destsize)
{
	size_t	i;
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	i = 0;
	if (destsize == 0)
		return (ft_strlen(src));
	destsize -= 1 ;
	while (s[i] != '\0')
	{
		if (i >= destsize)
		{
			d[i] = '\0';
			return (ft_strlen(src));
		}
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (ft_strlen(src));
}
//
//int main()
//{
//
//	char src[] = "lore";
//	char des[10] = ""; 
//	int n = strlcpy(des,src,6);
//
//	printf("\nvalor de numero del copy %d", n);
//	printf("\nvalor del destino |%s|\n", des);
//	char src2[] = "lore";
//	char des2[10] = ""; 
//	int b = ft_strlcpy(des2,src2,6);
//	
//
//	printf("\nvalor de numero del copy %d", b);
//	printf("\nvalor del destino |%s|\n", des2);
//	
//}
