/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:59:00 by dpalacio          #+#    #+#             */
/*   Updated: 2022/03/15 12:25:43 by dpalacio         ###   ########.fr       */
/*   Updated: 2022/03/07 12:29:37 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_solver(u_int16_t *map, t_tetri *tetri_array,
		int n_tetris, int map_size)
{
	t_filldata	data;

	data.n_tetris = n_tetris;
	data.map_size = map_size;
	ft_init_map(map, map_size);
	while (map_size < 13)
	{
		if (fillit(map, tetri_array, data) == 1)
			break ;
		else
			error(8);
	}
}

int	main(int argc, char **argv)
{
	char		**file;
	int			n_tetris;
	t_tetri		*tetri_array;
	u_int16_t	map_size;
	u_int16_t	map[13];

	n_tetris = 0;
	map_size = 0;
	if (argc != 2)
		error(0);
	file = read_file(argv[1], &n_tetris);
	tetri_array = (t_tetri *)ft_memalloc(sizeof(t_tetri)
			* n_tetris + sizeof(t_tetri *));
	map_size = ft_map_size(n_tetris);
	build_struct(n_tetris, file, str_to_int(file, n_tetris), tetri_array);
	ft_solver(map, tetri_array, n_tetris, map_size);
	print_map(n_tetris, tetri_array, map_size);
	return (0);
}
