

#include "fillit.h"

u_int16_t	ft_map_size(u_int16_t n_tetris)
{
	u_int16_t	size;

	size = 3;
	while ((size * size) < (n_tetris * 4))
		size++;
	return (size);
}

void	ft_init_map(u_int16_t *map, u_int16_t map_size)
{
	u_int16_t	x;

	x = 0;
	if (map_size > 13)
		error(7);
	while (x < map_size)
	{
		map[x] = (65535 >> map_size);
		x++;
	}
	map_size--;
	while (x < 13)
	{
		map[x] = 65535;
		x++;
	}
}

void	ft_fill_letters(char *map_char, t_tetri tetri, u_int16_t map_size)
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
		if (temp & (9223372036854775808UL >> i))
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
/*
0123456789012345
0011000000000000  DDAA
0001000000000000  CDDA
0001000000000000  CCCA
0000000000000000  BBBB
*/
