/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:59:00 by dpalacio          #+#    #+#             */
/*   Updated: 2022/03/01 15:09:38 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int ft_print_bin(int int_piece, int bit_size)
{
  int i;
  
  i = bit_size - 1;
  while (i >= 0)
    {
	if (int_piece & (1UL << i))
		ft_putchar('1');
	else
		ft_putchar('0');
//	if ((bit_size == 16) && (i % 4 == 0))
//		ft_putchar('\n');
    i--;
    }
  return (0);
}

int	main(int argc, char **argv)
{
	char	**file;
	int		i;
	int		n_tet;
	int	*pieces;

	i = 0;
	n_tet = 0;
	if (argc != 2)
		error(1);
	file = read_file(argv[1], &n_tet);
	pieces = str_to_int(file, n_tet);
	while (i < n_tet)
	{
		ft_putstr(file[i]);
		ft_putstr("\t->\t");
		ft_putnbr(*pieces);
		ft_putstr("\t->\t");
		ft_print_bin(*pieces, 16);
		ft_putchar('\n');
		pieces++;
		i++;
	}
	ft_putstr("It kinda works\n");
	return (0);
}
