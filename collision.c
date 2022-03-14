/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:07:23 by acastano          #+#    #+#             */
/*   Updated: 2022/03/14 16:55:03 by acastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_tetri_collision_y(u_int16_t *map, t_tetri tetri, int y)
{
	u_int64_t	res;

	if (y > 12 || (((u_int64_t)(map[y]) & tetri.id_int64) != 0))
		return (1);
	res = 0;
	tetri.id_int64 = ft_reorg_piece(tetri.id_int64);
	res = ((*(u_int64_t *)(map + y)) & (tetri.id_int64));
	if (y > 12 || (res != 0))
		return (1);
	return (0);
}

int	ft_collision_xy(u_int16_t *map, t_tetri tetri, int x, int y)
{
	if (y > 12 || x > 12)
		return (1);
	if (x > 0)
		tetri.id_int64 = (tetri.id_int64 >> x);
	if (ft_tetri_collision_y(map, tetri, y) == 0)
		return (0);
	return (1);
}
