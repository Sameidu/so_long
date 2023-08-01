/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:07:37 by smeixoei          #+#    #+#             */
/*   Updated: 2023/08/01 12:34:54 by smeixoei         ###   ########.fr       */
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
	int 	fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_error("ERROR\nProblems reading the file");
	line = get_next_line(fd);
	if (!line)
		ft_error("Problems reading fd");
	data->map.y = 0;
	data->map.x = ft_strlen(line) - 1;
	free(line);
	while (line)
	{
		line = get_next_line(fd);
		data->map.y++;
	}
	close(fd);
}
