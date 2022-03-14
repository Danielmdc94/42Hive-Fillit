

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
<<<<<<< HEAD
=======

u_int16_t	*map_gen(u_int16_t *map, int n_tetris)
{
  //	u_int16_t	x;

  //	x = 0;
	ft_init_map(map, ft_map_size(n_tetris));
	return (map);
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

void	ft_print_map(u_int16_t n_tetris, t_tetri *tetris, u_int16_t map_size)
{
  u_int16_t	i;
  char	*map_char;
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
	printf("\n");
      i++;
    }
  ft_strdel(&map_char);
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
>>>>>>> f694a682c0525cae4f88e538e02c2e0d7bc00ba6
