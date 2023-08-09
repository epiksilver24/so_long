/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:52:14 by scespede          #+#    #+#             */
/*   Updated: 2023/05/24 12:52:21 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> 

int	ft_atoi(char *str)
{
	int	count;
	int	num;
	int	resta;

	resta = 0 ;
	num = 0;
	count = 0;
	while ((str[count] >= 9 && str[count] <= 13) || str[count] == ' ')
		count++;
	if (str[count] == '-')
	{
		count++;
		resta++;
	}
	else if (str[count] == '+')
		count++;
	while (str[count] && str[count] >= '0' && str[count] <= '9')
	{
		num *= 10;
		num = num + (str[count] - '0');
		count++;
	}
	if (resta % 2 == 1)
		num *= -1;
	return (num);
}
/*
int main ()
{
	char a[] = "	 -012";
	int c;
	c = ft_atoi(a);
	printf("%d ; numero es",c);
}
*/
