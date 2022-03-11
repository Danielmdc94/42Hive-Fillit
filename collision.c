/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:07:23 by acastano          #+#    #+#             */
/*   Updated: 2022/03/11 19:07:45 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

u_int16_t	ft_tetri_collision_y(u_int16_t *map, t_tetri tetri, u_int16_t pos_y)
{
	if (pos_y > 12 || (((u_int64_t)(map[pos_y]) & tetri.id_int64) != 0))
	{
		return (1);
	}
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
