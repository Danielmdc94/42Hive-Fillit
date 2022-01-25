/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:59:00 by dpalacio          #+#    #+#             */
/*   Updated: 2022/01/25 14:06:20 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/get_next_line.h"
#include <fcntl.h>

static int	check_file(char *str, int n)
{
	int	i;
	int	x;
	int	y;
	int	z;
	int blocks;

	i = 0;
	x = 0;
	y = 0;
	z = 0;
	blocks = 0;
	while (z < n)
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
					if(str[i] != str[i - 1] && str[i]!= str[i + 1] 
						&& str[i] != str[i - 5] && str[i]!= str[i + 5])
						return (0);
				}
				if (blocks > 4)
					return (0);
				x++;
				i++;
			}
			if (str[i] != '\n')
				return (0);
			x = 0;
			i++;
			y++;
		}
		if (str[i] != '\n')
			return (0);
		y = 0;
		blocks = 0;
		i++;
		z++;
	}
	ft_putstr(str);
	return (1);
}

static int	convert_file(char *file)
{
	int		fd;
	int		ret;
	int		n;
	char	*buff;
	char	*str;

	buff = (char *)ft_memalloc(sizeof(char) * 21 + 1);
	fd = open(file, O_RDONLY);
	n = 1;
	if (fd == -1)
		return (0);
	ret = read(fd, buff, 21);
	str = ft_strdup(buff);
	while (ret > 0)
	{
		ret = read(fd, buff, 21);
		if (ret > 0)
		{
			str = ft_strjoin(str, buff);
			n++;
		}
	}
	ft_strdel(&buff);
	close(fd);
	return (check_file(str, n));
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit valid_file\n");
		return (0);
	}
	if (convert_file(argv[1]) != 1)
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
	return (1);
}
