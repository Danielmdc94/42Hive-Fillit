/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:35:25 by acastano          #+#    #+#             */
/*   Updated: 2022/03/16 11:44:35 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			ft_bitoi_base(char *binary_string, int base);
static int			ft_positive_pow(int x, int y);
static u_int16_t	ft_move_piece(u_int16_t piece);

/*
 * str_to_int() takes the str containing the file and the n of tetris
 * creates an array of 16int storing the binary form of each piece
 * returns said array
 */
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

/*
 * ft_bitoi_base() takes str of numbers and desired base
 * Converts the srt into an int of said base
 * Returns said int
 */
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
	if (number == 0)
		error(6);
	return (number);
}

/*
 * ft_positive_pow() takes a base and an exponent
 * Calculates the result
 * Returns it
 */
static int	ft_positive_pow(int x, int y)
{
	int	res;

	res = 1;
	if (x < 0 || y < 0)
		error(6);
	while (y > 0)
	{
		res *= x;
		y--;
	}
	return (res);
}

/*
 * ft_move_piece() takes the int representing each tetrimino
 * shifts its bits so it appears to be at the top left
 * returns the new int with shifted bits
 */
static u_int16_t	ft_move_piece(u_int16_t piece)
{
	while (!(piece & 61440))
		piece = piece << 4;
	while (!(piece & 34952))
		piece = (piece << 1);
	return (piece);
}
