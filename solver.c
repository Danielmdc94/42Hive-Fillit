/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:33:30 by acastano          #+#    #+#             */
/*   Updated: 2022/03/17 11:12:11 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	fillit(u_int16_t *map, t_tetri *tetris, int n_tetris, int map_size);
static int	place_tetri(u_int16_t *map, t_tetri *tetri, int x, int y);
static int	collision(u_int16_t *map, t_tetri tetri, int x, int y);

/*
 * reorg_piece() takes the 64bit uint representing the tetrimino,
 * reverses the order of its bits in blocks of 16 bits
 * Return value: A 64bit uint of the reversed value.
 */
u_int64_t	reorg_piece(u_int64_t id_int64)
{
	u_int64_t	temp_piece;

	temp_piece = (id_int64 >> 48);
	temp_piece = (temp_piece | ((id_int64 >> 16) & 0xFFFF0000));
	temp_piece = (temp_piece | ((id_int64 << 16) & 0xFFFF00000000));
	temp_piece = (temp_piece | ((id_int64 << 48) & 0xFFFF000000000000));
	return (temp_piece);
}

/*
 * solver() takes the map array, the array and the n of tetris, and the map size.
 * Calls init_map() to initialize the map according to the map size,
 * and fillit() to place the tetris in the map.
 * If all the pieces are placed (fillit() returns 1) it will call print_map()
 * Otherwise, it will grow the map size and call fillit() again.
 * If the pieces can't be placed, it will exit by calling error(8).
 */
void	solver(u_int16_t *map, t_tetri *tetris, int n_tetris, int map_size)
{
	while (map_size < 13)
	{
		init_map(map, map_size);
		if (fillit(map, tetris, n_tetris, map_size) == 1)
		{
			print_map(n_tetris, tetris, map_size);
			return ;
		}
		map_size++;
	}
	error(8);
}

/*
 * fillit() takes the map array, the array of tetris, the n of tetris,
 * and the map_size
 * It will iterate through the map until all tetris have been placed,
 * with place_tetri(), recursively calling fillit() to place the next pieces. If
 * it can't, it will use revert_map() to take the previous piece, and try placing
 * it again in a new position.
 * Returns 1 if there is no more tetris to place, and 0 if it couldn't
 * place the tetris.
 */
static int	fillit(u_int16_t *map, t_tetri *tetris, int n_tetris, int map_size)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map_size)
	{
		while (x < map_size)
		{
			if (place_tetri(map, &(tetris[0]), x, y) == 1)
			{
				if ((n_tetris > 1) && fillit(map, &(tetris[1]),
						(n_tetris - 1), map_size) == 1)
					return (1);
				else if (n_tetris > 1)
					revert_map(map, x, y, tetris);
				else
					return (1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

/*
 * place_tetri() takes the map array, the tetri struct, and the position in the
 * map to place the tetri (x and y).
 * If there is no collision between the map and the piece, updates the position
 * values of the tetri, and the map.
 * Return values: 1 if tetri is placed, 0 otherwise.
 */
static int	place_tetri(u_int16_t *map, t_tetri *tetri, int x, int y)
{
	if (collision(map, *tetri, x, y) == 0)
	{
		tetri->pos_x = x;
		tetri->pos_y = y;
		update_map(map, x, y, tetri->id_int64);
		return (1);
	}
	return (0);
}

/*
 * collision() takes the map, a tetri struct, and the positions x and y where
 * to look for collision.
 * Shifts the piece to x position, calls reorg_piece() and checks for collision
 * between the map and the piece in that position.
 * Return values: 1 if there is collision, 0 if there isn't.
 */
static int	collision(u_int16_t *map, t_tetri tetri, int x, int y)
{
	if (x > 0)
		tetri.id_int64 = (tetri.id_int64 >> x);
	tetri.id_int64 = reorg_piece(tetri.id_int64);
	if (((*(u_int64_t *)(map + y)) & (tetri.id_int64)) != 0)
		return (1);
	return (0);
}
