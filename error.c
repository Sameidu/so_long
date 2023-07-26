/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:15:25 by smeixoei          #+#    #+#             */
/*   Updated: 2023/07/26 15:42:35 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int	ft_free(struct s_data *data)
{
	if (data)
		free(data);
	exit(0);
}

void	ft_error(struct s_data *data)
{
	ft_putstr_fd("ERROR\nNo ha sido posible inicializar el programa.\n", 2);
	ft_free(data);
}