#include "../include/so_long.h"

int  path_extension(char *av)
{
	int len;

	len = ft_strlen(av);
//	if(!((av[1][len - 1] == 'r') && (av[1][len -2] == 'e') 
//				&& (av[1][len - 3] == 'b') && (av[1][len - 4] = '.')))
//		return (-1);

	if(!((av[len - 1] == 'r') && (av[len -2] == 'e') 
				&& (av[len - 3] == 'b') && (av[len - 4] = '.')))
		return (-1);

	return (1);
}
