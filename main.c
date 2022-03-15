/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:59:00 by dpalacio          #+#    #+#             */
/*   Updated: 2022/03/15 16:39:54 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_solver(u_int16_t *map, t_tetri *tetris,
		int n_tetris, int map_size)
{
	while (map_size < 13)
	{
		ft_init_map(map, map_size);
		if (fillit(map, tetris, n_tetris, map_size) == 1)
		{
			print_map(n_tetris, tetris, map_size);
			return ;
		}
		map_size++;
	}
	error(8);
}

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
	map_size = ft_map_size(n_tetris);
	build_struct(n_tetris, file, str_to_int(file, n_tetris), tetris);
	ft_solver(map, tetris, n_tetris, map_size);
	return (0);
}
