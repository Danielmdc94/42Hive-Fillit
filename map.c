/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:34:26 by acastano          #+#    #+#             */
/*   Updated: 2022/03/16 12:38:28 by acastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

u_int16_t	get_mapsize(int n_tetris)
{
	u_int16_t	size;

	size = 2;
	while ((size * size) < (n_tetris * 4))
		size++;
	return (size);
}

/*
* Calls init_map() to initialize the map according to the map size,
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

void	update_map(u_int16_t *map, int x, int y, u_int64_t id_int64)
{
	u_int64_t	temp;

	temp = ((reorg_piece(*(u_int64_t *)(map + y))) | (id_int64 >> x));
	map[y] = (temp >> 48);
	map[y + 1] = (temp >> 32);
	map[y + 2] = (temp >> 16);
	map[y + 3] = (temp);
}

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
