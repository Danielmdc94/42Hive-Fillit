

#include "fillit.h"

void		ft_init_map(u_int16_t *map, u_int16_t map_size);
u_int16_t	ft_map_size(u_int16_t n_tet);
void		ft_print_bin_map(u_int16_t *map);
void		ft_print_bin_map_line(u_int16_t map_line, u_int16_t bit_size);

u_int16_t	*map_gen(u_int16_t *map, int n_tet)
{
	u_int16_t	x;

	x = 0;
	ft_init_map(map, ft_map_size(n_tet));
	return (map);
}
	
void	ft_init_map(u_int16_t *map, u_int16_t map_size)
{
	u_int16_t	x;
	
	x = 0;
	if (map_size > 13)
		error(0);
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

u_int16_t    ft_map_size(u_int16_t n_tet)
{
	u_int16_t	bits;
	u_int16_t	size;

	bits = n_tet * 4;
	size = 4;
	while ((size * size) < bits)
		size++;
	return (size);
}

//From here is to print the map, testing purpose only
void	ft_print_bin_map(u_int16_t *map)
{
	u_int16_t x;

	x = 0;
	while (x < 13)
	{
		ft_print_bin_map_line(map[x], 16);
		x++;
	}
}

void	ft_print_bin_map_line(u_int16_t map_line, u_int16_t bit_size)
{
	int16_t i;

	i = bit_size - 1;
	while (i >= 0)
	{
		if (map_line & (1UL << i))
			ft_putchar('1');
		else
			ft_putchar('0');
		if ((bit_size == 16) && (i % 16 == 0))
			ft_putchar('\n');
		i--;
	}
}
