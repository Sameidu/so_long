/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:15:38 by smeixoei          #+#    #+#             */
/*   Updated: 2023/07/25 19:15:38 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_read_key(t_game *data)
{
	if (data->key == 53)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		free (data);
		exit (0);
	}
	else if (data->key == 13)
		ft_up(data);
	else if (data->key == 1)
		ft_down(data);
	else if (data->key == 0)
		ft_left(data);
	else if (data->key == 2)
		ft_right(data);
	return (0);		
}

void	ft_up(t_game *data)
{
	// Sería hacer un data->map.y - 1 (No sé si sería necesario alamacenar el largo en un auxiliar constate)
}

void	ft_down(t_game *data)
{
	// Sería hacer un data->map.y + 1 (No sé si sería necesario alamacenar el largo en un auxiliar constate)
}

void	ft_left(t_game *data)
{
	// Sería hacer un data->map.x + 1 (No sé si sería necesario alamacenar el largo en un auxiliar constate)
}

void	ft_right(t_game *data)
{
	// Sería hacer un data->map.x - 1 (No sé si sería necesario alamacenar el largo en un auxiliar constate)
}