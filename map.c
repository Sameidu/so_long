/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:15:44 by smeixoei          #+#    #+#             */
/*   Updated: 2023/07/25 19:15:44 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_walls(t_game *data, int y, int x)
{
	x = 0;
	y = (data->map.y - 1);
	while (x < data->map.x)
	{
		if (data->map.chart[0][x] != '1')
			ft_error("ERROR\nINVALID MAP");
		x++;
	}
	x = 0;
	while (x < data->map.x)
	{
		if (data->map.chart[y][x] != '1')
			ft_error("ERROR\nINVALID MAP");
		x++;
	}
	y = 1;
	x = (data->map.x - 1);
	while (y < data->map.y)
	{
		if (data->map.chart[y][0] != '1' || data->map.chart[y][x] != '1')
			ft_error("ERROR\nINVALID MAP");
		y++;
	}
}

void	ft_elements(t_game *data, int y, int x)
{
	int	p;
	int	e;

	p = 0;
	e = 0;
	y = 0;
	while (y < data->map.y - 1)
	{
		x = 0;
		while (x < data->map.x)
		{
			if (data->map.cp_chart[y][x] == 'C')
				data->map.count_coin++;
			if (data->map.cp_chart[y][x] == 'E')
				e++;
			if (data->map.cp_chart[y][x] == 'P')
				p++;
				data->map.p_x = x;
				data->map.p_y = y;
			x++;
		}
		y++;
	}
	if (e != 1 || p != 1 || data->map.count_coin < 1)
		ft_error("ERROR\nINVALID MAP");
}

void	ft_print_map(t_game *data, int y, int x)
{
	y = 0;
	while (y < data->map.y)
	{
		x = 0;
		while (x < data->map.x)
		{
			ft_put_img(data, data->map.chart[y][x], y, x);
			x++;
		}
		y++;
	}
}

void	ft_check_map(t_game *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	ft_check_walls(data, y, x);
	ft_elements(data, y, x);
	ft_check_move(data, y, x);
	ft_print_map(data, y, x);
}
