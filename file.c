/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:07:37 by smeixoei          #+#    #+#             */
/*   Updated: 2023/07/26 15:55:14 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void ft_ext(struct s_data *data, char *map)
{
	int i;
	i = ft_strlen(map);
	if (!map || ft_strnstr(map + (ft_strlen(map) - 4), ".ber", 4))
	{
		ft_putstr_fd("ERROR\nProblemas con la extensión del archivo", 1);
		ft_free(data);
	}
}

void ft_check_file(struct s_data *data, char *map)
{
	int fd;

	ft_ext(data, map);
	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("ERROR\nProblemas al leer el archivo");
		ft_free(data);
	}
	data->map = get_nextr_line(fd);
	close(fd);
}
