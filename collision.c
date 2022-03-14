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
<<<<<<< HEAD
	if (pos_y > 12 || (((u_int64_t)(map[pos_y]) & tetri.id_int64) != 0))
	{
		return (1);
	}
=======
//  if (pos_y > 12 || ft_line_collision(map[pos_y], tetri.id_int0) || ft_line_collision(map[(pos_y + 1)], tetri.id_int1) || ft_line_collision(map[pos_y + 2], tetri.id_int2) || ft_line_collision(map[pos_y + 3], tetri.id_int3))
  u_int64_t	res;
  u_int64_t	temp_piece;
  u_int64_t	temp_piece0;
  u_int64_t	temp_piece1;
  u_int64_t	temp_piece2;
  u_int64_t	temp_piece3;

  res = 0;
  temp_piece0 = (tetri.id_int64 >> 48);
  temp_piece1 = ((tetri.id_int64 >> 16) & 4294901760UL);
  temp_piece2 = ((tetri.id_int64 << 16) & 281470681743360UL);
  temp_piece3 = ((tetri.id_int64 << 48) & 18446462598732840960UL);
  /*  printf("IN tetri coll y, temp_piece0-3 are:\n");
  ft_print64(temp_piece0);
  ft_print64(temp_piece1);
  ft_print64(temp_piece2);
  ft_print64(temp_piece3);*/
  //  ft_print64(temp_piece);
  temp_piece = (temp_piece0 | temp_piece1 | temp_piece2 | temp_piece3);
  res = ((*(u_int64_t *)(map + pos_y)) & (temp_piece));
  //map[pos_y] = (temp >> 48);
  //map[pos_y+1] = (temp >> 32);
  //map[pos_y+2] = (temp >> 16);
  //map[pos_y+3] = (temp);

  /*  printf("IN tetri coll y, at y map is:\n");
  ft_print64(*(u_int64_t *)(map + pos_y));
  printf("IN tetri coll y, tetri is:\n");
  ft_print64(tetri.id_int64);
  printf("IN tetri coll y, temp_piece is:\n");
  ft_print64(temp_piece);*/

  //ft_print64(*(map + pos_y));
  if (pos_y > 12 || (res != 0))
    return (1);
>>>>>>> f694a682c0525cae4f88e538e02c2e0d7bc00ba6
  return (0);
}

u_int16_t	ft_collision_xy(u_int16_t *map, t_tetri tetri, u_int16_t pos_x, u_int16_t pos_y)
{
<<<<<<< HEAD
	if (pos_y > 12 || pos_x > 12)
		return (1);
	if (pos_x > 0)
		tetri.id_int64 = (tetri.id_int64 >> pos_x);
	if (ft_tetri_collision_y(map, tetri, pos_y) == 0)
		return (0);
	return (1);
=======
  //  printf("\nMap in collision xy, x is %d, y is %d:\n", pos_x, pos_y);
  //  ft_print_bin_map(map);
  //  printf("\ntetri 64:\n");
  //  ft_print64(tetri.id_int64);
  if (pos_y > 12 || pos_x > 12)
    return (1);
  if (pos_x > 0)
    {
      tetri.id_int64 = (tetri.id_int64 >> pos_x);
      /*		tetri.id_int0 = (tetri.id_int0 >> pos_x);
			tetri.id_int1 = (tetri.id_int1 >> pos_x);
			tetri.id_int2 = (tetri.id_int2 >> pos_x);
			tetri.id_int3 = (tetri.id_int3 >> pos_x);
      */
    }
  //  printf("\ntetri 64 after moving to pos_x %d:\n", pos_x);
  //  ft_print64(tetri.id_int64);
  if (ft_tetri_collision_y(map, tetri, pos_y) == 0)
    return (0);
  return (1);
>>>>>>> f694a682c0525cae4f88e538e02c2e0d7bc00ba6
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
