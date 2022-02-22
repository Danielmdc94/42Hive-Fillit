/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:59:00 by dpalacio          #+#    #+#             */
/*   Updated: 2022/02/22 18:12:13 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	char	**file;
	int		i;

	i = 0;
	if (argc != 2)
		error(1);
	file = read_file(argv[1]);
	while (i < 4)
	{
		ft_putstr(file[i]);
		ft_putchar('\n');
		i++;
	}
	ft_putstr("It kinda works\n");
	return (0);
}
