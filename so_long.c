/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:14:48 by smeixoei          #+#    #+#             */
/*   Updated: 2023/07/28 12:02:47 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void	ft_initialize(t_game *data, char *map)
{
	ft_check_file(data, map);
	//ft_check_map(data);
	data->mlx_win = mlx_new_window(data->mlx, data->w, data->h, "so_long");
	ft_put_img(data);
	//Cargar imágenes en ventana
}

int	main(int argc, char **argv)
{
	t_game	data;

	if (argc != 2 || !ft_ext(argv[1]))
	{
		ft_putstr_fd("ERROR\nInvalid arguments\n", 1);
		return (0);
	}
	data.mlx = mlx_init();
	ft_initialize(&data, argv[1]); //Para cargar e inicilializar el mapa con las imágenes haciedno las comprobaciones necesarias
	mlx_key_hook(data.mlx_win, ft_read_key(), &data);
	mlx_loop(data.mlx);
	return (0);
}
