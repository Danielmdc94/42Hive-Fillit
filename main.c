/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:59:00 by dpalacio          #+#    #+#             */
/*   Updated: 2022/01/21 19:41:43 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/get_next_line.h"
#include <fcntl.h>

static int	check_file(char *file)
{
	int fd;
	int y;
	int z;
	char *matrix[4][4];

	y = 0;
	z = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	while (get_next_line(fd, (&matrix[y][z])) == 1)
	{
		ft_putstr(matrix[y][z]);
		ft_putchar('\n');
		y++;
		while (y <= 3)
		{
			get_next_line(fd, (&matrix[y][z]));
			ft_putstr(matrix[y][z]);
			ft_putchar('\n');
			y++;
		}
		y = 0;
		z++;
	}
	close(fd);

	if (ft_strcmp(matrix[0][0], "....") != 0)
		return (0);

	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit valid_file\n");
		return (0);
	}
	if (check_file(argv[1]) != 1)
	{
		ft_putstr("error\n");
		return (0);
	}
	else
		ft_putstr("It kinda works\n");
/*
	steps:
		- check if file is valid
		- extract all tetriminos
		- arrange in smallest square
		- izi pz
*/
	return(1);
}
