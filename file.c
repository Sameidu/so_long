/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:07:37 by smeixoei          #+#    #+#             */
/*   Updated: 2024/04/15 17:19:45 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_ext(char *map)
{
	if (!map || ft_strnstr(map + (ft_strlen(map) - 4), ".ber", 4))
		return (0);
	return (1);
}

int	ft_open(char *map, int fd)
{
	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_error("Error\nProblems reading the file\n");
	return (fd);
}

char	*ft_line_map(int fd, t_game *data)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		ft_error("Error\nProblems reading fd\n");
	data->map.x = ft_strlen(line) - 1;
	data->map.y = 0;
	return (line);
}

void	ft_check_file(t_game *data, char *map)
{
	int		fd;
	char	*line;
	char	*read;

	fd = 0;
	fd = ft_open(map, fd);
	line = ft_line_map(fd, data);
	read = ft_strdup("");
	while (line)
	{
		read = ft_strjoin_gnl(read, line);
		if (!read)
			ft_error("Error\n Cannot read file\n");
		free(line);
		line = get_next_line(fd);
		data->map.y++;
		if (data->map.x > 81 || data->map.y > 43)
			ft_error("Error\n Map too big\n");
	}
	free(line);
	data->map.map = ft_split(read, '\n');
	if (!data->map.map)
		ft_error("Error\n Map cannot be created\n");
	free(read);
	close(fd);
}
