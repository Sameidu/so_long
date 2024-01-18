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
	int	x;
	int	y;

	y = data->map.p_y - 1;
	x = data->map.p_x;
	if ((data->map.chart[y][x] == '0' || data->map.chart[y][x] == 'C'
		|| data->map.chart[y][x] == 'E') && data->map.chart[y][x] != '1')
	{
		if (data->map.chart[y][x] == 'C')
			data->map.count_coin--;
		if (data->map.chart[y][x] == 'E' && data->map.count_coin == 0)
		{
			ft_putendl_fd("You win!\nSteps: ", 1);
			ft_putnbr_fd(data->map.steps, 1);
			ft_putendl_fd("\n", 1);
			ft_kill_game(data);
		}
		data->map.chart[data->map.p_y][data->map.p_x] = '0';
		data->map.p_x = x;
		data->map.p_y = y;
		data->map.chart[data->map.p_y][data->map.p_x] = 'P';
	}
	ft_print_map(data, y, x);
}

void	ft_down(t_game *data)
{
	int	x;
	int	y;

	y = data->map.p_y + 1;
	x = data->map.p_x;
	if ((data->map.chart[y][x] == '0' || data->map.chart[y][x] == 'C'
		|| data->map.chart[y][x] == 'E') && data->map.chart[y][x] != '1')
	if (data->map.chart[y][x] == 'E' && data->map.count_coin == 0)
		{
			ft_putendl_fd("You win!\nSteps: ", 1);
			ft_putnbr_fd(data->map.steps, 1);
			ft_putendl_fd("\n", 1);
			ft_kill_game(data);
		}
	{
		if (data->map.chart[y][x] == 'C')
			data->map.count_coin--;
		data->map.chart[data->map.p_y][data->map.p_x] = '0';
		data->map.p_x = x;
		data->map.p_y = y;
		data->map.chart[data->map.p_y][data->map.p_x] = 'P';
	}
	ft_print_map(data, y, x);
}

void	ft_left(t_game *data)
{
	int	x;
	int	y;

	y = data->map.p_y;
	x = data->map.p_x - 1;
	if ((data->map.chart[y][x] == '0' || data->map.chart[y][x] == 'C'
		|| data->map.chart[y][x] == 'E') && data->map.chart[y][x] != '1')
	{
		if (data->map.chart[y][x] == 'C')
			data->map.count_coin--;
		if (data->map.chart[y][x] == 'E' && data->map.count_coin == 0)
		{
			ft_putendl_fd("You win!\nSteps: ", 1);
			ft_putnbr_fd(data->map.steps, 1);
			ft_putendl_fd("\n", 1);
			ft_kill_game(data);
		}
		data->map.chart[data->map.p_y][data->map.p_x] = '0';
		data->map.p_x = x;
		data->map.p_y = y;
		data->map.chart[data->map.p_y][data->map.p_x] = 'P';
		ft_print_map(data, y, x);
	}
}

void	ft_right(t_game *data)
{
	int	x;
	int	y;

	y = data->map.p_y;
	x = data->map.p_x + 1;
	if ((data->map.chart[y][x] == '0' || data->map.chart[y][x] == 'C'
		|| data->map.chart[y][x] == 'E') && data->map.chart[y][x] != '1')
	if (data->map.chart[y][x] == 'E' && data->map.count_coin == 0)
		{
			ft_putendl_fd("You win!\nSteps: ", 1);
			ft_putnbr_fd(data->map.steps, 1);
			ft_putendl_fd("\n", 1);
			ft_kill_game(data);
		}
	{
		if (data->map.chart[y][x] == 'C')
			data->map.count_coin--;
		data->map.chart[data->map.p_y][data->map.p_x] = '0';
		ft_print_map(data, y, x);
		data->map.p_x = x;
		data->map.p_y = y;
		data->map.chart[data->map.p_y][data->map.p_x] = 'P';
	}
	ft_print_map(data, y, x);
}

int	ft_read_key(int key, t_game *data)
{
	data->map.steps++;
	if (key == 53)
		ft_kill_game(data);
	else if (key == 13)
		ft_up(data);
	else if (key == 1)
		ft_down(data);
	else if (key == 0)
		ft_left(data);
	else if (key == 2)
		ft_right(data);
	ft_putstr_fd("Steps: ", 1);
	ft_putnbr_fd(data->map.steps, 1);
	return (0);
}
