/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:59:00 by dpalacio          #+#    #+#             */
/*   Updated: 2022/03/02 14:36:54 by dpalacio         ###   ########.fr       */
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
			ft_putchar('1');
		else
			ft_putchar('0');
//		if ((bit_size == 16) && (i % 4 == 0))
//			ft_putchar('\n');
		i--;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	**file;
	int		i;
	int		n_tet;
	uint16_t		*piece_id;
	t_tetri	*tetri;

	i = 0;
	n_tet = 0;
	if (argc != 2)
		error(1);
	file = read_file(argv[1], &n_tet);
	piece_id = str_to_int(file, n_tet);
	tetri = (t_tetri *)ft_memalloc(sizeof(t_tetri) * n_tet + sizeof(t_tetri *));
	while (i < n_tet)
	{
	//	*tetri = *(t_tetri *)ft_memalloc(sizeof(t_tetri));
		(*tetri).id_int = *piece_id;
		(*tetri).string = file[i];
		(*tetri).id_char = 'A' + i;
		piece_id++;
		tetri++;
		i++;
	}
	piece_id = piece_id - n_tet;
	tetri = tetri - n_tet;
	i = 0;

//Printing for testing purposes:
	while (i < n_tet)
	{
		ft_putstr((*tetri).string);
		ft_putstr("\t->\t");
		ft_putnbr((*tetri).id_int);
		ft_putstr("\t->\t");
		ft_print_bin((*tetri).id_int, 16);
		ft_putstr("\t->\t");
		ft_putchar((*tetri).id_char);
		ft_putchar('\n');
		tetri++;
		i++;
	}

	ft_putstr("It kinda works\n");
	return (0);
}
