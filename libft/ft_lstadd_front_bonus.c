/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:59:04 by scespede          #+#    #+#             */
/*   Updated: 2023/05/26 11:59:05 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst)
	{
		new->next = *lst;
		*lst = new;
	}
	else
		*lst = new;
}
/*
int main ()
{
	char n[]= "pokemon";
	char n2[]= "pokemon2";
	char n3[]= "pokemon3";
	t_list *ptr = ft_lstnew(n);
	t_list *ptr2 = ft_lstnew(n2);
	t_list *ptr3 = ft_lstnew(n3);
	printf("\n1. valor del ptr %p\n",ptr);	
	printf("\n2. valor del ptr2 %p\n",ptr2);	
ptr->next = ptr2;	
	ft_lstadd_front(&ptr3, ptr);	
	printf("\n\n ptr3 -> ptr2 %p\n",ptr3->next);	
	printf("\n\n ptr3 -> ptr %p\n",ptr3->next);	
	while(ptr3)
	{
		printf("valor de ptr3 = %s\n",ptr3->content);
		ptr3 = ptr3->next;
	}
}
*/
