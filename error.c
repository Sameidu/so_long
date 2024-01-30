/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarameixoeiro <sarameixoeiro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:15:25 by smeixoei          #+#    #+#             */
/*   Updated: 2024/01/30 10:10:38 by sarameixoei      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit (0);
}

int	ft_kill_game(t_game *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit (0);
}
