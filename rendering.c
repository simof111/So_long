/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfallahi <mfallahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:56:46 by mfallahi          #+#    #+#             */
/*   Updated: 2022/03/12 23:15:38 by mfallahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

int	destroy_window(struct s_map *map)
{
	int	i;

	i = -1;
	f_ree(map);
	mlx_destroy_window(map->mlx, map->mlx_win);
	write(1, "Exit\n", 5);
	exit(1);
	return (0);
}

void	render(struct s_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			s_render(map, map->str[i][j], i, j);
		}
	}
}

void	s_render(struct s_map *map, char c, int i, int j)
{
	if (c == '1')
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->wl, j * 50, i * 50);
	else
	{
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->fl, j * 50, i * 50);
		if (c == 'p')
			mlx_put_image_to_window(map->mlx, map->mlx_win,
				map->hc, j * 50, i * 50);
		else if (c == 'e')
			mlx_put_image_to_window(map->mlx, map->mlx_win,
				map->ext, j * 50, i * 50);
		else if (c == 'c')
			mlx_put_image_to_window(map->mlx, map->mlx_win,
				map->ch, j * 50, i * 50);
	}
}

void	game(struct s_map *map)
{
	int	width;
	int	height;

	map->hc = mlx_xpm_file_to_image(map->mlx, "xpm/Walk.xpm", &width, &height);
	map->ext = mlx_xpm_file_to_image(map->mlx, "xpm/hs.xpm", &width, &height);
	map->fl = mlx_xpm_file_to_image(map->mlx, "xpm/floor.xpm", &width, &height);
	map->wl = mlx_xpm_file_to_image(map->mlx, "xpm/wall.xpm", &width, &height);
	map->ch = mlx_xpm_file_to_image(map->mlx, "xpm/ch.xpm", &width, &height);
	render(map);
}
