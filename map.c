/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:34:26 by acastano          #+#    #+#             */
/*   Updated: 2022/03/15 15:35:28 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

u_int16_t	ft_map_size(int n_tetris)
{
	u_int16_t	size;

	size = 2;
	while ((size * size) < (n_tetris * 4))
		size++;
	return (size);
}

void	ft_init_map(u_int16_t *map, int map_size)
{
	u_int16_t	x;

	x = 0;
	if (map_size > 13)
		error(7);
	while (x < map_size)
	{
		map[x] = (0xFFFF >> map_size);
		x++;
	}
	map_size--;
	while (x < 13)
	{
		map[x] = 0xFFFF;
		x++;
	}
}

void	ft_update_map(u_int16_t *map, int x, int y, u_int64_t id_int64)
{
	u_int64_t	reorg_map;
	u_int64_t	temp;

	temp = 0;
	reorg_map = ft_reorg_piece(*(u_int64_t *)(map + y));
	temp = (reorg_map | (id_int64 >> x));
	map[y] = (temp >> 48);
	map[y + 1] = (temp >> 32);
	map[y + 2] = (temp >> 16);
	map[y + 3] = (temp);
}

void	ft_revert_map(u_int16_t *map, int x, int y, t_tetri *tetris)
{
	u_int64_t	reorg_map;
	u_int64_t	temp;

	temp = 0;
	reorg_map = ft_reorg_piece(*(u_int64_t *)(map + y));
	temp = (reorg_map ^ (tetris[0].id_int64 >> x));
	map[y] = (temp >> 48);
	map[y + 1] = (temp >> 32);
	map[y + 2] = (temp >> 16);
	map[y + 3] = (temp);
	tetris->pos_x = 0;
	tetris->pos_y = 0;
}

void	ft_fill_letters(char *map_char, t_tetri tetri, int map_size)
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
