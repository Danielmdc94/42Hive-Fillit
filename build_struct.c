/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:41:26 by dpalacio          #+#    #+#             */
/*   Updated: 2022/03/14 15:29:48 by acastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	build_struct(int n_tet, char **file,
		u_int16_t *piece_id, t_tetri *tetri)
{
	int			i;

	i = 0;
	while (i < n_tet)
	{
		(*tetri).id_int = *piece_id;
		(*tetri).string = file[i];
		(*tetri).id_char = 'A' + i;
		valid_tetri((*tetri).id_int);
		(*tetri).id_int64 = ((u_int64_t)((*piece_id) & 61440) << 48);
		(*tetri).id_int64 |= ((u_int64_t)((*piece_id) & 3840) << 36);
		(*tetri).id_int64 |= ((u_int64_t)((*piece_id) & 240) << 24);
		(*tetri).id_int64 |= ((u_int64_t)((*piece_id) & 15) << 12);
		piece_id++;
		tetri++;
		i++;
	}
}

void	valid_tetri(u_int16_t tetri_id)
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
