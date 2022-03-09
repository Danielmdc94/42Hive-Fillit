/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placealgo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:48:12 by acastano          #+#    #+#             */
/*   Updated: 2022/03/09 17:55:50 by acastano         ###   ########.fr       */
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

//Do not try to understand. Under construction. No sense yet
u_int16_t	ft_place_tetri(u_int16_t *map, t_tetri *tetri, u_int16_t pos_x, u_int16_t pos_y)
{
	u_int16_t	x;
	u_int16_t	y;

	x = pos_x;//or the pieces saved pos
	y = pos_y;//same
/*	printf("\ninside place TETRI, before collision check\n");
	ft_print_bin_map(map);
	printf("\n");
*/	if (ft_collision_xy(map, *tetri, x, y) == 0)
	{
		ft_update_tetri_xy(tetri, x, y);
		map[y] = (map[y] | (tetri->id_int0 >> x));
		map[y+1] = (map[y+1] | (tetri->id_int1 >> x));
		map[y+2] = (map[y+2] | (tetri->id_int2 >> x));
		map[y+3] = (map[y+3] | (tetri->id_int3 >> x));
		return (1);
	}
/*	printf("\ninside place TETRI, after collision check\n");
	ft_print_bin_map(map);
	printf("\n");
*/
	return (0);//didnt work
}

//Do not try to understand. Under construction. No sense yet
u_int16_t	ft_placealgo(u_int16_t *map, t_tetri *tetris, u_int16_t n_tetris, u_int16_t map_size)
{
	u_int16_t	i;
	u_int16_t	x;
	u_int16_t	y;

	x = 0;//or the pieces saved pos
	y = 0;//same
	i = 0;
/*	printf("\ninside place algo\n");
	ft_print_bin_map(map);
	printf("\ntetris[0] is\n");
	ft_print_tetri_16(tetris[0]);
*/	while (y < map_size)//13
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
					else
					{
						i--;
						ft_update_tetri_xy(&tetris[i], 0, 0);
						map[y] = (map[y] ^ (tetris[i].id_int0 >> x));
						map[y+1] = (map[y+1] ^ (tetris[i].id_int1 >> x));
						map[y+2] = (map[y+2] ^ (tetris[i].id_int2 >> x));
						map[y+3] = (map[y+3] ^ (tetris[i].id_int3 >> x));
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
	return (0);//didnt work
}

//grow map size
