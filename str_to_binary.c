/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_binary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:59:49 by dpalacio          #+#    #+#             */
/*   Updated: 2022/02/28 19:58:13 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int ft_bitoint_base(char *binary_string, int base);
int ft_positive_pow(int x, int y);

int	*str_to_int(char **file, int n_tet)
{
	int	*pieces;
	int	i;
	
	pieces = (int *)ft_memalloc(sizeof(int) * n_tet);
	i = 0;
	while (i < n_tet)
	{
		*pieces = ft_bitoint_base(*file, 2);
		pieces++;
		file++;
		i++;
	}
	pieces = pieces - n_tet;
	return (pieces);
}

int	ft_bitoint_base(char *binary_string, int base)
{
	int	exponent;
	int	number;
	if (!binary_string)
		{
			error(0);
		}
	exponent = ft_strlen(binary_string) - 1;
	number = 0;
	while (exponent >= 0)
	{
		number += (*binary_string - 48) * ft_positive_pow(base, exponent);
		exponent--;
		binary_string++;
	}
	return (number);
}

int ft_positive_pow(int x, int y)
{
	int	res;

	res = 1;
	if (x < 0 || y < 0)
		error(0);
	while (y > 0)
	{
		res *= x;
		y--;
	}
	return (res);
}
