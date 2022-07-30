/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfallahi <mfallahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:56:49 by mfallahi          #+#    #+#             */
/*   Updated: 2022/03/14 23:28:51 by mfallahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdlib.h>

struct s_map{
	void	*mlx;
	void	*mlx_win;
	void	*hc;
	void	*fl;
	void	*wl;
	void	*ext;
	void	*ch;
	int		height;
	int		width;
	int		collect;
	int		moves;
	int		x;
	int		y;
	char	**str;
};

void		f_ree(struct s_map *map);
int			ft_strlen(char *str);
char		*ft_strdup(const char *src);
char		*gnl(int fd);
int			size_map(int fd);
char		**map_to_str(int fd, int size);
int			len_line1(char **str);
int			mostatil_ola_morabae(char **str, int size_map);
int			map_round(char **str, int size);
int			player1_exitbzaf(char **str, int size, int p, int e);
int			right_map(char *str);
void		render(struct s_map *map);
void		game(struct s_map *map);
void		pos(struct s_map *map);
void		collect_count(struct s_map *map);
void		map_init(struct s_map *map, char *str);
int			destroy_window(struct s_map *map);
void		player_mv(struct s_map *map, int p_y, int p_x);
int			key_hook(int kc, struct s_map *map);
long long	ft_atoi(const char *nptr);
void		s_render(struct s_map *map, char c, int i, int j);

#endif
