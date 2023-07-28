/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:07:37 by smeixoei          #+#    #+#             */
/*   Updated: 2023/07/28 12:02:52 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int	ft_ext(char *map)
{
	if (!map || ft_strnstr(map + (ft_strlen(map) - 4), ".ber", 4))
		return (0);
	return (1);
}

void	ft_check_file(t_game *data, char *map)
{
	int fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		ft_error("ERROR\nProblems reading the file");
	}
	data->map.chart = get_next_line(fd);
	close(fd);
}
