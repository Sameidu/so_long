#include "so_long.h"

void	ft_initialize(struct s_data *data, char *map)
{
	//ft_check_file(data, map);
	//ft_check_map(data);
	data->mlx_win = mlx_new_window(data->mlx, data->w, data->h, "so_long");
}

int	main(int argc, char **argv)
{
	struct s_data	*data;

	if (argc != 2)
	{
		ft_putstr("ERROR\nIntroduce un mapa válido\n");
		return (0);
	}
	data = ft_calloc(1, sizeof(struct s_data));
	if (!data)
		return (0);
	data->mlx = mlx_init();
	ft_initialize(data, argv[1]); //Para cargar e inicilializar el mapa con las imágenes haciedno las comprobaciones necesarias
	mlx_loop(data->mlx);
	ft_free(data);
	return (0);
}