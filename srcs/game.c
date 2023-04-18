/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahadir yigit <bahadiryigit0307@gmail.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:04:26 by bahadir yig       #+#    #+#             */
/*   Updated: 2023/04/18 18:11:31 by bahadir yig      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int		p_walk(t_game *game, int key)
{
	if (key == UP)
		return (game->map[game->player.y - 1][game->player.x] == '0');
	else if (key == DOWN )
		return (game->map[game->player.y + 1][game->player.x] == '0');
	else if (key == LEFT )
		return (game->map[game->player.y][game->player.x - 1] == '0');
	else if (key == RIGHT)
		return (game->map[game->player.y][game->player.x + 1] == '0');
	return (0);
}

void	draw_player(t_game *game)
{
	draw_background(game);
	if (game->player.dir == UP )
	{
		game->player.img.img = mlx_xpm_file_to_image(game->mlx.mlx,"xpms/./UP.xpm",
			&game->bg.size_x, &game->bg.size_y);
	}
	else if (game->player.dir == DOWN)
	{
		game->player.img.img = mlx_xpm_file_to_image(game->mlx.mlx,"xpms/./DOWN.xpm",
			&game->bg.size_x, &game->bg.size_y);
	}
	else if (game->player.dir == LEFT)
	{
		game->player.img.img = mlx_xpm_file_to_image(game->mlx.mlx,"xpms/./LEFT.xpm",
			&game->bg.size_x, &game->bg.size_y);
	}
	else {
		game->player.img.img = mlx_xpm_file_to_image(game->mlx.mlx,"xpms/./RIGHT.xpm",
			&game->bg.size_x, &game->bg.size_y);
	}
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->player.img.img,
		game->player.x * 32, game->player.y * 32);
}

int		key_events(int key, t_game *game)
{
	int	dis;

	dis = p_walk(game, key);
	if (key == UP && dis && key == game->player.dir)
		game->player.y--;
	else if (key == DOWN && dis && key == game->player.dir)
		game->player.y++;
	else if (key == LEFT && dis && key == game->player.dir)
		game->player.x--;
	else if (key == RIGHT && dis && key == game->player.dir)
		game->player.x++;
	if (LEFT <= key && key <= DOWN)
	{
		game->player.dir = key;
		draw_player(game);
	}
	printf("%d\n", game->player.dir);
	return (0);
}
