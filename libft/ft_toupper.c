/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:48:25 by scespede          #+#    #+#             */
/*   Updated: 2023/05/26 11:47:27 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int chr)
{
	if (chr >= 'a' && chr <= 'z')
	{
		chr -= 32;
	}
	return (chr);
}
//
//int main ()
//{
//char c ;
//int i;
//	i = 'a';
//    while (i <= 'z')
//    {
//        c = ft_toupper(i);
//        write(1, &c, 1);
//        i++;
//    }
//	printf("\npatron original\n");
//
//char u ;
//int t;
//t = 'a';
//while (t <= 'z')
//{
//	u = toupper(t);
//	write(1,&u,1);
//	t++;
//}
//
//}
