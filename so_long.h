#ifndef SOLONG
# define SOLONG

#include <unistd.h>
#include <math.h>
#include "mlx.h"

struct so_long
{
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
	int		w;
	int		y;
};




#endif