/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahadir yigit <bahadiryigit0307@gmail.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:07:45 by bahadir yig       #+#    #+#             */
/*   Updated: 2023/04/18 04:22:47 by bahadir yig      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**alloc_map(char *filename)
{
	char	**map;
	char	c;
	int		fd;
	int		x;
	int		y;

	x = 0;
	y = 0;
	fd = open(filename, O_RDONLY);
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			y++;
		else if (!y && ((c == '1') || (c == '0') || (c == 'P') || (c == 'C')
		|| (c == 'E')))
			x++;
	}
	close(fd);
	fd = 0;
	map = (char **) malloc(sizeof(char*) * (y + 1));
	while (fd < y + 1)
		map[fd++] = (char *) malloc(sizeof(char) * (x + 1));
	printf("%d %d \n", x, y);
	return (map);
}


int		check(char c, char *map)
{
	if (!((c == '1') || (c == '0') || (c == 'P') || (c == 'C') || (c == 'E')))
		return (0);
	*map = c;
	return (1);
}

char	**read_map(char *filename)
{
	char	**map;
	int		x;
	int		y;
	char	c;
	int fd;

	x = 0;
	y = 0;
	map = alloc_map(filename);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	while (read(fd, &c, 1))
	{
		x += check(c, &(map[y][x]));
		if (c == '\n')
		{
			y++;
			x = 0;
		}
	}
	map[y] = NULL;
	close(fd);
	return (map);
}

int		get_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if  (game->map[i][j] == 'P')
			{
				game->player.x = j;
				game->player.y = i;
				game->map[i][j] = '0';
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
