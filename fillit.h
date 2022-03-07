/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:54:47 by dpalacio          #+#    #+#             */
/*   Updated: 2022/03/07 18:19:39 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

//open()
# include <fcntl.h>

typedef struct s_tetri{
	char		id_char;
	char		*string;
	u_int16_t	id_int;
	u_int16_t	id_int0;
	u_int16_t	id_int1;
	u_int16_t	id_int2;
	u_int16_t	id_int3;
	int			pos_x;
	int			pos_y;
}				t_tetri;

//main
void		error(int error_code);//error
int			main(int argc, char **argv);//main
char		**read_file(char *file, int *n_tet);//read_file
u_int16_t	*str_to_int(char **file, int n_tet);//str_to_int
void	build_struct(int n_tet, char **file,
					 u_int16_t *piece_id, t_tetri *tetri);//build_struct
u_int16_t	*map_gen(u_int16_t *map, int n_tet);//map

//build_struct
void	ft_update_tetri(t_tetri *tetri, u_int16_t new_id);
void	ft_print_tetri(t_tetri tetri, u_int16_t bit_size);//TO DO: erase
void	ft_print_tetri_16(t_tetri tetri);//TO DO: erase

//collision.c
u_int16_t	ft_collision_xy(u_int16_t *map, t_tetri tetri, u_int16_t pos_x, u_int16_t pos_y);
u_int16_t	ft_line_collision(u_int16_t map_line, u_int16_t tetri_line);
u_int16_t	ft_tetri_collision_y(u_int16_t *map, t_tetri tetri, u_int16_t pos_y);
u_int16_t	ft_shift_line(u_int16_t *tetri_line, u_int16_t x);
u_int16_t	ft_shift_piece_x(u_int16_t *tetri, u_int16_t x);

//map.c
u_int16_t	ft_map_size(u_int16_t tetriminos);
//u_int16_t	ft_init_map(u_int16_t *map, u_int16_t i);
void ft_print_bin_map_line(u_int16_t map_line, u_int16_t bit_size);
void ft_print_bin_map(u_int16_t *map);

#endif
