/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:13:28 by scespede          #+#    #+#             */
/*   Updated: 2023/08/10 19:32:18 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	numword(const char *s, char sep)
{
	size_t	count;
	size_t	worlds;
	int		sispace;
	char	*str;

	str = (char *) s;
	sispace = 0;
	worlds = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[count])
	{
		if (str[count] != sep)
			sispace = 1;
		if ((str[count + 1] == sep || str[count + 1] == '\0') && sispace == 1)
		{
			worlds++;
			sispace = 0;
		}
		count++;
	}
	return (worlds);
}
//static int	countworld(const char *s, char c)
//{
//	int count;
//
//	count = 0;
//	while (*s && *s != c) {
//		count++;
//		s++;
//	}
//	return (count);
//}

static void	*maximumfree(char **str, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	count;
	size_t	worlds;
	char	*news;

	worlds = numword(s, c);
	count = 0;
	ptr = malloc (sizeof(char *) * (numword(s, c) + 1));
	if (!ptr)
		return (NULL);
	while (count < worlds)
	{
		while (*s == c && *s)
			s++;
		news = (char *)s;
		while (*s != c && *s != '\0')
			s++;
		ptr[count] = ft_substr(news, 0, s - news);
		if (!ptr[count])
			return (maximumfree(ptr, count));
		count++;
	}
	ptr[count] = NULL;
	return (ptr);
}
/*
int main ()
{ 
	char b[] = " pokemo nverde rojo negro";
	char a[] = "1 2 3 4 5 6 7 8 9 0 ";
	char **ptr;
	ptr = ft_split(b,' ');
	int count;

	count = 0;
	while (ptr[count] ) {
	
	printf("indice %d |%s|\n",count,ptr[count]);
	count++;
	}
}
 *{
	char **ptr;
	size_t	count;
	size_t	worlds;

	worlds = numword(s, c);
	count = 0;
	ptr = (char **)malloc(sizeof(char *) * (numword(s,c ) + 1));
	if(!ptr)
	{
		return NULL;
	}
	while (count < worlds)
	{
//		printf("valor count %zu\n",count);
		while (*s == c && *s)
			s++;
		ptr[count] = malloc(sizeof(char) * (countworld(s, c) + 1));
		if (ptr[count] == NULL)
		{
			maximumfree(ptr, count);
			return NULL;
		}
		ptr[count] = ft_substr(s, 0, countworld(s, c));
		if (ptr[count] == NULL)
		{
			maximumfree(ptr, count);
			return NULL;
		}
		s += countworld(s, c);
		count++;	
	}
//	printf("valor de count %zu\n",count);
	ptr[count] = 0;
	return ptr;	
}

*/
