#include "../include/so_long.h"

void print_map(char **map)
{
	int i;
	
	i = 0;
	write(1,"\n",1);
	while (map[i])
	{
		printf("%s\n",map[i]);
		i++;
	}
}
