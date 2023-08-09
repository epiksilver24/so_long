/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:43:40 by scespede          #+#    #+#             */
/*   Updated: 2023/05/26 11:50:20 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		num;
	size_t	count;
	size_t	round;

	round = 0;
	num = 0;
	count = 0;
	if ((s1[count] == '\0' && s2[count] == '\0') || n == 0)
		return (0);
	while (s1[count] != '\0' && s2[count] != '\0' && round < n)
	{
		if (s1[count] != s2[count])
			return ((unsigned char) s1[count] - (unsigned char) s2[count]);
		num += (s1[count] - s2[count]);
		count++;
		round++;
	}
	if (!(round == n))
		num += ((unsigned char) s1[count] - (unsigned char) s2[count]);
	return (num);
}
//int main ()
//{
//  char  a[] = "abcdef";
//  char	b[] = "abc/376xx";
//  printf("mi funcionsadas\nnum= %d",ft_strncmp(a, b, 5) );
//
//  char  c[] = "abcdef";
//  char	d[] = "abc/375xx";
//  printf("\nmi funcionsadas\nnum= %d\tnum = %d",strncmp(c, d, 5) );
//
//}
