/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:59:00 by dpalacio          #+#    #+#             */
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
	int			i; //printing test index
	int			n_tet;
	t_tetri		*tetri;

	i = 0;
	n_tet = 0;
	if (argc != 2)
		error(1);
	file = read_file(argv[1], &n_tet);
	tetri = (t_tetri *)ft_memalloc(sizeof(t_tetri) * n_tet + sizeof(t_tetri *));
	build_struct(n_tet, file, str_to_int(file, n_tet), tetri);
//Printing for testing purposes:
	while (i < n_tet)
	{
		ft_print_bin((*tetri).id_int0, 16);
		ft_putchar('\n');
		ft_print_bin((*tetri).id_int1, 16);
		ft_putchar('\n');
		ft_print_bin((*tetri).id_int2, 16);
		ft_putchar('\n');
		ft_print_bin((*tetri).id_int3, 16);
		ft_putchar('\n');
//		ft_putstr((*tetri).string);
//		ft_putstr("\t->\t");
//		ft_putnbr((*tetri).id_int);
//		ft_putstr("\t->\t");
//		ft_print_bin((*tetri).id_int, 16);
//		ft_putstr("\t->\t");
//		ft_putchar((*tetri).id_char);
		ft_putchar('\n');
		tetri++;
		i++;
	}
	ft_putstr("It kinda works\n");
	return (0);
}
