/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:34:26 by acastano          #+#    #+#             */
/*   Updated: 2022/03/22 13:31:22 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 * get_mapsize() takes the number of tetris
 * it calculates the minimum map size necessary
 */
u_int16_t	get_mapsize(int n_tetris)
{
	u_int16_t	size;

	size = 2;
	while ((size * size) < (n_tetris * 4))
		size++;
	return (size);
}

/*
* init_map() takes the map array and the calculated map size
* It initializes the map according to the map size
*/
void	init_map(u_int16_t *map, int map_size)
{
	u_int16_t	y;

	y = 0;
	if (map_size > 13)
		error(7);
	while (y < 13)
	{
		map[y] = 0xFFFF;
		if (y < map_size)
			map[y] = (0xFFFF >> map_size);
		y++;
	}
}

/*
 * update_map() takes the map, current position (x, y), and id int of each tetri
 * updates the map once a tetri has been placed
 */
void	update_map(u_int16_t *map, int x, int y, u_int64_t id_int64)
{
	u_int64_t	temp;

	temp = ((reorg_piece(*(u_int64_t *)(map + y))) | (id_int64 >> x));
	map[y] = (temp >> 48);
	map[y + 1] = (temp >> 32);
	map[y + 2] = (temp >> 16);
	map[y + 3] = (temp);
}

/*
 * revert_map() takes an uint representing the map, the position (x, y) of the 
 * piece we want to delete from the map, and the array of tetris.
 * To compare the map with the tetris, the map needs to be casted to an uint64,
 * and rearranged in blocks of 16 bits so they are in the same order.
 */
void	revert_map(u_int16_t *map, int x, int y, t_tetri *tetris)
{
	u_int64_t	temp;

	temp = ((reorg_piece(*(u_int64_t *)(map + y)))
			^ (tetris[0].id_int64 >> x));
	map[y] = (temp >> 48);
	map[y + 1] = (temp >> 32);
	map[y + 2] = (temp >> 16);
	map[y + 3] = (temp);
	tetris->pos_x = 0;
	tetris->pos_y = 0;
}
