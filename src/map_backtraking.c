#include "../include/so_long.h"

void serch_player(char  **map , t_game *game)
{
	int row;
	int col;

	row = 0;
	col = 0;

	while (map[row] )
	{
		while(map[row][col])
		{
			if(map[row][col] == 'P')
			{
				game->pr = row;
				game->pc = col;
			}
			col++;
		}
		col = 0;
		row++;
	}
}

int bt_confirm(t_game *game, int  i, int j)
{
	while(game->map[i][j] != '1' && game->map[i][j] != 'X') 
	{
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
	//serch player
	serch_player(game->map, game);
	game->exit = 0;
//	printf("valor de p row%i , col%i",game->pr,game->pc);
//	printf("\n antes valor de p coin%i\n",game->coin);
	printf("\n############# antes valor de p exit%i ################\n",game->exit);
	bt_confirm(game, game->pr,game->pc);
//	printf("\ndespues valor de p coin%i\n",game->coin);
	printf("\n######### despues valor de p exit%i ##############\n",game->exit);
	if(game->coin != 0)
		printf("error de moneda");
	if(game->exit != 1)
		printf("\nerror de exit\n");
}
