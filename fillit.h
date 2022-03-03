/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:54:47 by dpalacio          #+#    #+#             */
/*   Updated: 2022/03/03 13:31:56 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

//open()
# include <fcntl.h>

typedef struct s_tetri{
	char		*string;
	uint16_t	id_int;
	uint16_t	id_int0;
	uint16_t	id_int1;
	uint16_t	id_int2;
	uint16_t	id_int3;
	char		id_char;
	int			pos_x;
	int			pos_y;
}				t_tetri;

void		error(int error_code);
int			main(int argc, char **argv);
char		**read_file(char *file, int *n_tet);
uint16_t	*str_to_int(char **file, int n_tet);

#endif
