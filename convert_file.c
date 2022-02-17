/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:20:08 by dpalacio          #+#    #+#             */
/*   Updated: 2022/02/17 17:19:51 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	convert_file(char *file)
{
	int	i;
	int	matrix[16][26];
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (file[i] != '\0')
	{
		while (x < 16)
		{
			if (file[i] == '#')
			{
				matrix[x][y] = 1;
//				ft_putnbr(matrix[x][y]);
			}
			if (file[i] == '.')
			{
				matrix[x][y] = 0;
//				ft_putnbr(matrix[x][y]);
			}
			i++;
			if (file[i] != '\n')
				x++;
		}
//		ft_putchar('\n');
		x = 0;
		y++;
	}
	return (matrix);
}
