/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:15:30 by smeixoei          #+#    #+#             */
/*   Updated: 2023/07/25 19:15:30 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_floor(t_game *data, int y, int x)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->map.floor, x * SIZE, y * SIZE);
}

void	ft_put_obj(t_game *data, char value, int y, int x)
{
	if (value == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->map.wall, x * SIZE, y * SIZE);
	if (value == 'K')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->map.coin, x * SIZE, y * SIZE);
	if (value == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->map.exit, x * SIZE, y * SIZE);
	if (value == 'P')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->map.main, x * SIZE, y * SIZE);
}

void	ft_xpm_img(t_game *data)
{
	data->map.coin = mlx_xpm_file_to_image(data->mlx,
			"./art/heart.xpm", &data->w, &data->h);
	if (!data->map.coin)
		ft_error("No access to a xpm file coin");
	data->map.exit = mlx_xpm_file_to_image(data->mlx,
			"./art/brain.xpm", &data->w, &data->h);
	if (!data->map.exit)
		ft_error("No access to a xpm file exit");
	data->map.wall = mlx_xpm_file_to_image(data->mlx,
			"./art/skull.xpm", &data->w, &data->h);
	if (!data->map.wall)
		ft_error("No access to a xpm file wall");
	data->map.floor = mlx_xpm_file_to_image(data->mlx,
			"./art/7.xpm", &data->w, &data->h);
	if (!data->map.floor)
		ft_error("No access to a xpm file floor");
	data->map.main = mlx_xpm_file_to_image(data->mlx,
			"./art/pj.xpm", &data->w, &data->h);
	if (!data->map.main)
		ft_error("No access to a xpm file main");
}
