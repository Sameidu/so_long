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

void	ft_count_obj(t_game *data, int y, int x, t_count *count)
{
	if (data->map.map[y][x] == 'C')
		data->map.count_coin++;
	if (data->map.map[y][x] == 'E')
		count->e++;
	if (data->map.map[y][x] == 'P')
	{
		count->p++;
		data->map.p_x = ((data->map.p_y = y), x);
	}
}

void	ft_check_walls(t_game *data, int y, int x)
{
	x = 0;
	y = (data->map.y - 1);
	while (x < data->map.x)
	{
		if (data->map.map[0][x] != '1')
			ft_error("Error\nInvalid map\n");
		x++;
	}
	x = 0;
	while (x < data->map.x)
	{
		if (data->map.map[y][x] != '1')
			ft_error("Error\nInvalid map\n");
		x++;
	}
	y = 1;
	x = (data->map.x - 1);
	while (y < data->map.y)
	{
		if (data->map.map[y][0] != '1' || data->map.map[y][x] != '1')
			ft_error("Error\nInvalid map\n");
		y++;
	}
}

void	ft_elements(t_game *data, int y, int x)
{
	t_count	count;

	data->map.count_coin = ((y = 0), 0);
	while (y < data->map.y - 1)
	{
		x = 0;
		while (x < data->map.x)
		{
			ft_count_obj(data, y, x, &count);
			x++;
		}
		y++;
	}
	if (count.e != 1 || count.p != 1 || data->map.count_coin < 1)
		ft_error("Error\nInvalid map\n");
}

void	ft_print_map(t_game *data, int y, int x)
{
	y = 0;
	while (y < data->map.y)
	{
		x = 0;
		while (x < data->map.x)
		{
			ft_put_floor(data, y, x);
			ft_put_obj(data, data->map.map[y][x], y, x);
			x++;
		}
		y++;
	}
}

void	ft_check_map(t_game *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map.y)
	{
		x = 0;
		while (x <= data->map.map[y][x])
			x++;
		if (x != data->map.x)
			ft_error("Error\n Invalid map");
		y++;
	}
	x = 0;
	y = 0;
	ft_check_walls(data, y, x);
	ft_elements(data, y, x);
	if (ft_check_move(data, y, x) == 1)
		ft_error("Error\nInvalid mpa\n");
	ft_print_map(data, y, x);
}
