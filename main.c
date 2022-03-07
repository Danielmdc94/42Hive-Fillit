/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:59:00 by dpalacio          #+#    #+#             */
/*   Updated: 2022/03/07 17:55:45 by acastano         ###   ########.fr       */
/*   Updated: 2022/03/07 12:29:37 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_print_bin(int int_piece, int bit_size)
{
	int	i;

	i = bit_size - 1;
	while (i >= 0)
	{
		if (int_piece & (1UL << i))
			ft_putchar('#');
		else
			ft_putchar('.');
		i--;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char		**file;
	int			i; //only for printing tests
	int			n_tet;
	t_tetri		*tetri_array;
	uint16_t	map[13];

	i = 0;
	n_tet = 0;
	if (argc != 2)
		error(1);
	file = read_file(argv[1], &n_tet);
	tetri_array = (t_tetri *)ft_memalloc(sizeof(t_tetri) * n_tet + sizeof(t_tetri *));
	build_struct(n_tet, file, str_to_int(file, n_tet), tetri_array);
	map_gen(map, n_tet);
//Printing for testing purposes:
	while (i < n_tet)
	{
		ft_print_bin((*tetri_array).id_int0, 16);
		ft_putchar('\n');
		ft_print_bin((*tetri_array).id_int1, 16);
		ft_putchar('\n');
		ft_print_bin((*tetri_array).id_int2, 16);
		ft_putchar('\n');
		ft_print_bin((*tetri_array).id_int3, 16);
		ft_putchar('\n');
//		ft_putstr((*tetri_array).string);
//		ft_putstr("\t->\t");
//		ft_putnbr((*tetri_array).id_int);
//		ft_putstr("\t->\t");
//		ft_print_bin((*tetri_array).id_int, 16);
//		ft_putstr("\t->\t");
//		ft_putchar((*tetri_array).id_char);
		ft_putchar('\n');
		tetri_array++;
		i++;
	}
	ft_putstr("It kinda works\n");
	ft_putstr("\n\ndaniels havoc\n\n");
	return (0);
}
