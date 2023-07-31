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

void	ft_put_img(t_game *data)
{
	ft_xpm_img(data);
	if ( == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->map.wall, &size, &size);
	else if ( == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->map.floor, &size, &size);
	else if ( == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->map.coin, &size, &size);
	else if ( == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->map.exit, &size, &size);
	else if ( == 'P')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->map.main, &size, &size);
}

void	ft_xpm_img(t_game *data)
{
	data->map.coin = mlx_xpm_file_to_image(data->mlx, "./art/heart", &data->w, &data->h);
	if (!data->map.coin)
		ft_error("No access to a xpm file");
	data->map.exit = mlx_xpm_file_to_image(data->mlx, "./art/brain", &data->w, &data->h);
	if (!data->map.exit)
		ft_error("No access to a xpm file");
	data->map.wall = mlx_xpm_file_to_image(data->mlx, "./art/skull", &data->w, &data->h);
	if (!data->map.wall)
		ft_error("No access to a xpm file");
	data->map.floor = mlx_xpm_file_to_image(data->mlx, "./art/", &data->w, &data->h);
	if (!data->map.floor)
		ft_error("No access to a xpm file");
	data->map.main = mlx_xpm_file_to_image(data->mlx, "./art/brain", &data->w, &data->h);
	if (!data->map.main)
		ft_error("No access to a xpm file");
}
