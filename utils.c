/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:08:18 by smeixoei          #+#    #+#             */
/*   Updated: 2023/08/14 11:11:59 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void	ft_route_map(t_game *data, int x, int y)
{
	if (data->map.cp_chart[y][x] == 'C' || data->map.cp_chart[y][x] == '0')
		data->map.cp_chart[y][x] == 'P';
}

int	ft_exit(t_game *data, int x, int y)
{
	if (data->map.cp_chart[y][x] == 'P' &&
		(data->map.cp_chart[y][x] == '0'
		|| data->map.cp_chart[y][x] == 'C'
		|| data->map.cp_chart[y][x] == '0'
		|| data->map.cp_chart[y][x] == 'C'))
}

int    ft_flood_fill(t_game *data)
{
    int	x;
	int	y;

	y = 0;
	while (y < data->map.y)
	{
		x = 0;
		while (x < data->map.x)
		{
			if (ft_exit(data, x, y))
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
	if (ft_route(data))
		return (1);
	return (0);
}
