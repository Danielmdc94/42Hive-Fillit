/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:07:23 by acastano          #+#    #+#             */
/*   Updated: 2022/03/07 19:08:25 by acastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
//#include <stdio.h>
//#include <stdlib.h>//libft strnew and memalloc
//#include <string.h>//memset

u_int16_t	ft_line_collision(u_int16_t map_line, u_int16_t tetri_line)
{
  if (map_line & tetri_line)
    return (1);
  return (0);//no collision
}

u_int16_t	ft_tetri_collision_y(u_int16_t *map, t_tetri tetri, u_int16_t pos_y)
{
  if (pos_y > 12 || ft_line_collision(map[pos_y], tetri.id_int0) || ft_line_collision(map[(pos_y + 1)], tetri.id_int1) || ft_line_collision(map[pos_y + 2], tetri.id_int2) || ft_line_collision(map[pos_y + 3], tetri.id_int3))
    return (1);
  return (0);
}

u_int16_t	ft_collision_xy(u_int16_t *map, t_tetri tetri, u_int16_t pos_x, u_int16_t pos_y)
{
	if (pos_y > 12 || pos_x > 12)
		return (1);
	if (pos_x > 0)
    {
		tetri.id_int0 = (tetri.id_int0 >> pos_x);
		tetri.id_int1 = (tetri.id_int1 >> pos_x);
		tetri.id_int2 = (tetri.id_int2 >> pos_x);
		tetri.id_int3 = (tetri.id_int3 >> pos_x);
    }
	if (ft_tetri_collision_y(map, tetri, pos_y) == 0)
		return (0);
	return (1);
}
