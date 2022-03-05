/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:54:30 by acastano          #+#    #+#             */
/*   Updated: 2022/03/04 11:13:40 by acastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <stdlib.h>//libft strnew and memalloc
#include <string.h>//memset

u_int16_t	ft_map_size(u_int16_t tetriminos)
{
	u_int16_t	bits;
	u_int16_t	size;

	bits = tetriminos * 4;
	size = 4;
	while ((size * size) < bits)
		size++;
	return (size);
}

u_int16_t	ft_init_map(u_int16_t *map, u_int16_t i)
{
	u_int16_t	x;

	x = 0;
	if (i > 13)
		return (1);
	while (x < i)
	{
		map[x] = (65535 >> i);//FFFF
		x++;
	}
	i = i - 1;
	while (x < 13)
	{
		map[x] = 65535;
		x++;
	}
	return (0);
}

void ft_print_bin_map_line(u_int16_t map_line, u_int16_t bit_size)
{
  int16_t i;
  
  i = bit_size - 1;
  while (i >= 0)
  {
      if (map_line & (1UL << i))
		  printf("1");
      else
		  printf("0");
      if ((bit_size == 16) && (i % 16 == 0))
		  printf("\n");
      i--;
  }
}

void ft_print_bin_map(u_int16_t *map)
{
  int16_t x;
  
  x = 0;

  while (x < 13)
  {
	  ft_print_bin_map_line(map[x], 16);
	  x++;
  }
}

/*
char	*maptoletters(char *char_map, t_tetri tetri)
{
  uint16_t	i = 0;
  //what if no map string yet, does it come for sure,
  //or do we make it here?  if (*letter_map == NULL)
//AAAA .... .... ....
//B... B... BB.. ....
  char	*tetri_pos;

  tetri_pos = ft_itoa_base(tetri.id_uint16_t, 2);
  while (tetri_pos[i])
  {
      if (tetri_pos[i] == '1')
		  (char_map)[i] = tetri.id_char;
      i++;
  }
  free(tetri_pos);
  return (char_map);
}
*/
