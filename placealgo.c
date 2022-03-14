/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placealgo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:48:12 by acastano          #+#    #+#             */
/*   Updated: 2022/03/14 15:14:14 by acastano         ###   ########.fr       */
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

void	ft_update_tetri_xy(t_tetri *tetri, u_int16_t x, u_int16_t y)
{
	tetri->pos_x = x;
	tetri->pos_y = y;
}

void	ft_update_map(u_int16_t *map, u_int16_t x, u_int16_t y, u_int64_t id_int64)
{
	u_int64_t	reorg_map;
	u_int64_t	temp;

	temp = 0;
	reorg_map = ft_reorg_piece(*(u_int64_t *)(map + y));
	temp = (reorg_map | (id_int64 >> x));
	map[y] = (temp >> 48);
	map[y+1] = (temp >> 32);
	map[y+2] = (temp >> 16);
	map[y+3] = (temp);
}

void	ft_revert_map(u_int16_t *map, u_int16_t x, u_int16_t y, u_int64_t id_int64)
{
	u_int64_t	reorg_map;
	u_int64_t	temp;
	temp = 0;
	reorg_map = ft_reorg_piece(*(u_int64_t *)(map + y));
	temp = (reorg_map ^ (id_int64 >> x));

	map[y] = (temp >> 48);
	map[y+1] = (temp >> 32);
	map[y+2] = (temp >> 16);
	map[y+3] = (temp);
}

int	ft_place_tetri(u_int16_t *map, t_tetri *tetri, u_int16_t x, u_int16_t y)
{
	if (ft_collision_xy(map, *tetri, x, y) == 0)
	{
		ft_update_tetri_xy(tetri, x, y);
		ft_update_map(map, x, y, tetri->id_int64);
		return (1);
	}
	return (0);
}

int	ft_placealgo(u_int16_t *map, t_tetri *tetris, u_int16_t n_tetris, u_int16_t map_size)
{
	u_int16_t	x;
	u_int16_t	y;

	x = 0;
	y = 0;
	while (y < map_size)
	{
		while (x < map_size)
		{
			if (ft_place_tetri(map, &(tetris[0]), x, y) == 1)
			{
				if (n_tetris > 1)
				{
					if (ft_placealgo(map, &(tetris[1]), (n_tetris - 1), map_size) == 1)
						return (1);
					else
					{
						ft_update_tetri_xy(&tetris[0], 0, 0);
						ft_revert_map(map, x, y, (tetris[0].id_int64));
					}
				}
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
