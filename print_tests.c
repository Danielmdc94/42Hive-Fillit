#include "fillit.h"


void	ft_print64(u_int64_t id)
{
	u_int64_t x;

	x = 0;
	while (x < 64)
	{
		if (id & (9223372036854775808UL >> x))
			printf("1");
		else
			printf("0");
		x++;
	}
}

int	ft_print_bin(int int_piece, int bit_size)
{
  int	i;

  i = bit_size - 1;
  while (i >= 0)
    {
      if (int_piece & (1UL << i))
	ft_putchar('#');
      else
	ft_putchar('.');
      i--;
    }
  return (0);
}

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

//for now joined constructing map_string and printing
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
//changed to print with tetris, not ints
void	ft_print_tetri(t_tetri tetri, u_int16_t bit_size)//TO DO: erase
{
  int i;

  i = bit_size - 1;
  while (i >= 0)
    {
      if (tetri.id_int & (1UL << i))
	ft_putchar(tetri.id_char);
      else
	ft_putchar('.');
      if ((bit_size == 16) && (i % 4 == 0))
	ft_putchar('\n');
      i--;
    }
}

//changed to print with tetris, not ints
void	ft_print_tetri_64(t_tetri tetri)//TO DO: erase
{
  int i;

  i = 64 - 1;
  while (i >= 0)
    {
      if (tetri.id_int64 & (1UL << i))
	ft_putchar(tetri.id_char);
      else
	ft_putchar('.');
      if (i % 16 == 0)
	ft_putchar('\n');
      i--;
    }
}
