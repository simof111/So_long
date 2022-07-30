/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfallahi <mfallahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:56:41 by mfallahi          #+#    #+#             */
/*   Updated: 2022/03/12 23:04:02 by mfallahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

int	mostatil_ola_morabae(char **str, int size_map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size_map)
	{
		j = -1;
		while (str[i][++j] != '\n' && str[i][j])
			;
		if (j != len_line1(str))
			return (0);
	}
	return (1);
}

int	map_round(char **str, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		if (i == 0 || i == size -1)
		{
			while (str[i][++j] != '\n' && str[i][j])
			{
				if (str[i][j] != '1')
					return (0);
			}
		}
		else
		{
			if (str[i][0] != '1' || str[i][len_line1(str) - 1] != '1')
				return (0);
		}
	}
	return (1);
}

int	player1_exitbzaf(char **str, int size, int p, int e)
{
	int	i;
	int	j;
	int	c;

	c = 0;
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (str[i][++j] != '\n' && str[i][j])
		{
			if (str[i][j] == 'p')
				p++;
			if (str[i][j] == 'e')
				e++;
			if (str[i][j] == 'c')
				c++;
		}
	}
	if (p != 1 || e == 0 || c == 0)
		return (0);
	return (1);
}

int	right_map(char *str)
{
	int	i;
	int	p;

	p = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '.')
			p++;
	}
	if (p != 1 || str[ft_strlen(str) - 1] != 'r'
		|| str[ft_strlen(str) - 2] != 'e' || str[ft_strlen(str) - 3] != 'b'
		|| str[ft_strlen(str) - 4] != '.')
		return (0);
	return (1);
}
