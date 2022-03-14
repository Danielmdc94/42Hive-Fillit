/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:54:47 by dpalacio          #+#    #+#             */
/*   Updated: 2022/03/11 18:03:43 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <stdio.h>//TO DO: erase

//open()
# include <fcntl.h>

typedef struct s_tetri{
	char		*string;
	char		id_char;
	u_int16_t	id_int;
	u_int64_t	id_int64;
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
u_int16_t	*map_gen(u_int16_t *map, int n_tetris);//map
void	ft_print_tetri_64(t_tetri tetri);//TO DO: erase

//build_struct
void	ft_update_tetri(t_tetri *tetri, u_int16_t new_id);

//collision.c
u_int16_t	ft_collision_xy(u_int16_t *map, t_tetri tetri, u_int16_t pos_x, u_int16_t pos_y);
u_int16_t	ft_tetri_collision_y(u_int16_t *map, t_tetri tetri, u_int16_t pos_y);

//map.c
u_int16_t	ft_map_size(u_int16_t n_tetris);
void	ft_init_map(u_int16_t *map, u_int16_t map_size);
<<<<<<< HEAD
=======
void	ft_print_bin_map_line(u_int16_t map_line, u_int16_t bit_size);
void	ft_print_bin_map(u_int16_t *map);
void	ft_print_map(u_int16_t n_tetris, t_tetri *tetris, u_int16_t map_size);
void	ft_fill_letters(char *map_char, t_tetri tetri, u_int16_t map_size);
>>>>>>> f694a682c0525cae4f88e538e02c2e0d7bc00ba6

//placealgo.c
u_int16_t	ft_placealgo(u_int16_t *map, t_tetri *tetris, u_int16_t n_tetris, u_int16_t map_size);
u_int16_t	ft_place_tetri(u_int16_t *map, t_tetri *tetri, u_int16_t pos_x, u_int16_t pos_y);
void	ft_print64(u_int64_t id);

//print_tests.c TO DO: erase all
void	ft_print_bin_map_line(u_int16_t map_line, u_int16_t bit_size);
void	ft_print_bin_map(u_int16_t *map);
void	ft_print_map(u_int16_t *map, u_int16_t n_tetris, t_tetri *tetris, u_int16_t map_size);
void	ft_print_tetri(t_tetri tetri, u_int16_t bit_size);
void	ft_print_tetri_16(t_tetri tetri);
void	ft_print64(u_int64_t id);

#endif
