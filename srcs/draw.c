/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahadir yigit <bahadiryigit0307@gmail.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 04:05:53 by bahadir yig       #+#    #+#             */
/*   Updated: 2023/04/18 17:45:26 by bahadir yig      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	my_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *) dst = color;
}

void	sq_put(t_img *data, int x, int y, int color, int size)
{
	int	i;

	i = 0;
	while (i < size * size)
	{
		my_pixel_put(data, (i % size) + x, (i / size) + y, color);
		i++;
	}
}

void	draw_background(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	game->bg.img = mlx_new_image(game->mlx.mlx, game->mlx.x_size,game->mlx.y_size);
	game->bg.addr = mlx_get_data_addr(game->bg.img,
		&game->bg.bpp, &game->bg.line_length, &game->bg.endian);
	sq_put(&game->bg, 0, 0, 0x00306951, game->mlx.y_size);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->bg.img, 0, 0);
	game->bg.img = mlx_xpm_file_to_image(game->mlx.mlx,"xpms/./1.xpm",
	&game->bg.size_x, &game->bg.size_y);
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
			{
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
				game->bg.img, x * 32, y * 32);
			}
			x++;
		}
		y++;
	}
}
