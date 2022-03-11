/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:33:11 by dpalacio          #+#    #+#             */
/*   Updated: 2022/03/11 19:07:40 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

u_int16_t	ft_placealgo(u_int16_t *map, t_tetri *tetris, u_int16_t n_tetris, u_int16_t map_size)
{
	int	i;

	i = 0;
	printf("testing\n");
	//	ft_print64(tetris->id_int64);
	while (tetris->pos_y <= map_size)
	{
		tetris->pos_x = 0;
		while (tetris->pos_y <= map_size)
		{
			if ((*(uint64_t *)(map + tetris->pos_y) & (tetris->id_int64 >> tetris->pos_x)))
			{
				*(uint64_t *)(map + tetris->pos_y) |= (tetris->id_int64 >> tetris->pos_x);
				if (ft_placealgo(map, (tetris + 1), (n_tetris), map_size))
					return(1);
				*(uint64_t *)(map + tetris->pos_y) |= (tetris->id_int64 >> tetris->pos_x);
			}
			if (n_tetris == 0)
				return (1);
			tetris->pos_x++;
		}
		tetris->pos_y++;
	}
	return (0);
}
