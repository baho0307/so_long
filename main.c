/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahadir yigit <bahadiryigit0307@gmail.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:00:33 by bahadir yig       #+#    #+#             */
/*   Updated: 2023/04/18 18:03:48 by bahadir yig      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	create_game(char *filename)
{
	t_game	game;

	game.mlx.mlx = mlx_init();
	game.mlx.x_size = 512;
	game.mlx.y_size = 512;
	game.mlx.win = mlx_new_window(game.mlx.mlx, game.mlx.x_size, game.mlx.y_size,
		"AAAAA");
	game.map = read_map(filename);
	get_player(&game);
	draw_player(&game);
	return (game);
}

int	main(int argc, char *argv[])
{
	t_game game;

	game = create_game(argv[argc - 1]);
	write_map(game.map);
	mlx_hook(game.mlx.win,3, (1L<<1), key_events, &game);
	mlx_loop(game.mlx.mlx);
}
