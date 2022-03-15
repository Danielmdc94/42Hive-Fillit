/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:54:47 by dpalacio          #+#    #+#             */
/*   Updated: 2022/03/15 12:15:56 by dpalacio         ###   ########.fr       */
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
char		**read_file(char *file, int *n_tetri);//read_file CHECKED
u_int16_t	*str_to_int(char **file, int n_tetri);//str_to_int CHECKED
u_int16_t	*map_gen(u_int16_t *map, int n_tetris);//map
void		ft_print_tetri_64(t_tetri tetri);//TO DO: erase

//build_struct
void		build_struct(int n_tet, char **file,
				u_int16_t *piece_id, t_tetri *tetri);//build_struct
void		valid_tetri(u_int16_t tetri_id);

//collision.c
int			ft_collision_xy(u_int16_t *map, t_tetri tetri,
				int x, int y);
int			ft_tetri_collision_y(u_int16_t *map, t_tetri tetri, int y);

//map.c
u_int16_t	ft_map_size(int n_tetris);
void		ft_init_map(u_int16_t *map, int map_size);
void		ft_update_map(u_int16_t *map, int x, int y, u_int64_t id_int64);
void		ft_revert_map(u_int16_t *map, int x, int y, t_tetri *tetris);
void		ft_fill_letters(char *map_char, t_tetri tetri, int map_size);
void		print_map(int n_tetris, t_tetri *tetris, int map_size);

//placealgo.c
u_int64_t	ft_reorg_piece(u_int64_t piece);
void		ft_update_tetri_xy(t_tetri *tetri, int x, int y);
int			ft_place_tetri(u_int16_t *map, t_tetri *tetri, int x, int y);
int			fillit(u_int16_t *map, t_tetri *tetris, int n_tetris, int map_size);

//print_tests.c TO DO: erase all
void		ft_print_bin_map_line(u_int16_t map_line, u_int16_t bit_size);
void		ft_print_bin_map(u_int16_t *map);
void		ft_print_tetri(t_tetri tetri, u_int16_t bit_size);
void		ft_print_tetri_16(t_tetri tetri);
void		ft_print64(u_int64_t id);

#endif
