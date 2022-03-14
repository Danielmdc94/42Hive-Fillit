/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:41:26 by dpalacio          #+#    #+#             */
/*   Updated: 2022/03/14 13:14:45 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	valid_tet(u_int16_t tetri_id);

void	build_struct(int n_tet, char **file,
		u_int16_t *piece_id, t_tetri *tetri)
{
	int			i;
	u_int64_t	int0;
	u_int64_t	int1;
	u_int64_t	int2;
	u_int64_t	int3;

	int0 = 0;
	int1 = 0;
	int2 = 0;
	int3 = 0;
	i = 0;
	while (i < n_tet)
	{
		(*tetri).id_int = *piece_id;
		(*tetri).string = file[i];
		(*tetri).id_char = 'A' + i;
		valid_tet((*tetri).id_int);
		int0 = ((u_int64_t)((*piece_id) & 61440) << 48);
		int1 = ((u_int64_t)((*piece_id) & 3840) << 36);
		int2 = ((u_int64_t)((*piece_id) & 240) << 24);
		int3 = ((u_int64_t)((*piece_id) & 15) << 12);
		(*tetri).id_int64 = ((int0) | (int1) | (int2) | (int3));
		piece_id++;
		tetri++;
		i++;
	}
}

void	ft_update_tetri(t_tetri *tetri, u_int16_t new_id)
{
	tetri->id_int = new_id;
}

void	valid_tet(u_int16_t tetri_id)
{
	int					i;
	static u_int16_t	valid_tet[19] = {11776, 17600, 19520, 19584, 19968,
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
		error(6);
}
