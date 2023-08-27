#include "../../include/so_long.h"

void serch_player(char  **map , t_game *game)
{
	int row;
	int col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while(map[row][col])
		{
			if(map[row][col] == 'P')
			{
				game->pr = row;
				game->pc = col;
			}
		//	if (map[row][col] == 'C')
		//		game->coin++;
			col++;
		}
		row++;
	}
}


void serch_exitrc(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (game->maps[row])
	{
		col = 0;
		while (game->maps[row][col])
		{
			if(game->maps[row][col] == 'E')
			{
				game->exitr = row;
				game->exitc = col;
			}
			if (game->maps[row][col] == 'C')
				game->coin++;
			col++;
		}
		row++;
	}
}


int bt_confirm(t_game *game, int  i, int j)
{
	while(game->map[i][j] != '1' && game->map[i][j] != 'X') 
	{
		if (game->map[i][j] == 'P')
		{
			game->pjy = i;
			game->pjx = j;
		}
		if(game->map[i][j] == 'C')
			game->coin--;
		if(game->map[i][j] == 'E')
			game->exit++;
		game->map[i][j] = 'X';
		bt_confirm(game, i + 1, j);
		bt_confirm(game, i - 1, j);
		bt_confirm(game, i , j + 1);
		bt_confirm(game, i, j - 1);
	}
	return (0);
}

void map_backtraking(t_game *game)
{
	serch_player(game->map, game);
	game->exit = 0;
	bt_confirm(game, game->pr,game->pc);
	if(game->coin != 0)
		printf("error de moneda");
	if(game->exit != 1)
		printf("\nerror de exit\n");
//	game->coin = 0;
	serch_exitrc(game);
}
