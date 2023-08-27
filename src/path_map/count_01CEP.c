#include "../../include/so_long.h"

int count_char(t_game *game, char pj2)
{
	int row;
	int col;
	int pj;

	row = -1;
	col = 0;
	pj = 0;
	while (game->map[++row])
	{
		while (game->map[row][col] && pj < 2)
		{
			if (game->map[row][col] == pj2)
				pj++;
			col++;
		}
		col = 0;
	}
	if (pj == 0 || pj > 1)
		return (-8);
	return (0);
}



