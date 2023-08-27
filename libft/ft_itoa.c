/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:57:08 by scespede          #+#    #+#             */
/*   Updated: 2023/08/28 01:53:38 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lengn(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		copyn;
	size_t	count;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	count = lengn(n);
	if (count == 0)
		return (ft_strdup("0"));
	if (n < 0)
		copyn = n * -1;
	else
		copyn = n;
	str = malloc((sizeof(char)) * (count + 1));
	if (!str)
		return (NULL);
	str[count--] = '\0';
	while (copyn > 0)
	{
		str[count--] = (copyn % 10) + '0';
		copyn /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
/*
int main ()
{
  char *str;
  str =NULL;
  str =ft_itoa(-214483648);
  printf("valor de los numero %s",str);
}
*/
