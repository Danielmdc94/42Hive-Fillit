/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:41:26 by dpalacio          #+#    #+#             */
/*   Updated: 2022/03/21 18:24:27 by acastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	valid_tetri(u_int16_t tetri_id);

/*
 * build_struct() takes the n of tetris, the file str, and int array of pieces
 * fills all values of the struct for each tetri
 */
void	build_struct(int n_tetris, char **file,
		u_int16_t *piece_id, t_tetri *tetris)
{
	int			i;

	i = 0;
	while (i < n_tetris)
	{
		(*tetris).id_int = *piece_id;
		(*tetris).string = file[i];
		(*tetris).id_char = 'A' + i;
		valid_tetri((*tetris).id_int);
		(*tetris).id_int64 = ((u_int64_t)((*piece_id) & 0xF000) << 48);
		(*tetris).id_int64 |= ((u_int64_t)((*piece_id) & 0xF00) << 36);
		(*tetris).id_int64 |= ((u_int64_t)((*piece_id) & 0xF0) << 24);
		(*tetris).id_int64 |= ((u_int64_t)((*piece_id) & 0xF) << 12);
		piece_id++;
		tetris++;
		i++;
	}
}

/*
 * valid_tetri() takes the int id of a piece
 * checks if the id is of a valid tetri
 */
static void	valid_tetri(u_int16_t tetri_id)
{
	int					i;
	static u_int16_t	valid_tetri[19] = {11776, 17600, 19520, 19584, 19968,
		27648, 34952, 35008, 35904, 35968, 36352, 50240,
		50688, 51328, 52224, 57856, 58368, 59392, 61440};

	i = 0;
	while (i < 19)
	{
		if (valid_tetri[i] == tetri_id)
			break ;
		i++;
	}
	if (valid_tetri[i] != tetri_id)
		error(6);
}
