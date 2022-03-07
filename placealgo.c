/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placealgo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:48:12 by acastano          #+#    #+#             */
/*   Updated: 2022/03/07 20:38:10 by acastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//Do not try to understand. Under construction. No sense yet
u_int16_t	ft_place_tetri(u_int16_t *map, t_tetri *tetri)
{
	u_int16_t	x;
	u_int16_t	y;

	x = 0;
	y = 0;
	while (y < 13)
	{
		while (x < 13)
		{
			if (ft_collision_xy(map, tetri, x, y) == 0)
			{
				//update info in map and piece;
			}
			x++;
		}
		y++;
	}
}

//Do not try to understand. Under construction. No sense yet
u_int16_t	ft_placealgo(u_int16_t *map, t_tetri *tetris, u_int16_t n_tetris)
{
	u_int16_t	i;
	u_int16_t	x;
	u_int16_t	y;

	i = 0;
	x = 0;
	y = 0;
	while (x < n_tetris)
	{
		if (ft_place_tetri(map, &(tetris[x])) == 1)
			return (1);
		x++;
	}
	return (0);//didnt work
}
