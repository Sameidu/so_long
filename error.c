#include "so_long.h"

int	ft_free(struct s_data *data)
{
	if (data)
		free(data);
	exit(0);
}

void	ft_error(struct s_data *data)
{
	ft_putstr("ERROR\nNo ha sido posible inicializar el programa.\n");
	ft_free(data);
}