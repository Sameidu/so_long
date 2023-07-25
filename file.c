#include "so_long.h"

void	ft_ext(struct s_data *data, char *map)
{
	int	i;
	i = ft_strlen(map);
	if (map[i - 4] != '.' || map[i - 3] != 'b' ||
		map[i - 2] != 'e' || map[i - 1] != 'r')
	{
		ft_putstr("ERROR\nProblemas con la extensión del archivo");
		ft_free(data);
	}
}

void	ft_check_file(struct s_data *data, char *map)
{
	int	fd;

	ft_ext(data, map);
	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("ERROR\nProblemas al leer el archivo");
		ft_free(data);
	}

};