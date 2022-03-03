/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:59:00 by dpalacio          #+#    #+#             */
/*   Updated: 2022/03/03 14:33:43 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	valid_tet(uint16_t tetri_id);

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
//		if ((bit_size == 16) && (i % 4 == 0))
//			ft_putchar('\n');
		i--;
	}
	return (0);
}

void	fill_tet_struct(int n_tet, char **file,
		uint16_t *piece_id, t_tetri *tetri)
{
	int			i;

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

int	main(int argc, char **argv)
{
	char		**file;
	int			i;
	int			n_tet;
	uint16_t	*piece_id;
	t_tetri		*tetri;

	i = 0;
	n_tet = 0;
	if (argc != 2)
		error(1);
	file = read_file(argv[1], &n_tet);
	piece_id = str_to_int(file, n_tet);
	tetri = (t_tetri *)ft_memalloc(sizeof(t_tetri) * n_tet + sizeof(t_tetri *));
	fill_tet_struct(n_tet, file, piece_id, tetri);
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
