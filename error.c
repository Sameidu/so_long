/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:15:25 by smeixoei          #+#    #+#             */
/*   Updated: 2023/08/23 15:56:37 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit (0);
}

void	ft_kill_game(t_game *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit (0);
}
