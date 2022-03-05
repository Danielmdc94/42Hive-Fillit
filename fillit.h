/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:54:47 by dpalacio          #+#    #+#             */
/*   Updated: 2022/01/26 15:55:59 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

//# include "libft/libft.h"

//open()
# include <fcntl.h>

void	error_manager(int error_code);
int		convert_file(char *file);

#include <stdio.h>
#include <stdlib.h>//libft strnew and memalloc
#include <string.h>//memset

typedef struct	s_tetri{
  char			id_char;
  char			*string;//string orig to top left
  u_int16_t		id_int;//int orig top left
  u_int16_t		id_int0;
  u_int16_t		id_int1;
  u_int16_t		id_int2;
  u_int16_t		id_int3;
  u_int16_t		pos_x;
  u_int16_t		pos_y;
}				t_tetri;

//struct
void	ft_update_tetri(t_tetri *tetri, u_int16_t new_id);
void	ft_print_tetri(t_tetri tetri, u_int16_t bit_size);
void	ft_print_tetri_16(t_tetri tetri);

//collision.c
u_int16_t	ft_line_collision(u_int16_t map_line, u_int16_t tetri_line);
u_int16_t	ft_tetri_collision_y(u_int16_t *map, t_tetri tetri, u_int16_t pos_y);
u_int16_t	ft_shift_line(u_int16_t *tetri_line, u_int16_t x);
u_int16_t	ft_shift_piece_x(u_int16_t *tetri, u_int16_t x);
u_int16_t	ft_collision_xy(u_int16_t *map, t_tetri tetri, u_int16_t pos_x, u_int16_t pos_y);

//map.c
u_int16_t	ft_map_size(u_int16_t tetriminos);
u_int16_t	ft_init_map(u_int16_t *map, u_int16_t i);
void ft_print_bin_map_line(u_int16_t map_line, u_int16_t bit_size);
void ft_print_bin_map(u_int16_t *map);

#endif
