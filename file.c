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
	char	*read;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_error("Error\nProblems reading the file\n");
	line = get_next_line(fd);
	if (!line)
		ft_error("Error\nProblems reading fd\n");
	data->map.x =((data->map.y = 0), ft_strlen(line) - 1);
	read = ft_strdup("");
	while (line)
	{
		read = ft_strjoin(read, line);
		free(line);
		line = get_next_line(fd);
		data->map.y++;
		if (data->map.x > 81 || data->map.y > 43)
			ft_error("Error\n Map too big\n");
	}
	free(line);
	data->map.chart = ft_split(read, '\n');
	free(read);
	close(fd);
}
