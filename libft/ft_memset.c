/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:07:32 by scespede          #+#    #+#             */
/*   Updated: 2023/05/26 11:56:27 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;
	size_t	count;

	count = 0;
	str = b;
	while (count != len)
	{
		str[count] = (unsigned char) c;
		count++;
	}
	return (str);
}
/*
int main ()
{
	char a[] = "aaaaaaaaaa";
	size_t b = 4;
	ft_memset(&a, 'x' , b);
}
*/
