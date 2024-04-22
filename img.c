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
		data->map.f, x * SIZE, y * SIZE);
}

void	ft_put_obj(t_game *data, char value, int y, int x)
{
	if (value == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->map.w, x * SIZE, y * SIZE);
	if (value == 'K')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->map.c, x * SIZE, y * SIZE);
	if (value == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->map.e, x * SIZE, y * SIZE);
	if (value == 'P')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->map.m, x * SIZE, y * SIZE);
}

void	ft_xpm_img(t_game *data)
{
	data->map.c = mlx_xpm_file_to_image(data->mlx,
			"./art/heart.xpm", &data->w, &data->h);
	if (!data->map.c)
		ft_error("No access to a xpm file coin");
	data->map.e = mlx_xpm_file_to_image(data->mlx,
			"./art/brain.xpm", &data->w, &data->h);
	if (!data->map.e)
		ft_error("No access to a xpm file exit");
	data->map.w = mlx_xpm_file_to_image(data->mlx,
			"./art/skull.xpm", &data->w, &data->h);
	if (!data->map.w)
		ft_error("No access to a xpm file wall");
	data->map.f = mlx_xpm_file_to_image(data->mlx,
			"./art/7.xpm", &data->w, &data->h);
	if (!data->map.f)
		ft_error("No access to a xpm file floor");
	data->map.m = mlx_xpm_file_to_image(data->mlx,
			"./art/pj.xpm", &data->w, &data->h);
	if (!data->map.m)
		ft_error("No access to a xpm file main");
}
