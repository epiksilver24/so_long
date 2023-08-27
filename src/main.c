/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 04:45:10 by scespede          #+#    #+#             */
/*   Updated: 2023/08/28 00:43:18 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <unistd.h>
#include <fcntl.h>

t_game	*ft_lsnew(void)
{
	t_game	*game;

	game = malloc(sizeof(*game));
	if (!game)
		return (NULL);
	game->map = NULL;
	game->lenght_size = -1;
	game->with_size = -1;
	game->move = 1;
	game->coin = 0;
	return (game);
}

int	main(int ac, char **av )
{
	t_game	*game;

	game = ft_lsnew();
	if (ac != 2)
		return (0);
	if (ft_map_path(av[1], game) == 0)
		return (0);
	start_mlx(game);
	ft_putstr_fd("start Game", 1);
	mlx_hook(game->mlx_w, 17, 1L << 0, (void *) exit, NULL);
	mlx_hook(game->mlx_w, 2, 1L << 0, (void *) moviment, game);
	mlx_loop(game->mlx);
	return (0);
}

int	moviment(int keycode, t_game *game)
{
	int	works;

	works = 0;
	if (keycode == 53)
		destroy_game(game);
	if (keycode == 13 || keycode == 126)
		works = control_w(game);
	if (keycode == 1 || keycode == 125)
		works = control_s(game);
	if (keycode == 2 || keycode == 124)
		works = control_d(game);
	if (keycode == 0 || keycode == 123)
		works = control_a(game);
	if (works)
	{
		draw_window(game);
		ft_putstr_fd("\nmove numero = ", 1);
		ft_putnbr_fd(game->move++, 1);
	}
	return (works);
}
