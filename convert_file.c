/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_binary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:59:49 by dpalacio          #+#    #+#             */
/*   Updated: 2022/03/14 15:57:41 by acastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			ft_bitoi_base(char *binary_string, int base);
static int			ft_positive_pow(int x, int y);
static u_int16_t	ft_move_piece(u_int16_t piece);

u_int16_t	*str_to_int(char **file, int n_tetri)
{
	u_int16_t	*pieces;
	int			i;

	pieces = (u_int16_t *)ft_memalloc(sizeof(int) * n_tetri);
	i = 0;
	while (i < n_tetri)
	{
		*pieces = ft_bitoi_base(*file, 2);
		*pieces = ft_move_piece(*pieces);
		pieces++;
		file++;
		i++;
	}
	pieces = pieces - n_tetri;
	return (pieces);
}

static int	ft_bitoi_base(char *binary_string, int base)
{
	int	exponent;
	int	number;

	if (!binary_string)
		error(0);
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

static int	ft_positive_pow(int x, int y)
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

static u_int16_t	ft_move_piece(u_int16_t piece)
{
	while (!(piece & 61440))
		piece = piece << 4;
	while (!(piece & 34952))
		piece = (piece << 1);
	return (piece);
}
