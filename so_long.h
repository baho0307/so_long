/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahadir yigit <bahadiryigit0307@gmail.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 18:50:56 by bahadir yig       #+#    #+#             */
/*   Updated: 2023/04/18 16:39:21 by bahadir yig      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "mlx_linux/mlx.h"

#define LEFT (65361)
#define RIGHT (65363)
#define UP (65362)
#define DOWN (65364)

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	int		x_size;
	int		y_size;
}	t_mlx;

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		size_x;
	int		size_y;
}	t_img;

typedef struct	s_player
{
	int		x;
	int		y;
	int		dir;
	t_img	img;
}	t_player;

typedef struct	s_game
{
	t_mlx		mlx;
	char		**map;
	t_img		bg;
	t_player	player;
}	t_game;

int		check(char c, char *map);
char	**alloc_map(char *filename);
char	**read_map(char *filename);
void	ft_putchar(char c);
void	write_map(char **map);
void	my_pixel_put(t_img *data, int x, int y, int color);
void	sq_put(t_img *data, int x, int y, int color, int size);
void	draw_background(t_game *game);
void	draw_player(t_game *game);
int		get_player(t_game *game);
int		key_events(int key, t_game *game);
int		ft_strlen(char *str);
char	*ft_strcat(char *dest, char *src);

#endif
