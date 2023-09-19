/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:08:18 by smeixoei          #+#    #+#             */
/*   Updated: 2023/09/19 20:17:35 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

static void	ft_route_map(t_game *data, int y, int x)
{
	//printf("%s x[%i], y[%i]-> %c\n", "aqui bb estoy perrote, entra por cojones", x, y, data->map.chart[x][y]);
	if (data->map.cp_chart[y][x] == 'C' || data->map.cp_chart[y][x] == '0'){
	//	printf("%s\n", "aqui bb estoy perrote, entra por cojones, me haces daño");
		data->map.cp_chart[y][x] = 'P';
	}
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
	static int i = 0;
	i++;
	printf("iter -> %i\n", i);
	
	if(data->map.cp_chart[y][x] == 'P')
			printf("%s\n", "aqui bb estoy perrote");
	if (data->map.cp_chart[y][x] == 'P' &&
		(data->map.cp_chart[y][x + 1] == '0'
		|| data->map.cp_chart[y][x + 1] == 'C'
		|| data->map.cp_chart[y][x - 1] == '0'
		|| data->map.cp_chart[y][x - 1] == 'C'
		|| data->map.cp_chart[y + 1][x] == '0'
		|| data->map.cp_chart[y + 1][x] == 'C'
		|| data->map.cp_chart[y - 1][x] == '0'
		|| data->map.cp_chart[y - 1][x] == 'C'))
		{
			printf("%s\n", "aqui bb");
			return (1);
		}
	return (0);
}

int    ft_check_move(t_game *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map.y)
	{
		x = 0;
		while (x < data->map.x)
		{
			int c = 0;
			while (data->map.chart[c])
			{
				printf("%s\n", data->map.cp_chart[c++]);
			}
			printf("\n");
			if (ft_route(data, y, x))
				{
					ft_route_map(data, y + 1, x);
					ft_route_map(data, y - 1, x);
					ft_route_map(data, y, x + 1);
					ft_route_map(data, y, x - 1);
					x = 0;
					printf("%s\n", "aqui");
				}
				x++;
			//fprintf(stderr, "x\n");
		}
		fprintf(stderr, "y = %i\n", y);
		y++;
	}
	ft_check_coin(data);
	if (ft_exit(data))
	{
		printf("%s\n", "aqui");
		return (1);
	}
	return (0);
}
