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

void	ft_put_img(t_game *data, char value)
{
	int	size;

	size = SIZE;
	printf("%d\n", value);
	// if (value == '0')
	// 	mlx_put_image_to_window(data->mlx, data->mlx_win, data->map.floor, size, size);
	if (value == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->map.wall, 0, 0);
	else if (value == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->map.coin, 32, 0);
	else if (value == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->map.exit, 0, 32);
	else if (value == 'P')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->map.main, 32, 32);
}

void	ft_xpm_img(t_game *data)
{
	data->map.coin = mlx_xpm_file_to_image(data->mlx, "./art/heart.xpm", &data->w, &data->h);
	if (!data->map.coin)
		ft_error("No access to a xpm file 1");
	data->map.exit = mlx_xpm_file_to_image(data->mlx, "./art/brain.xpm", &data->w, &data->h);
	if (!data->map.exit)
		ft_error("No access to a xpm file 2");
	data->map.wall = mlx_xpm_file_to_image(data->mlx, "./art/skull.xpm", &data->w, &data->h);
	if (!data->map.wall)
		ft_error("No access to a xpm file 3");
	// data->map.floor = mlx_xpm_file_to_image(data->mlx, "./art/", &data->w, &data->h);
	// if (!data->map.floor)
	// 	ft_error("No access to a xpm file 3");
	data->map.main = mlx_xpm_file_to_image(data->mlx, "./art/brain.xpm", &data->w, &data->h);
	if (!data->map.main)
		ft_error("No access to a xpm file 4");
}
