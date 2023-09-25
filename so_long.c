/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:14:48 by smeixoei          #+#    #+#             */
/*   Updated: 2023/09/25 13:54:11 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void	ft_initialize(t_game *data, char *map)
{
	ft_check_file(data, map);
	data->w = data->map.x * SIZE;
	data->h = data->map.y * SIZE;
	printf("%d\n", data->w);
	printf("%d\n", data->h);
	data->mlx_win = mlx_new_window(data->mlx, data->w, data->h, "so_long");
	ft_xpm_img(data);
	ft_check_map(data);
}

int	main(int argc, char **argv)
{
	t_game	data;

	if (argc != 2 || ft_ext(argv[1]))
	{
		ft_putstr_fd("ERROR\nInvalid arguments\n", 1);
		return (0);
	}
	data.mlx = mlx_init();
	ft_initialize(&data, argv[1]);
	mlx_key_hook(data.mlx_win, ft_read_key, &data);
	mlx_loop(data.mlx);
	return (0);
}
