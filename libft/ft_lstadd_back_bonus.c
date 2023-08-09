/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:58:50 by scespede          #+#    #+#             */
/*   Updated: 2023/05/26 11:58:51 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	ptr = *lst;
	if (*lst)
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
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
	ptr->next = ptr2;
	ptr2->next = ptr3;

	t_list *ptr4 = ft_lstnew(n);

	ft_lstadd_back(&ptr, ptr4);
	while (ptr) {
		printf("contenc de ptr %s\n",(char*)ptr->content);
		ptr = ptr->next;
	}
}
*/
