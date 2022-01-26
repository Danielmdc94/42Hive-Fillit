/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:59:00 by dpalacio          #+#    #+#             */
/*   Updated: 2022/01/26 15:59:16 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*static int	validate_file(char *buff, int pieces)
{
	int	i;
	int	x;
	int	y;
	int	z;
	int	blocks;

	i = 0;
	x = 0;
	y = 0;
	z = 0;
	blocks = 0;
	while (z < n_pieces)
	{
		while (y < 4)
		{
			while (x < 4)
			{
				if (str[i] != '.' && str[i] != '#')
					return (0);
				if (str[i] == '#')
				{
					blocks++;
					if (str[i] != str[i - 1] && str[i] != str[i + 1]
						&& str[i] != str[i - 5] && str[i] != str [i + 5])
						return (0);
				}
				x++;
				i++;
			}
			if (str[i] != '\n')
				return (0);
			x = 0;
			i++;
			y++;
		}
		if (z != n_pieces)
		{
			if (str[i] != '\n')
				return (0);
		}
		y = 0;
		if (blocks != 4)
			return (0);
		blocks = 0;
		i++;
		z++;
	}
	//ft_putstr(str);
	return (1);
}

static int	convert_file(char *file)
{
	int		fd;
	int		ret;
	int		pieces;
	char	buff[547];

	fd = open(file, O_RDONLY);
	ret = read(fd, buff, 547);
	if (fd == -1 || ret < 0)
		error_manager(0);
	close(fd);
	buff[ret] = '\0';
	if ((ret + 1) % 21 != 0 || ret == 0)
		error_manager(0);
	pieces = (ret + 1) / 21;
	validate_file(buff, pieces);
	return (1);
}
*/
int	main(int argc, char **argv)
{
	if (argc != 2)
		error_manager(1);
	if (convert_file(argv[1]) != 1)
		error_manager(0);
	else
		ft_putstr("It kinda works\n");
/*
	steps:
		- check if file is valid
		- extract all tetriminos
		- arrange in smallest square
		- izi pz
*/
	return (1);
}
