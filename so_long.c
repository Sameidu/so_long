/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:14:48 by smeixoei          #+#    #+#             */
/*   Updated: 2023/07/26 15:55:03 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void	ft_initialize(struct s_data *data, char *map)
{
	ft_check_file(data, map);
	//ft_check_map(data);
	data->mlx_win = mlx_new_window(data->mlx, data->w, data->h, "so_long");
	//Cargar imágenes en ventana
}

int	main(int argc, char **argv)
{
	struct s_data	*data;

	if (argc != 2 || ft_ext(data, argv[1]))
	{
		ft_putstr_fd("ERROR\nIntroduce un mapa válido\n", 1);
		return (0);
	}
	data = ft_calloc(sizeof(struct s_data), 1);
	if (!data)
		return (0);
	data->mlx = mlx_init();
	ft_initialize(data, argv[1]); //Para cargar e inicilializar el mapa con las imágenes haciedno las comprobaciones necesarias
	mlx_loop(data->mlx);

	ft_free(data);
	return (0);
}