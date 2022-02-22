/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:59:00 by dpalacio          #+#    #+#             */
/*   Updated: 2022/02/22 17:13:41 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	char	**file;

	if (argc != 2)
		error(1);
	file = read_file(argv[1]);
//	while (file)
//	{
//		ft_putstr(*file);
//		ft_putchar('\n');
//		(file)++;
//	}
//	convert_file(file);
	ft_putstr("It kinda works\n");
	return (0);
}
