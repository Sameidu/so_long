/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:08:29 by smeixoei          #+#    #+#             */
/*   Updated: 2023/07/26 18:26:30 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "./minilibx/mlx.h"
# include "./libft/libft.h"

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
	int		w;
	int		h;
	int		x;
	int		y;
	int		pos_c;
	int		pos_p;
	int		post_e;
	int		pos_1;
	int		pos_0;
	char	*map;	
}			t_game;

void	ft_check_file(t_game *data, char *map);
void	ft_error(char *str);
int		ft_ext(char *map);

#endif