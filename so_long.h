#ifndef SOLONG
# define SOLONG

#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "mlx.h"

struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
	int		w;
	int		h;
	int		pos_c;
	int		pos_p;
	int		post_e;
	int		pos_1;
	int		pos_0;
	char	*map;	
};


#endif