/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:41:26 by dpalacio          #+#    #+#             */
/*   Updated: 2022/03/03 14:52:04 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	valid_tet(uint16_t tetri_id);

void	build_struct(int n_tet, char **file,
		uint16_t *piece_id, t_tetri *tetri)
{
	int	i;

	i = 0;
	while (i < n_tet)
	{
		(*tetri).id_int = *piece_id;
		(*tetri).id_int0 = *piece_id & 61440;
		(*tetri).id_int1 = (*piece_id << 4) & 61440;
		(*tetri).id_int2 = (*piece_id << 8) & 61440;
		(*tetri).id_int3 = (*piece_id << 12) & 61440;
		(*tetri).string = file[i];
		(*tetri).id_char = 'A' + i;
		valid_tet((*tetri).id_int);
		piece_id++;
		tetri++;
		i++;
	}
}

void	valid_tet(uint16_t tetri_id)
{
	int				i;
	static uint16_t	valid_tet[19] = {8800, 11776, 19520, 19584, 19968,
		27648, 34952, 35008, 35904, 35968, 36352, 50240,
		50688, 51328, 52224, 57856, 58368, 59392, 61440};

	i = 0;
	while (i < 19)
	{
		if (valid_tet[i] == tetri_id)
			break ;
		i++;
	}
	if (valid_tet[i] != tetri_id)
		error(0);
}
