/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:56:29 by scespede          #+#    #+#             */
/*   Updated: 2023/05/24 12:56:34 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int a)
{
	if ((a >= 32 && a <= 126))
		return (1);
	return (0);
}
/*
int main ()
{
	char a ;

	a = 62;

printf("es pimible : %d" ,ft_isprint('~') );
	
}
*/
