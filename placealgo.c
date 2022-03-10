/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placealgo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:48:12 by acastano          #+#    #+#             */
/*   Updated: 2022/03/10 16:50:36 by acastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>//printf TO DO: erase

//void	ft_update_map

void	ft_update_tetri_xy(t_tetri *tetri, u_int16_t pos_x, u_int16_t pos_y)
{
  //  tetri.id_char = 'E';
  //  tetri.string = "1000100010001000";
  //tetri->id_int = new_id;
  //tetri->id_int0 = ((tetri->id_int0) >> x& 61440);//F000
  //  tetri->id_int1 = (new_id & 3840) << 4;//F00
  //tetri->id_int2 = (new_id & 240) << 8;//F0
  //tetri->id_int3 = (new_id & 15) << 12;//F
  tetri->pos_x = pos_x;
  tetri->pos_y = pos_y;
}

u_int16_t	ft_place_tetri(u_int16_t *map, t_tetri *tetri, u_int16_t pos_x, u_int16_t pos_y)
{
	if (ft_collision_xy(map, *tetri, pos_x, pos_y) == 0)
	{
		ft_update_tetri_xy(tetri, pos_x, pos_y);
		(map[pos_y]) = (((u_int64_t)(map[pos_y])) | (tetri->id_int64 >> pos_x));
/*		map[pos_y] = (map[pos_y] | (tetri->id_int0 >> pos_x));
		map[pos_y+1] = (map[pos_y+1] | (tetri->id_int1 >> pos_x));
		map[pos_y+2] = (map[pos_y+2] | (tetri->id_int2 >> pos_x));
		map[pos_y+3] = (map[pos_y+3] | (tetri->id_int3 >> pos_x));
*/
		printf("\ncolocamos?\n");
		return (1);
	}
	printf("\nNo colocamos?\n");
	return (0);//if it didnt work
}

void	ft_print64(u_int64_t id)
{
	u_int64_t x;

	x = 0;
	while (x < 64)
	{
		if (id & (9223372036854775808UL >> x))
			printf("1");
		else
			printf("0");
		x++;
	}
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
				printf("\nllegamos?\n");
				i++;
				if (i < n_tetris)
				{
					if (ft_placealgo(map, &(tetris[1]), (n_tetris - 1), map_size) == 1)
					{
						printf("\nvolvemos?\n");
						return (1);
					}
					else
					{
						printf("\nentramos?\n");
						i--;
						ft_update_tetri_xy(&tetris[i], 0, 0);
						(map[y]) = (((u_int64_t)(map[y])) ^ tetris[i].id_int64 >> x);
/*						map[y] = (map[y] ^ (tetris[i].id_int0 >> x));
						map[y+1] = (map[y+1] ^ (tetris[i].id_int1 >> x));
						map[y+2] = (map[y+2] ^ (tetris[i].id_int2 >> x));
						map[y+3] = (map[y+3] ^ (tetris[i].id_int3 >> x));
*/
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
	return (0);//if it didnt work
}

//grow map size
