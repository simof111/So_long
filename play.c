/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfallahi <mfallahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:56:43 by mfallahi          #+#    #+#             */
/*   Updated: 2022/03/14 23:22:46 by mfallahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long	nb;

	nb = n;
	if (n < 0)
	{
		nb *= -1;
		ft_putchar('-');
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	else
		ft_putchar('0' + nb);
}

int	key_hook(int kc, struct s_map *map)
{
	if (kc == 53)
		destroy_window(map);
	if (kc == 0)
		player_mv(map, 0, -1);
	if (kc == 1)
		player_mv(map, 1, 0);
	if (kc == 2)
		player_mv(map, 0, 1);
	if (kc == 13)
		player_mv(map, -1, 0);
	return (0);
}

void	player_mv(struct s_map *map, int p_y, int p_x)
{
	if (map->str[map->y + p_y][map->x + p_x] != '1')
	{
		if (map->str[map->y + p_y][map->x + p_x] == 'c')
			map->collect--;
		if (map->str[map->y + p_y][map->x + p_x] == 'e' && !map->collect)
		{
			f_ree(map);
			write(1, "vous avez gagner\n", 17);
			mlx_destroy_window(map->mlx, map->mlx_win);
			exit(1);
		}
		if (map->str[map->y + p_y][map->x + p_x] == 'e' \
				&& map->collect)
			return ;
		map->str[map->y + p_y][map->x + p_x] = 'p';
		map->str[map->y][map->x] = '0';
		map->y += p_y;
		map->x += p_x;
		map->moves++;
		write(1, "Moves : ", 8);
		ft_putnbr(map->moves);
		ft_putchar('\n');
		render(map);
	}
}
