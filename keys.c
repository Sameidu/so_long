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
		
	else if (data->key == 1)
		
	else if (data->key == 0)

	else if (data->key == 2)

	return (0);		
}