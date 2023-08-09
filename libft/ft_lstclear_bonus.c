/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:59:18 by scespede          #+#    #+#             */
/*   Updated: 2023/05/26 11:59:19 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;

	ptr = *lst;
	if (ptr != NULL)
	{
		ft_lstclear(&ptr->next, del);
		(*del)(ptr->content);
		free(ptr);
	}
	*lst = NULL;
}
/*
int main ()

{
	char  *n = ft_strdup("pokemon");
	char  *n1 = ft_strdup("pokemon");
	char  *n2 = ft_strdup("pokemon");
	char  *n3 = ft_strdup("pokemon");
	char  *n4 = ft_strdup("pokemon");
	t_list *ptr = ft_lstnew(n);
	t_list *ptr2 = ft_lstnew(n1);
	t_list *ptr3 = ft_lstnew(n2);
	t_list *ptr4 = ft_lstnew(n3);
	t_list *ptr5 = ft_lstnew(n4);
	ptr->next = ptr2;
	ptr2->next = ptr3;
	ptr3->next = ptr4;
	ptr4->next = ptr5;
	
	ft_lstclear(&ptr,free);	
}
*/
