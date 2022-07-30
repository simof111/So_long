/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfallahi <mfallahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:56:19 by mfallahi          #+#    #+#             */
/*   Updated: 2022/03/14 23:27:58 by mfallahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

void	map_init(struct s_map *map, char *str)
{
	int	fd;

	fd = open(str, O_RDWR);
	map->height = size_map(fd);
	close(fd);
	if (!map->height)
		return ;
	fd = open(str, O_RDWR);
	map->str = map_to_str(fd, map->height);
	close(fd);
	map->width = len_line1(map->str);
	pos(map);
	collect_count(map);
}

int	main(int ac, char **av)
{
	struct s_map	map;

	if (ac == 2)
	{
		map_init(&map, av[1]);
		if (!right_map(av[1]) || !mostatil_ola_morabae(map.str, map.height)
			|| !map_round(map.str, map.height)
			|| !player1_exitbzaf(map.str, map.height, 0, 0))
		{
			write (1, "Error mapping\n", 14);
			f_ree(&map);
			exit(1);
		}
		map.mlx = mlx_init();
		map.mlx_win = mlx_new_window(map.mlx, map.width * 50,
				map.height * 50, "So long");
		game(&map);
		mlx_hook(map.mlx_win, 17, 0, destroy_window, &map);
		mlx_hook(map.mlx_win, 2, 0, key_hook, &map);
		mlx_loop(map.mlx);
		f_ree(&map);
	}
	else
		write (1, "manque argument\n", 16);
	return (0);
}
