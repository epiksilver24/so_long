/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:49:54 by scespede          #+#    #+#             */
/*   Updated: 2023/08/28 01:54:03 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	leng;

	if (!(ft_strlen(s1)) && !(ft_strlen(s2)))
		return (ft_strdup(""));
	str = NULL;
	leng = (ft_strlen(s1) + ft_strlen(s2) + 1);
	str = (char *)malloc((sizeof(char)) * leng);
	if (!str)
		return (NULL);
	ft_strlcpy(str, (char *)s1, leng);
	ft_strlcat(str, (char *)s2, leng);
	free((char *)s1);
	return (str);
}

//int main ()
//{
//	char a[] = "";
//	char b[] = "";
//	
//	printf("valor de la salida que sera : %s",ft_strjoin(a,b));
//}
