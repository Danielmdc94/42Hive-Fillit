/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:59:00 by dpalacio          #+#    #+#             */
/*   Updated: 2022/01/21 15:38:14 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/get_next_line.h"
#include <fcntl.h>

static int	check_file(char *file)
{
	int fd;
	char *matrix;

	matrix = NULL;
	fd = open(file, O_RDONLY);
	get_next_line(fd, &matrix);
	close(fd);

	if (ft_strcmp(file, "test") != 0)
		return (0);
	ft_putstr("It kinda works\n");
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
		ft_putstr("error\n");

/*
	steps:
		- check if file is valid
		- extract all tetriminos
		- arrange in smallest square
		- izi pz
*/
	return(1);
}
