/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:08:18 by smeixoei          #+#    #+#             */
/*   Updated: 2024/04/11 21:42:14 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_route_map(t_game *data, int y, int x)
{
	if (data->map.map[y][x] == 'C')
		data->map.map[y][x] = 'K';
	if (data->map.map[y][x] == '0')
		data->map.map[y][x] = 'O';
}

static int	ft_exit(t_game *data, int y, int x)
{
	y = 0;
	while (y < data->map.y)
	{
		x = 0;
		while (x < data->map.x)
		{
			if ((data->map.map[y][x] == 'E' && data->map.map[y][x + 1] == 'P')
			|| (data->map.map[y][x] == 'E' && data->map.map[y][x + 1] == 'O')
			|| (data->map.map[y][x] == 'E' && data->map.map[y][x + 1] == 'K')
			|| (data->map.map[y][x] == 'E' && data->map.map[y][x - 1] == 'P')
			|| (data->map.map[y][x] == 'E' && data->map.map[y][x - 1] == 'O')
			|| (data->map.map[y][x] == 'E' && data->map.map[y][x - 1] == 'K')
			|| (data->map.map[y][x] == 'E' && data->map.map[y + 1][x] == 'P')
			|| (data->map.map[y][x] == 'E' && data->map.map[y + 1][x] == 'O')
			|| (data->map.map[y][x] == 'E' && data->map.map[y + 1][x] == 'K')
			|| (data->map.map[y][x] == 'E' && data->map.map[y - 1][x] == 'P')
			|| (data->map.map[y][x] == 'E' && data->map.map[y - 1][x] == 'O')
			|| (data->map.map[y][x] == 'E' && data->map.map[y - 1][x] == 'K'))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

static int	ft_check_coin(t_game *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map.y)
	{
		x = 0;
		while (x < data->map.x)
		{
			if (data->map.map[y][x] == 'C')
				ft_error("Error\nInvalid map");
			x++;
		}
		y++;
	}
	return (1);
}

static int	ft_route(t_game *data, int y, int x)
{
	if ((data->map.map[y][x] == 'P' || data->map.map[y][x] == 'E'
		|| data->map.map[y][x] == 'K' || data->map.map[y][x] == 'O')
		&& (data->map.map[y][x + 1] == '0'
		|| data->map.map[y][x + 1] == 'C'
		|| data->map.map[y][x - 1] == '0'
		|| data->map.map[y][x - 1] == 'C'
		|| data->map.map[y + 1][x] == '0'
		|| data->map.map[y + 1][x] == 'C'
		|| data->map.map[y - 1][x] == '0'
		|| data->map.map[y - 1][x] == 'C'))
		return (1);
	return (0);
}

int	ft_check_move(t_game *data, int y, int x)
{
	y = 0;
	while (y < data->map.y)
	{
		x = 0;
		while (x < data->map.x)
		{
			if (ft_route(data, y, x))
			{
				ft_route_map(data, y + 1, x);
				ft_route_map(data, y - 1, x);
				ft_route_map(data, y, x + 1);
				ft_route_map(data, y, x - 1);
				y = 0;
			}
			x++;
		}
		y++;
	}
	ft_check_coin(data);
	y = 0;
	x = 0;
	if (ft_exit(data, y, x) == 1)
		return (1);
	return (0);
}
