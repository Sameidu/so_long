/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:15:44 by smeixoei          #+#    #+#             */
/*   Updated: 2023/07/25 19:15:44 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_walls(t_game *data, int x, int y)
{
	x = 0;
	y = data->map.y;
	while (x < data->map.x)
	{
		if (data->map.chart[0][x] != '1')
			ft_error("ERROR\nINVALID MAP");
		x++;
	}
	x = 0;
	while (x < data->map.x)
	{
		if (data->map.chart[y][x] != '1')
			ft_error("ERROR\nINVALID MAP");
		x++;
	}
	y = 1;
	x = data->map.x;
	while (y < data->map.y)
	{
		if (data->map.chart[y][0] != '1' || data->map.chart[y][x] != '1')
			ft_error("ERROR\nINVALID MAP");
		y++;
	}
}

void	ft_elements(t_game *data, int x, int y)
{
	int	c;
	int	p;
	int	e;

	c = 0;
	p = 0;
	e = 0;
	y = 0;
	while (y < data->map.y)
	{
		x = 0;
		while (x < data->map.x)
		{
			if (data->map.cp_chart[y][x] == 'C')
				c++;
			if (data->map.cp_chart[y][x] == 'P')
				p++;
			if (data->map.cp_chart[y][x] == 'E')
				e++;
			x++;
		}
		y++;
	}
	if (e != 1 || p != 1 || c < 1)
		ft_error("ERROR\nINVALID MAP");
}

void	ft_print_map(t_game *data, int x, int y)
{
	y = 0;
	while (y < data->map.y)
	{
		x = 0;
		while (x < data->map.x)
		{
			ft_put_img(data, data->map.chart[y][x]);
			x++;
		}
		y++;
	}
}

void	ft_check_map(t_game *data)
{
	int	x;
	int	y;
	// Comprobar si el mapa está cerrado por paredes (1)
	// Recorrer primera y última fila así como primer y último caracter de las columnas para comprobar que son todos 1
	ft_check_walls(data, x, y);
	// Comprobar que haya sólo una salida (E)
	// Comprobar que haya sólo un personaje (P)
	// Comprobar que haya al menos un coleccionable (C)
	// ft_check_exit_and_character(data); (Posiblemente se pueda hacer dentro de esta función por ser poca comprobación)
	ft_elements(data, x, y);
	// Comprobar que el personaje se pueda mover por el mapa (0) (Con flood fill crearemos esto en "utils.c")
	// Comprpobar que la salida sea accesible para el personaje	(Con flood fill crearemos esto en "utils.c")
	ft_check_move(data, x, y);
	// Comprobar que el colleccionable sea accesible para el personaje
	// ft_check_coin(data); (Con flood fill crearemos esto en "utils.c"
	// Posiblemente todas las comprobaciones se puedan realizar en el archivo de utils
	ft_print_map(data, x, y);
}

// Tengo que tener en cuenta que el personaje tampoco puede atravesar la salida y se contabiliza como pared hasta que recoja todos los coleccionables. acordarme de sólo convertir los 0 y C en P para ello.