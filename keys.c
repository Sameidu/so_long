/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:15:38 by smeixoei          #+#    #+#             */
/*   Updated: 2023/07/25 19:15:38 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_up(t_game *data)
{
    int x;
    int y;

	y = data->map.p_y - 1;
	x = data->map.p_x;
    if (y >= 0 && data->map.chart[y][x] != '1')
    {
        data->map.chart[data->map.p_y][data->map.p_x] = '0';
        data->map.p_x = x;
        data->map.p_y = y;
        data->map.chart[data->map.p_y][data->map.p_x] = 'P';
    }
}

void	ft_down(t_game *data)
{
    int x;
    int y;

	y = data->map.p_y + 1;
	x = data->map.p_x;
    if (y >= 0 && data->map.chart[y][x] != '1')
    {
        data->map.chart[data->map.p_y][data->map.p_x] = '0';
        data->map.p_x = x;
        data->map.p_y = y;
        data->map.chart[data->map.p_y][data->map.p_x] = 'P';
    }
}

void	ft_left(t_game *data)
{
    int x;
    int y;

	y = data->map.p_y;
	x = data->map.p_x - 1;
    if (x >= 0 && data->map.chart[y][x] != '1')
    {
        data->map.chart[data->map.p_y][data->map.p_x] = '0';
        data->map.p_x = x;
        data->map.p_y = y;
        data->map.chart[data->map.p_y][data->map.p_x] = 'P';
    }
}

void	ft_right(t_game *data)
{
    int x;
    int y;

	y = data->map.p_y;
	x = data->map.p_x + 1;
    if (x >= 0 && data->map.chart[y][x] != '1')
    {
        data->map.chart[data->map.p_y][data->map.p_x] = '0';
        data->map.p_x = x;
        data->map.p_y = y;
        data->map.chart[data->map.p_y][data->map.p_x] = 'P';
    }
}

int	ft_read_key(int key, t_game *data)
{
    data->map.steps++;
	if (key == 53)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		free (data);
		exit (0);
	}
	else if (key == 13)
		ft_up(data);
	else if (key == 1)
		ft_down(data);
	else if (key == 0)
		ft_left(data);
	else if (key == 2)
		ft_right(data);
	return (0);		
}