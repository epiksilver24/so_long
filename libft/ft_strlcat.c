/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 13:35:29 by scespede          #+#    #+#             */
/*   Updated: 2023/05/26 11:53:03 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	destleng;
	size_t	srcleng;
	size_t	counter;

	counter = 0;
	destleng = ft_strlen(dst);
	srcleng = ft_strlen(src);
	if (!size)
		return (srcleng);
	while (src[counter] && destleng + counter < size - 1)
	{
		dst[destleng + counter] = src[counter];
		counter++;
	}
	dst[destleng + counter] = '\0';
	if (destleng > size)
		return (srcleng + size);
	return (destleng + srcleng);
}
//
//int main ()
//{
//  char f1[] = "pokemon";
//  char f2[] = "diamante";
//  size_t a = 3;
//
//  printf("valor de numero %d \t valor de la frase 
//  %s",ft_strlcat(f1, f2, a),f1);  
//}
//
