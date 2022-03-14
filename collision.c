/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:07:23 by acastano          #+#    #+#             */
/*   Updated: 2022/03/14 13:16:28 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

u_int16_t	ft_tetri_collision_y(u_int16_t *map, t_tetri tetri, u_int16_t pos_y)
{
	u_int64_t	res;
	u_int64_t	temp_piece;
	u_int64_t	temp_piece0;
	u_int64_t	temp_piece1;
	u_int64_t	temp_piece2;
	u_int64_t	temp_piece3;

	if (pos_y > 12 || (((u_int64_t)(map[pos_y]) & tetri.id_int64) != 0))
	{
		return (1);
	}

	res = 0;
	temp_piece0 = (tetri.id_int64 >> 48);
	temp_piece1 = ((tetri.id_int64 >> 16) & 4294901760UL);
	temp_piece2 = ((tetri.id_int64 << 16) & 281470681743360UL);
	temp_piece3 = ((tetri.id_int64 << 48) & 18446462598732840960UL);
	temp_piece = (temp_piece0 | temp_piece1 | temp_piece2 | temp_piece3);
	res = ((*(u_int64_t *)(map + pos_y)) & (temp_piece));
	if (pos_y > 12 || (res != 0))
		return (1);
	return (0);
}

u_int16_t	ft_collision_xy(u_int16_t *map, t_tetri tetri, u_int16_t pos_x, u_int16_t pos_y)
{
	if (pos_y > 12 || pos_x > 12)
		return (1);
	if (pos_x > 0)
		tetri.id_int64 = (tetri.id_int64 >> pos_x);
	if (ft_tetri_collision_y(map, tetri, pos_y) == 0)
		return (0);
	return (1);
	if (pos_y > 12 || pos_x > 12)
		return (1);
	if (pos_x > 0)
		tetri.id_int64 = (tetri.id_int64 >> pos_x);
	if (ft_tetri_collision_y(map, tetri, pos_y) == 0)
		return (0);
	return (1);
}

/*
1000 0000 0000 0000
1000 0000 0000 0000
1100 0000 0000 0000
0000 0000 0000 0000

1000 1000 1100 0000
1000 0000 0000 0000
1000 1100 0000
1000 0000 0000 0000-1000 0000 0000 0000-1100 0000 0000 0000-0000 0000 0000 0000
               1111 0000 0000 0000-1000 0000 0000 0000-1100 0000 0000 0000-0000 0000 0000 0000

((orig & F000) << 12) | ((orig & F00) << 9) | ((orig & F0) << 6) | ((orig & F) << 3)
*/
