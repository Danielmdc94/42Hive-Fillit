/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placealgo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:48:27 by acastano          #+#    #+#             */
/*   Updated: 2022/03/15 15:09:48 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

u_int64_t	ft_reorg_piece(u_int64_t id_int64)
{
	u_int64_t	temp_piece;

	temp_piece = (id_int64 >> 48);
	temp_piece = (temp_piece | ((id_int64 >> 16) & 0xFFFF0000));
	temp_piece = (temp_piece | ((id_int64 << 16) & 0xFFFF00000000));
	temp_piece = (temp_piece | ((id_int64 << 48) & 0xFFFF000000000000));
	return (temp_piece);
}

int	ft_place_tetri(u_int16_t *map, t_tetri *tetri, int x, int y)
{
	if (ft_collision_xy(map, *tetri, x, y) == 0)
	{
		tetri->pos_x = x;
		tetri->pos_y = y;
		ft_update_map(map, x, y, tetri->id_int64);
		return (1);
	}
	return (0);
}

int	fillit(u_int16_t *map, t_tetri *tetris, int n_tetris, int map_size)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map_size)
	{
		while (x < map_size)
		{
			if (ft_place_tetri(map, &(tetris[0]), x, y) == 1)
			{
				if ((n_tetris > 1) && fillit(map, &(tetris[1]),
						(n_tetris - 1), map_size) == 1)
					return (1);
				else if (n_tetris > 1)
					ft_revert_map(map, x, y, tetris);
				else
					return (1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
