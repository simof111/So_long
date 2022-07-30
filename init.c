/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfallahi <mfallahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:56:31 by mfallahi          #+#    #+#             */
/*   Updated: 2022/03/12 22:56:32 by mfallahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

int	size_map(int fd)
{
	int		i;
	char	*str;

	i = 0;
	str = gnl(fd);
	if (str == NULL)
		return (0);
	while (str)
	{
		i++;
		free(str);
		str = NULL;
		str = gnl(fd);
	}
	free(str);
	return (i);
}

char	**map_to_str(int fd, int size)
{
	char	**str;
	int		i;

	i = -1;
	str = (char **)malloc(sizeof(char *) * (size + 1));
	if (str == NULL)
		return (NULL);
	while (++i < size)
		str[i] = gnl(fd);
	str[i] = 0;
	return (str);
}

int	len_line1(char **str)
{
	int	len;

	len = 0;
	while (str[0][len] != '\n')
		len++;
	return (len);
}

void	pos(struct s_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->str[i][j] == 'p')
			{
				map->x = j;
				map->y = i;
			}
		}
	}
}

void	collect_count(struct s_map *map)
{
	int	i;
	int	j;

	i = -1;
	map->collect = 0;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->str[i][j] == 'c')
				map->collect++;
		}
	}
}
