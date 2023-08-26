/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 04:44:09 by scespede          #+#    #+#             */
/*   Updated: 2023/08/27 00:31:51 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "../mlx/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_game
{
	char 	**map;
	char 	**maps;
	int		lenght_size;
	int		with_size;
	int		pjy;
	int		pjx;
	int		exitr;
	int		exitc;
	int		pr;
	int		pc;
	int		coin;
	int		exit;
	void	*mlx;
	void	*mlx_w;
	char	*dorrexit;
	char	*coin2;
	char	*wall;
	char	*pj;
	char	*floor;
}	t_game;




int map_add(int fd, t_game *game);
int	path_extension(char *av);
int map_error_size(t_game *game);
int map_tiles_correct(t_game *game);
t_game *ft_lsnew();
int errors_path(int error, t_game *game);
void	free_map(t_game *game, int error);
void print_map(char **map);
void serch_player(char **map, t_game *game);
int map_farlands(t_game *game);
int count_char(t_game *game, char pj2);
int map_char_events(t_game *game);
void map_backtraking(t_game *game);
int bt_confirm(t_game *game, int i, int j);
int draw_window(t_game *game);
void src_tiles(t_game *game);
int ft_close_game(t_game *game);
void add_path_img(t_game *game);
int moviment(int keycode, t_game *game);
int control_w( t_game *game);
int control_s( t_game *game);
int control_d( t_game *game);
int control_a( t_game *game);
void serch_exit(t_game *game);

#endif
