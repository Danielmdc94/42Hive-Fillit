/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:46:01 by dpalacio          #+#    #+#             */
/*   Updated: 2022/01/26 16:55:27 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	validate_file(char *buff, int ret, int pieces)
{
	int	i;
	int	x;
	int	y;
	int	blocks;
	pieces = 0;
	i = 0;
	x = 0;
	y = 0;
	blocks = 0;
	while (i < ret)
	{
		while (y < 4)
		{
			while (x < 4)
			{
				if (buff[i] != '.' && buff[i] != '#')
					error_manager(0);
				if (buff[i] == '#')
				{
					blocks++;
					if (buff[i] != buff[i - 1] && buff[i] != buff[i + 1]
						&& buff[i] != buff[i - 5] && buff[i] != buff [i + 5])
						error_manager(0);
				}
				x++;
				i++;
			}
			if (buff[i] != '\n')
				error_manager(0);
			x = 0;
			i++;
			y++;
		}
		if (buff[i] != '\n' && buff[i] != '\0')
			error_manager(0);
		y = 0;
		if (blocks != 4)
			error_manager(0);
		blocks = 0;
		i++;
	}
	return (1);
}

int	convert_file(char *file)
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
	validate_file(buff, ret, pieces);
	return (1);
}
