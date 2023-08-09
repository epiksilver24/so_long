/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:01:12 by scespede          #+#    #+#             */
/*   Updated: 2023/05/26 12:01:13 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*a;
	t_list	*head;
	void	*temp;

	head = NULL;
	while (lst)
	{
		temp = (*f)(lst->content);
		a = ft_lstnew(temp);
		if (!a)
		{
			(*del)(temp);
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, a);
		lst = lst->next;
	}
	return (head);
}
/*
int  *savenum(int *s)
{
	int *ptr;
	ptr = (int *)malloc((sizeof(int)));
	ptr = s;
	return (ptr);
}

static void *plustwo(void *n)
{
	n = n + 2;
	return n;
}


int main ()
{
	int  *p ;
	p = (int *) 3;
	int  *n1 =savenum(p) ;
	int  *n2 =savenum(p) ;
	int  *n3 =savenum(p) ;
	int  *n4 =savenum(p) ;
	t_list *ptr = ft_lstnew(n1);
	t_list *ptr2 = ft_lstnew(n1);
	t_list *ptr3 = ft_lstnew(n2);
	t_list *ptr4 = ft_lstnew(n3);
	t_list *ptr5 = ft_lstnew(n4);
	ptr->next = ptr2;
	ptr2->next = ptr3;
	ptr3->next = ptr4;
	ptr4->next = ptr5;
	t_list *newc;

	newc = ft_lstmap(ptr,plustwo,free);

	while(newc)
	{
		int numero;

		numero = (int) newc->content;
		printf("valor de numero %d\n",numero);
		newc = newc->next;
	}





}*/
