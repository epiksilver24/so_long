#include "../../include/so_long.h"

int  path_extension(char *av)
{
	int len;

	len = ft_strlen(av);

	if(!((av[len - 1] == 'r') && (av[len -2] == 'e') 
				&& (av[len - 3] == 'b') && (av[len - 4] = '.')))
		return (-1);

	return (1);
}
