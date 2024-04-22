/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:15:38 by smeixoei          #+#    #+#             */
/*   Updated: 2024/04/11 19:10:09 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_up(t_game *data)
{
	int	x;
	int	y;

	y = ((x = data->map.p_x), data->map.p_y - 1);
	if (data->map.chart[y][x] != '1')
	{
		if (data->map.chart[y][x] == 'K')
			data->map.count_coin--;
		if (data->map.chart[y][x] == 'E' && data->map.count_coin == 0)
		{
			ft_putnbr_fd(data->map.steps, 1);
			ft_kill_game(data);
		}
		if (data->map.chart[data->map.p_y][data->map.p_x] != 'E')
            data->map.chart[data->map.p_y][data->map.p_x] = 'O';
		data->map.p_y = ((data->map.p_x = x), y);
		if (data->map.chart[data->map.p_y][data->map.p_x] != 'E')
            data->map.chart[data->map.p_y][data->map.p_x] = 'P';
		data->map.steps++;
		ft_print_map(data, data->map.p_y, data->map.p_x);
	}
}

void	ft_down(t_game *data)
{
	int	x;
	int	y;

	y = ((x = data->map.p_x), data->map.p_y + 1);
	if ( data->map.chart[y][x] != '1')
	{
		if (data->map.chart[y][x] == 'K')
			data->map.count_coin--;
		if (data->map.chart[y][x] == 'E' && data->map.count_coin == 0)
		{
			ft_putnbr_fd(data->map.steps, 1);
			ft_kill_game(data);
		}
		if (data->map.chart[data->map.p_y][data->map.p_x] != 'E')
            data->map.chart[data->map.p_y][data->map.p_x] = 'O';
		data->map.p_y = ((data->map.p_x = x), y);
		if (data->map.chart[data->map.p_y][data->map.p_x] != 'E')
           data->map.chart[data->map.p_y][data->map.p_x] = 'P';
		data->map.steps++;
		ft_print_map(data, data->map.p_y, data->map.p_x);
	}
}

void	ft_left(t_game *data)
{
	int	x;
	int	y;

	y = ((x = data->map.p_x - 1), data->map.p_y);
	if (data->map.chart[y][x] != '1')
	{
		if (data->map.chart[y][x] == 'K')
			data->map.count_coin--;
		if (data->map.chart[y][x] == 'E' && data->map.count_coin == 0)
		{
			ft_putnbr_fd(data->map.steps, 1);
			ft_kill_game(data);
		}
		if (data->map.chart[data->map.p_y][data->map.p_x] != 'E')
            data->map.chart[data->map.p_y][data->map.p_x] = 'O';
		data->map.p_x = ((data->map.p_y = y), x);
		if (data->map.chart[data->map.p_y][data->map.p_x] != 'E')
            data->map.chart[data->map.p_y][data->map.p_x] = 'P';
		data->map.steps++;
		ft_print_map(data, data->map.p_y, data->map.p_x);
	}
}

void	ft_right(t_game *data)
{
	int	x;
	int	y;

	y = ((x = data->map.p_x + 1), data->map.p_y);
	if (data->map.chart[y][x] != '1')
	{
		if (data->map.chart[y][x] == 'K')
			data->map.count_coin--;
		if (data->map.chart[y][x] == 'E' && data->map.count_coin == 0)
		{
			ft_putnbr_fd(data->map.steps, 1);
			ft_kill_game(data);
		}
		if (data->map.chart[data->map.p_y][data->map.p_x] != 'E')
            data->map.chart[data->map.p_y][data->map.p_x] = 'O';
		data->map.p_x = ((data->map.p_y = y), x);
		if (data->map.chart[data->map.p_y][data->map.p_x] != 'E')
            data->map.chart[data->map.p_y][data->map.p_x] = 'P';
		data->map.steps++;
		ft_print_map(data, data->map.p_y, data->map.p_x);
	}
}

int	ft_read_key(int key, t_game *data)
{
	if (key == 53)
		ft_kill_game(data);
	else if (key == 13 || key == 126)
		ft_up(data);
	else if (key == 1 || key == 125)
		ft_down(data);
	else if (key == 0 || key == 123)
		ft_left(data);
	else if (key == 2 || key == 124)
		ft_right(data);
	ft_putnbr_fd(data->map.steps, 1);
	ft_putstr_fd("\n", 1);
	return (0);
}
