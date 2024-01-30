/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarameixoeiro <sarameixoeiro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:08:18 by smeixoei          #+#    #+#             */
/*   Updated: 2024/01/30 10:11:35 by sarameixoei      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

static void	ft_route_map(t_game *data, int y, int x)
{
	if (data->map.cp_chart[y][x] == 'C' || data->map.cp_chart[y][x] == '0')
		data->map.cp_chart[y][x] = 'P';
}

static int	ft_exit(t_game *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map.y)
	{
		x = 0;
		while (x < data->map.x)
		{
			if ((data->map.cp_chart[y][x] == 'E' && data->map.cp_chart[y][x + 1] == 'P')
				|| (data->map.cp_chart[y][x] == 'E' && data->map.cp_chart[y][x - 1] == 'P')
				|| (data->map.cp_chart[y][x] == 'E' && data->map.cp_chart[y + 1][x] == 'P')
				|| (data->map.cp_chart[y][x] == 'E' && data->map.cp_chart[y - 1][x] == 'P'))
				return (1);
			x++;
		}
		y++;
	}
	ft_error("ERROR\nINVALID MAP");
	return (0);
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
			if (data->map.cp_chart[y][x] == 'C')
				ft_error("ERROR\nINVALID MAP");
			x++;
		}
		y++;
	}
	return (1);
}

static int	ft_route(t_game *data, int y, int x)
{
	if (data->map.cp_chart[y][x] == 'P' &&
		(data->map.cp_chart[y][x + 1] == '0'
		|| data->map.cp_chart[y][x + 1] == 'C'
		|| data->map.cp_chart[y][x - 1] == '0'
		|| data->map.cp_chart[y][x - 1] == 'C'
		|| data->map.cp_chart[y + 1][x] == '0'
		|| data->map.cp_chart[y + 1][x] == 'C'
		|| data->map.cp_chart[y - 1][x] == '0'
		|| data->map.cp_chart[y - 1][x] == 'C'))
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
	if (ft_exit(data))
		return (1);
	return (0);
}
