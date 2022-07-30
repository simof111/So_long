/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfallahi <mfallahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:56:25 by mfallahi          #+#    #+#             */
/*   Updated: 2022/03/12 22:56:26 by mfallahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

void	f_ree(struct s_map *map)
{
	int	i;

	i = -1;
	while (++i < map->height)
		free(map->str[i]);
	free(map->str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*s;

	i = 0;
	while (src[i])
		i++;
	s = (char *)malloc(i + 1);
	if (s == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		s[i] = src[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*gnl(int fd)
{
	char	str[8000000];
	int		i;
	char	buff[1];
	int		byte;

	byte = read(fd, buff, 1);
	i = 0;
	while (byte > 0)
	{
		str[i++] = buff[0];
		if (buff[0] == '\n')
			break ;
		byte = read(fd, buff, 1);
	}
	str[i] = '\0';
	if (str[0] == '\0')
		return (0);
	return (ft_strdup(str));
}

long long	ft_atoi(const char *nptr)
{
	int			i;
	int			signe;
	long long	rslt;

	i = 0;
	signe = 1;
	rslt = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signe *= -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		rslt = rslt * 10 + nptr[i] - 48;
		i++;
	}
	return (rslt * signe);
}
