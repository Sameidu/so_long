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

void	ft_check_map(t_game *data)
{
	// Comprobar si el mapa está cerrado por paredes (1)
	// Recorrer primera y última fila así como primer y último caracter de las columnas para comprobar que son todos 1
	// ft_check_walls(data);
	// Comprobar que haya sólo una salida (E)
	// Comprobar que haya sólo un personaje (P)
	// Comprobar que haya al menos un coleccionable (C)
	// ft_check_exit_and_character(data); (Posiblemente se pueda hacer dentro de esta función por ser poca comprobación)
	if (data->map.exit != 1 || data->map.main != 1 || data->map.coin < 1)
		ft_error("ERROR\n INVALID MAP");
	// Comprobar que el personaje se pueda mover por el mapa (0) (Con flood fill crearemos esto en "utils.c")
	// Comprpobar que la salida sea accesible para el personaje	(Con flood fill crearemos esto en "utils.c")
	// ft_check_move(data); (Con flood fill crearemos esto en "utils.c")
	// Comprobar que el colleccionable sea accesible para el personaje
	// ft_check_coin(data); (Con flood fill crearemos esto en "utils.c"
	// Posiblemente todas las comprobaciones se puedan realizar en el archivo de utils
}

// Tengo que tener en cuenta que el personaje tampoco puede atravesar la salida y se contabiliza como pared hasta que recoja todos los coleccionables. acordarme de sólo convertir los 0 en P para ello.