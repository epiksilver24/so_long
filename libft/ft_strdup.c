/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 01:15:52 by scespede          #+#    #+#             */
/*   Updated: 2023/06/12 12:28:23 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	leng;
	char	*ptr;

	ptr = NULL;
	leng = ft_strlen(s);
	ptr = (char *)malloc(leng + 1);
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s, leng + 1);
	return (ptr);
}
//
//int main ()
//{
//	char s[] = "pokemon";
//	char *p;
//	p = ft_strdup(s);	
//	printf("frase de s %s",s);
//}
//
