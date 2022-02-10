/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:46:01 by dpalacio          #+#    #+#             */
/*   Updated: 2022/02/10 17:10:27 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	validate_format(char *buff, int pieces);
int	create_matrix(char *buff, int bit, int i);

void	validate_file(char *file)
{
	int		fd;
	int		ret;
	int		pieces;
	char	buff[547];

	fd = open(file, O_RDONLY);
	ret = read(fd, buff, 547);
	if (fd == -1 || ret < 0)
		error(0);
	close(fd);
	buff[ret] = '\0';
	if ((ret + 1) % 21 != 0 || ret == 0)
		error(0);
	pieces = (ret + 1) / 21;
	validate_format(buff, pieces);
}

void	validate_format(char *buff, int pieces)
	{
	int		i;
	int		b;
	int		p;
	int		matrix[16][26];

	i = 0;
	b = 0;
	p = 0;
	while (buff[i] != '\0')
	{
		while (p < pieces)
		{
			if (i != 0 && buff[i] != '\n')
				error(0);
			while (b < 16)
			{
//				matrix[b][p] = create_matrix(buff, matrix[b][p], i);
				if (buff[i] == '\n')
					i++;
				if (buff[i] == '.')
					matrix[b][p] = 0;
				else if (buff[i] == '#')
					matrix[b][p] = 1;
				else
					error(0);
				ft_putnbr(matrix[b][p]);
				b++;
				i++;
			}
			if (buff[i] != '\n' && buff[i + 1] != '\n')
				error(0);
			ft_putchar('\n');
				i++;
			p++;
			b = 0;
		}
	}
}

int	create_matrix(char *buff, int bit, int i)
{
		if (buff[i] == '\n')
			i++;
		if (buff[i] == '.')
			bit = 0;
		else if (buff[i] == '#')
			bit = 1;
		else
			error(0);
	return (bit);
}
