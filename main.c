/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:59:00 by dpalacio          #+#    #+#             */
/*   Updated: 2022/03/16 12:36:37 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	char		**file;
	int			n_tetris;
	t_tetri		*tetris;
	u_int16_t	map_size;
	u_int16_t	map[13];

	n_tetris = 0;
	map_size = 0;
	if (argc != 2)
		error(0);
	file = read_file(argv[1], &n_tetris);
	tetris = (t_tetri *)ft_memalloc(sizeof(t_tetri)
			* n_tetris + sizeof(t_tetri *));
	map_size = map_size(n_tetris);
	build_struct(n_tetris, file, str_to_int(file, n_tetris), tetris);
	solver(map, tetris, n_tetris, map_size);
	return (0);
}
