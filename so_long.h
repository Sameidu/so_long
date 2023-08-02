/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:08:29 by smeixoei          #+#    #+#             */
/*   Updated: 2023/08/02 18:00:55 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "./minilibx_linux/mlx.h"
# include "./minilibx_mac/mlx.h"
# include "./libft/libft.h"

# define SIZE 32

typedef struct s_map
{
	void	*main;
	void	*exit;
	void	*coin;
	void	*floor;
	void	*wall;
	int		x;
	int		y;
	char	**chart;
}			t_map;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
	int		w;
	int		h;
	int		key;
	t_map	map;	
}			t_game;

void	ft_check_file(t_game *data, char *map);
void	ft_error(char *str);
int		ft_ext(char *map);
void	ft_put_img(t_game *data);
void	ft_xpm_img(t_game *data);
int		ft_read_key(t_game *data);

#endif