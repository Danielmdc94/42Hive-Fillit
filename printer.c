/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:37:27 by acastano          #+#    #+#             */
/*   Updated: 2022/03/16 11:59:38 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_fill_letters(char *map_char, t_tetri tetri, int map_size);

/*
 * print_map() takes the n of tetris, the array of tetris and the map size
 * it prints the final result after every piece is placed
 */
void	print_map(int n_tetris, t_tetri *tetris, int map_size)
{
	u_int16_t	i;
	char		*map_char;
	u_int16_t	map_len;

	map_len = map_size * map_size;
	i = 0;
	map_char = (char *)malloc(sizeof(char) * (map_len + 1));
	ft_memset(map_char, '.', map_len);
	map_char[map_len] = '\0';
	while (i < n_tetris)
	{
		ft_fill_letters(map_char, tetris[i], map_size);
		i++;
	}
	i = 0;
	while (i < map_len)
	{
		ft_putchar(map_char[i]);
		if (((i + 1) % map_size) == 0)
			ft_putchar('\n');
		i++;
	}
	ft_strdel(&map_char);
}

/*
 * ft_fill_letters() takes the current char, each of the tetris and the map size
 * switches the current map char for the given tetri ID char if applicable
 */
static void	ft_fill_letters(char *map_char, t_tetri tetri, int map_size)
{
	u_int16_t	i;
	u_int16_t	x;
	u_int16_t	y;
	u_int64_t	temp;

	i = 0;
	x = 0;
	temp = (tetri.id_int64 >> tetri.pos_x);
	y = (map_size * tetri.pos_y);
	while (i < 64)
	{
		if (temp & (0x8000000000000000 >> i))
		map_char[x + y] = tetri.id_char;
		i++;
		x++;
		if (x == 16)
		{
			y = y + map_size;
			x = 0;
		}
	}
}
