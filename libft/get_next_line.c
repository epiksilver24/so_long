/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:43:22 by scespede          #+#    #+#             */
/*   Updated: 2023/08/08 17:04:17 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>

char	*read_storage(int fd, char *stc)
{
	char	*temp_storage;
	int		read_bytes;

	temp_storage = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp_storage)
		return (free_storage(stc));
	read_bytes = 1;
	while (!ft_strchr2(stc, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, temp_storage, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free(temp_storage);
			if (stc)
				free(stc);
			return (NULL);
		}
		temp_storage[read_bytes] = '\0';
		stc = ft_strjoin2(stc, temp_storage);
	}
	free(temp_storage);
	temp_storage = NULL;
	return (stc);
}

char	*extract_line(char *storage)
{
	int		i;
	char	*line;

	i = 0;
	if (storage[0] == '\0')
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\0')
		line = malloc(sizeof(char) * (i + 1));
	else
		line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

void	*clean_storage(char *stc)
{
	int		i;
	int		j;
	char	*new_stc;

	i = 0;
	while (stc[i] && stc[i] != '\n')
		i++;
	if (!stc[i])
	{
		free(stc);
		return (NULL);
	}
	new_stc = malloc(sizeof(char) * (ft_strlen2(stc) - i + 1));
	if (!new_stc)
	{
		free(stc);
		return (NULL);
	}
	i++;
	j = 0;
	while (stc[i])
		new_stc[j++] = stc[i++];
	new_stc[j] = '\0';
	free(stc);
	return (new_stc);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stc;

	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		if (stc)
			free(stc);
		return (NULL);
	}
	if (!stc || (stc && !ft_strchr2(stc, '\n')))
		stc = read_storage(fd, stc);
	if (!stc)
		return (NULL);
	line = extract_line(stc);
	if (!line)
	{
		free(stc);
		stc = NULL;
		return (NULL);
	}
	stc = clean_storage(stc);
	return (line);
}
