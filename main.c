/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:59:00 by dpalacio          #+#    #+#             */
/*   Updated: 2022/03/21 19:20:12 by acastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	char		**file;
	int			n_tetris;
	t_tetri		*tetris;
	u_int16_t	map[13];
	u_int16_t	*strtoi;

	n_tetris = 0;
	if (argc != 2)
		error(0);
	file = read_file(argv[1], &n_tetris);
	tetris = (t_tetri *)ft_memalloc(sizeof(t_tetri)
			* n_tetris + sizeof(t_tetri *));
	strtoi = str_to_int(file, n_tetris);
	build_struct(n_tetris, file, strtoi, tetris);
	free(strtoi);
	solver(map, tetris, n_tetris, get_mapsize(n_tetris));
	while (n_tetris > 0)
	{
		ft_strdel(&(file[n_tetris - 1]));
		n_tetris--;
	}
	free(tetris);
	free(file);
	return (0);
}
