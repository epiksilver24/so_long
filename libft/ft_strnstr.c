/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:41:59 by scespede          #+#    #+#             */
/*   Updated: 2023/07/19 11:13:01 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*str;
	char	*ned;
	size_t	c;
	size_t	position;

	position = 0;
	c = 0;
	str = (char *) haystack;
	ned = (char *) needle;
	if (ned[c] == '\0')
		return ((char *) haystack);
	while (str[c] && c < len)
	{
		while (str[c + position] == ned[position] && (c + position) < len)
		{
			if (ned[position + 1] == '\0')
				return (&str[c]);
			position++;
		}
		position = 0;
		c++;
	}
	return (NULL);
}
/*
int main ()
{
  char  a[] = "lorem impsum dolor sit amet";
  char	b[] = "hola";
  printf("mi funcionsadas num= \n%s", ft_strnstr(a,b,15) );


}
*/
