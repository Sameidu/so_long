#include "so_long.h"

int	main(int argc, char **argv)
{
	struct s_data	*data;

	if (argc != 2)
	{
		return (write(1, "ERROR\nIntroduce un mapa válido\n", 34));
		return (0);
	}
	data = ft_calloc(1, sizeof(struct s_data));
	if (!data)
		return (0);
}