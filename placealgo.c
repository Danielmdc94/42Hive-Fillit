/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placealgo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:48:27 by acastano          #+#    #+#             */
/*   Updated: 2022/03/15 12:22:34 by dpalacio         ###   ########.fr       */
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

void	ft_update_tetri_xy(t_tetri *tetri, int x, int y)
{
	tetri->pos_x = x;
	tetri->pos_y = y;
}

int	ft_place_tetri(u_int16_t *map, t_tetri *tetri, int x, int y)
{
	if (ft_collision_xy(map, *tetri, x, y) == 0)
	{
		ft_update_tetri_xy(tetri, x, y);
		ft_update_map(map, x, y, tetri->id_int64);
		return (1);
	}
	return (0);
}

int	ft_placealgo(u_int16_t *map, t_tetri *tetris, t_filldata data)
{
	if (ft_place_tetri(map, &(tetris[0]), data.x, data.y) == 1)
	{
		if (data.n_tetris > 1)
		{
			data.n_tetris--;
			if (fillit(map, &(tetris[1]), data) == 1)
				return (1);
			else
			{
				data.n_tetris++;
				ft_update_tetri_xy(&tetris[0], 0, 0);
				ft_revert_map(map, data.x, data.y, (tetris[0].id_int64));
			}
		}
		else
			return (1);
	}
	return (0);
}

int	fillit(u_int16_t *map, t_tetri *tetris, t_filldata data)
{
	data.x = 0;
	data.y = 0;
	while (data.y < data.map_size)
	{
		while (data.x < data.map_size)
		{
			if (ft_placealgo(map, tetris, data) == 1)
				return (1);
			data.x++;
		}
		data.x = 0;
		data.y++;
	}
	return (0);
}
