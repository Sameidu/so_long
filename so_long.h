#ifndef SOLONG
# define SOLONG

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
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

void	ft_check_file(struct s_data *data, char *map);
void	ft_error(struct s_data *data);
int		ft_free(struct s_data *data);
void	ft_putstr(char *s);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char *s1, char *s2);

#endif