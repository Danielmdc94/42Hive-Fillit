/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placealgo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:48:12 by acastano          #+#    #+#             */
/*   Updated: 2022/03/11 19:07:43 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_update_tetri_xy(t_tetri *tetri, u_int16_t pos_x, u_int16_t pos_y)
{
  tetri->pos_x = pos_x;
  tetri->pos_y = pos_y;
}

u_int16_t	ft_place_tetri(u_int16_t *map, t_tetri *tetri, u_int16_t pos_x, u_int16_t pos_y)
{
	if (ft_collision_xy(map, *tetri, pos_x, pos_y) == 0)
	{
		ft_update_tetri_xy(tetri, pos_x, pos_y);
		(map[pos_y]) = (((u_int64_t)(map[pos_y])) | (tetri->id_int64 >> pos_x));
		return (1);
	}
	return (0);//if it didnt work
}

u_int16_t	ft_placealgo(u_int16_t *map, t_tetri *tetris, u_int16_t n_tetris, u_int16_t map_size)
{
	u_int16_t	i;
	u_int16_t	x;
	u_int16_t	y;

	x = 0;
	y = 0;
	i = 0;
	ft_print64(tetris[0].id_int64);
	while (y < map_size)//13
    {
		while (x < map_size)//13
		{
			if (ft_place_tetri(map, &(tetris[0]), x, y) == 1)
			{
				i++;
				if (i < n_tetris)
				{
					if (ft_placealgo(map, &(tetris[1]), (n_tetris - 1), map_size) == 1)
						return (1);
					i--;
					ft_update_tetri_xy(&tetris[i], 0, 0);
					(map[y]) = (((u_int64_t)(map[y])) ^ tetris[i].id_int64 >> x);
				}
				else
					return (1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);//if it didnt work
}
