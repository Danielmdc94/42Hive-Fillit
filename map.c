

#include "fillit.h"

u_int16_t    ft_map_size(u_int16_t n_tetris)
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
