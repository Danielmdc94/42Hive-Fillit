/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:59:00 by dpalacio          #+#    #+#             */
/*   Updated: 2022/01/24 19:02:23 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/get_next_line.h"
#include <fcntl.h>

static int	check_file(char *str, int n)
{
	int	len;
	int	i;
	int	x;

	i = 0;
	x = 1;
	len = ft_strlen(str);
	while (i <= len)
	{
		if (str[x * 5 - 1] != '\n')
			return (0);
		n++;
		i++;
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
	return(1);
}
