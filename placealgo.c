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
<<<<<<< HEAD
=======
#include <stdio.h>//printf TO DO: erase

u_int64_t	ft_reorg_piece(u_int64_t piece)
{
  u_int64_t	temp_piece0;
  u_int64_t	temp_piece1;
  u_int64_t	temp_piece2;
  u_int64_t	temp_piece3;

  temp_piece0 = (piece >> 48);
  temp_piece1 = ((piece >> 16) & 4294901760UL);
  temp_piece2 = ((piece << 16) & 281470681743360UL);
  temp_piece3 = ((piece << 48) & 18446462598732840960UL);
  piece = (temp_piece0 | temp_piece1 | temp_piece2 | temp_piece3);
  return (piece);
}
>>>>>>> f694a682c0525cae4f88e538e02c2e0d7bc00ba6

void	ft_update_tetri_xy(t_tetri *tetri, u_int16_t pos_x, u_int16_t pos_y)
{
  tetri->pos_x = pos_x;
  tetri->pos_y = pos_y;
}

void	ft_update_map(u_int16_t *map, u_int16_t pos_x, u_int16_t pos_y, u_int64_t id_int64)
{
  u_int64_t	reorg_map;
  u_int64_t	temp;

  temp = 0;
  reorg_map = ft_reorg_piece(*(u_int64_t *)(map + pos_y));
  temp = (reorg_map | (id_int64 >> pos_x));
  
  map[pos_y] = (temp >> 48);
  map[pos_y+1] = (temp >> 32);
  map[pos_y+2] = (temp >> 16);
  map[pos_y+3] = (temp);
}

void	ft_revert_map(u_int16_t *map, u_int16_t pos_x, u_int16_t pos_y, u_int64_t id_int64)
{
  u_int64_t	reorg_map;
  u_int64_t	temp;
  temp = 0;
  reorg_map = ft_reorg_piece(*(u_int64_t *)(map + pos_y));
  temp = (reorg_map ^ (id_int64 >> pos_x));
  
  map[pos_y] = (temp >> 48);
  map[pos_y+1] = (temp >> 32);
  map[pos_y+2] = (temp >> 16);
  map[pos_y+3] = (temp);
}

u_int16_t	ft_place_tetri(u_int16_t *map, t_tetri *tetri, u_int16_t pos_x, u_int16_t pos_y)
{
	if (ft_collision_xy(map, *tetri, pos_x, pos_y) == 0)
	{
<<<<<<< HEAD
		ft_update_tetri_xy(tetri, pos_x, pos_y);
		(map[pos_y]) = (((u_int64_t)(map[pos_y])) | (tetri->id_int64 >> pos_x));
		return (1);
=======
	  ft_update_tetri_xy(tetri, pos_x, pos_y);
	  ft_update_map(map, pos_x, pos_y, tetri->id_int64);
	  return (1);
>>>>>>> f694a682c0525cae4f88e538e02c2e0d7bc00ba6
	}
	return (0);//if it didnt work
}

<<<<<<< HEAD
=======
void	ft_print64(u_int64_t id)//for testing
{
	u_int64_t x;

	x = 0;
	while (x < 64)
	{
		if (id & (9223372036854775808UL >> x))
			ft_putchar('1');
		else
			ft_putchar('0');
		x++;
	}
	ft_putchar('\n');
}

>>>>>>> f694a682c0525cae4f88e538e02c2e0d7bc00ba6
u_int16_t	ft_placealgo(u_int16_t *map, t_tetri *tetris, u_int16_t n_tetris, u_int16_t map_size)
{
  u_int16_t	x;
  u_int16_t	y;

  x = 0;
  y = 0;
  while (y < map_size)//13
    {
      while (x < map_size)//13
	{
	  if (ft_place_tetri(map, &(tetris[0]), x, y) == 1)
	    {
	      if (n_tetris > 1)
		{
<<<<<<< HEAD
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
=======
		  if (ft_placealgo(map, &(tetris[1]), (n_tetris - 1), map_size) == 1)
		    return (1);
		  else
		    {
		      ft_update_tetri_xy(&tetris[0], 0, 0);
		      ft_revert_map(map, x, y, (tetris[0].id_int64));
		    }
>>>>>>> f694a682c0525cae4f88e538e02c2e0d7bc00ba6
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
