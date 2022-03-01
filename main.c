/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:59:00 by dpalacio          #+#    #+#             */
/*   Updated: 2022/02/28 19:59:49 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	char	**file;
	int		i;
	int		n_tet;
	int		*pieces;

	i = 0;
	n_tet = 0;
	if (argc != 2)
		error(1);
	file = read_file(argv[1], &n_tet);
	pieces = str_to_int(file, n_tet);
	while (i < n_tet)
	{
		ft_putstr(file[i]);
		ft_putstr(" -> ");
		ft_putnbr(*pieces);
		ft_putchar('\n');
		pieces++;
		i++;
	}
	ft_putstr("It kinda works\n");
	return (0);
}
