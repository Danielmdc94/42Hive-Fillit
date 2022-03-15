/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:54:47 by dpalacio          #+#    #+#             */
/*   Updated: 2022/03/15 17:55:37 by acastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

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

//read_file.c
char		**read_file(char *file, int *n_tetri);

//convert_file.c
u_int16_t	*str_to_int(char **file, int n_tetri);

//build_struct
void		build_struct(int n_tet, char **file,
				u_int16_t *piece_id, t_tetri *tetri);
void		valid_tetri(u_int16_t tetri_id);

//solver.c
u_int64_t	ft_reorg_piece(u_int64_t piece);
void		ft_solver(u_int16_t *map, t_tetri *tetris,
				int n_tetris, int map_size);

//printer.c
void		print_map(int n_tetris, t_tetri *tetris, int map_size);

//map.c
u_int16_t	ft_map_size(int n_tetris);
void		ft_init_map(u_int16_t *map, int map_size);
void		ft_update_map(u_int16_t *map, int x, int y, u_int64_t id_int64);
void		ft_revert_map(u_int16_t *map, int x, int y, t_tetri *tetris);

//error.c
void		error(int error_code);

#endif
