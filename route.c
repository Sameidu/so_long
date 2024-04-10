/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:08:18 by smeixoei          #+#    #+#             */
/*   Updated: 2024/04/10 20:00:18 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

static void	ft_route_map(t_game *data, int y, int x)
{
	if (data->map.chart[y][x] == 'C')
		data->map.chart[y][x] = 'K';
	if (data->map.chart[y][x] == '0')
		data->map.chart[y][x] = 'O';
}

static int	ft_exit(t_game *data, int y, int x)
{
	y = 0;
	while (y < data->map.y)
	{
		x = 0;
		while (x < data->map.x)
		{
			if ((data->map.chart[y][x] == 'E' && data->map.chart[y][x + 1] == 'P')
				|| (data->map.chart[y][x] == 'E' && data->map.chart[y][x + 1] == 'O')
				|| (data->map.chart[y][x] == 'E' && data->map.chart[y][x + 1] == 'K')
				|| (data->map.chart[y][x] == 'E' && data->map.chart[y][x - 1] == 'P')
				|| (data->map.chart[y][x] == 'E' && data->map.chart[y][x - 1] == 'O')
				|| (data->map.chart[y][x] == 'E' && data->map.chart[y][x - 1] == 'K')
				|| (data->map.chart[y][x] == 'E' && data->map.chart[y + 1][x] == 'P')
				|| (data->map.chart[y][x] == 'E' && data->map.chart[y + 1][x] == 'O')
				|| (data->map.chart[y][x] == 'E' && data->map.chart[y + 1][x] == 'K')
				|| (data->map.chart[y][x] == 'E' && data->map.chart[y - 1][x] == 'P')
				|| (data->map.chart[y][x] == 'E' && data->map.chart[y - 1][x] == 'O')
				|| (data->map.chart[y][x] == 'E' && data->map.chart[y - 1][x] == 'K'))
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
			if (data->map.chart[y][x] == 'C')
				ft_error("ERROR\nINVALID MAP");
			x++;
		}
		y++;
	}
	return (1);
}

static int	ft_route(t_game *data, int y, int x)
{
	if ((data->map.chart[y][x] == 'P' 
		|| data->map.chart[y][x] == 'K' || data->map.chart[y][x] == 'O')
		&& (data->map.chart[y][x + 1] == '0'
		|| data->map.chart[y][x + 1] == 'C'
		|| data->map.chart[y][x - 1] == '0'
		|| data->map.chart[y][x - 1] == 'C'
		|| data->map.chart[y + 1][x] == '0'
		|| data->map.chart[y + 1][x] == 'C'
		|| data->map.chart[y - 1][x] == '0'
		|| data->map.chart[y - 1][x] == 'C'))
			return (1);
	return (0);
}

int    ft_check_move(t_game *data, int y, int x)
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
