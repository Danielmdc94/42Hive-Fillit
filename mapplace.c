/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapplace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:16:00 by acastano          #+#    #+#             */
/*   Updated: 2022/03/04 12:20:22 by acastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>//libft strnew and memalloc
#include <string.h>//memset

/*
typedef struct	s_tetri{
	char			*string;//string orig to top left
  uint16_t		id_int;//int orig top left
  uint16_t		id_int0;
  uint16_t		id_int1;
  uint16_t		id_int2;
  uint16_t		id_int3;
  char			id_char;
  uint16_t		pos_x;
  uint16_t		pos_y;
}				t_tetri;
*/

/*
//changed to print with tetris, not ints
int ft_print_tetri(t_tetri tetri, uint16_t bit_size)
{
  uint16_t i;

  i = bit_size - 1;
  while (i >= 0)
  {
      if (tetri.id_int & (1UL << i))
		  printf("%c", tetri.id_char);
      else
		  printf(".");
      if ((bit_size == 16) && (i % 4 == 0))
		  printf("\n");
      i--;
  }
  return (0);
}

//so far same as in binary.c
uint16_t	ft_move_piece(uint16_t piece)
{
  while (!(piece & 61440))//1111000000000000
    piece = piece << 4;
  while (!(piece & 34952))//1000100010001000
    piece = (piece << 1);
  return (piece);
}

//moves piece as many positions as x and y say
uint16_t	ft_shift_piece(uint16_t piece, uint16_t x, uint16_t y)
{
  while (y > 0 && !(piece & 15))//0000000000001111
    {
      piece = piece >> 4;
      y--;
    }
  while (x > 0 && !(piece & 4369))//0001000100010001
    {
      piece = piece >> 1;
      x--;
    }
  return (piece);
}
*/

/*
t_tetri ft_stotetri(char *string, t_tetri tetri;)
{
  tetri.string = string;
  tetri.id_int = ft_bitoi_base(string, 2);
  return (tetri);
}
*/

//same map.c
uint16_t	ft_map_size(uint16_t tetriminos)
{
	uint16_t	bits;
	uint16_t	size;

	bits = tetriminos * 4;
	size = 4;
	while ((size * size) < bits)
		size++;
	return (size);
}

//same map.c
uint16_t	ft_init_map(uint16_t *map, uint16_t i)
{
	uint16_t	x;

	x = 0;
	if (i > 13)
		return (1);
	while (x < i)
	{
		map[x] = (65535 >> i);//FFFF
		x++;
	}
	i = i - 1;
	while (x < 13)
	{
		map[x] = 65535;
		x++;
	}
	return (0);
}

//same map.c
uint16_t ft_print_bin_map_line(uint16_t map_line, uint16_t bit_size)
{
  int16_t i;
  
  i = bit_size - 1;
  while (i >= 0)
  {
      if (map_line & (1UL << i))
		  printf("1");
      else
		  printf("0");
      if ((bit_size == 16) && (i % 16 == 0))
		  printf("\n");
      i--;
  }
  return (0);
}

//same map.c
uint16_t ft_print_bin_map(uint16_t *map)
{
  int16_t x;
  
  x = 0;

  while (x < 13)
  {
	  ft_print_bin_map_line(map[x], 16);
	  x++;
  }
  return (0);
}

/*
char	*maptoletters(char *char_map, t_tetri tetri)
{
  uint16_t	i = 0;
  //what if no map string yet, does it come for sure,
  //or do we make it here?  if (*letter_map == NULL)
//AAAA .... .... ....
//B... B... BB.. ....
  char	*tetri_pos;

  tetri_pos = ft_itoa_base(tetri.id_uint16_t, 2);
  while (tetri_pos[i])
  {
      if (tetri_pos[i] == '1')
		  (char_map)[i] = tetri.id_char;
      i++;
  }
  free(tetri_pos);
  return (char_map);
}
*/

uint16_t	ft_line_collision(uint16_t map_line, uint16_t tetri_line)
{
	if (map_line & tetri_line)
		return (1);
	return (0);//no collision
}

uint16_t	ft_tetri_collision(uint16_t *map, t_tetri *tetri)
{
	if ()
		return (1);
	return (0);
}

uint16_t	ft_is_collision(uint16_t *map, uint16_t map_size, t_tetri *tetri)
{
  uint16_t	x;
  uint16_t	y;
  t_tetri	*temp;//tetri

  temp.id_char = tetri.id_char;
  temp.string = ft_strdup(tetri.string);
  temp.id_int = tetri.id_int;
  temp.id_int0 = tetri.id_int0;
  temp.id_int1 = tetri.id_int1;
  temp.id_int2 = tetri.id_int2;
  temp.id_int3 = tetri.id_int3;
  temp.pos_x = tetri.pos_x;
  temp.pos_y = tetri.pos_y;
  
  x = 0;
  y = 0;
  while (y < map_size)
  {
	  while (x < map_size)
	  {
		  if (map[y] & temp.id_int0)
			  return (1);
		  i++;
	  }
	  i = 0;
	  j++;
	  temp_piece = ft_shift_piece(tetri->id_int, 0, j);//2 0
  }
  free(temp.string);
  return (0);
}

//checks for collision and places piece. under construction.
//Works if map is 4x4 and pieces fit in order
uint16_t	ft_placepiece(uint16_t *map, t_tetri *tetri)
{
  uint16_t	x;
  uint16_t	y;
  uint16_t	temp_piece;
  
  x = 0;
  y = 0;
  temp_piece = tetri->id_int;
  while (y < 4)
  {
	  while (x < 4)
	  {
		  if (!(temp_piece & map))
		  {
			  map = map | temp_piece;
			  tetri->pos_x = x;
			  tetri->pos_y = y;
			  tetri->id_int = temp_piece;//---| x 0 y 0
			  if (tetri->id_int == 'B')
				  tetri->string = "0000100010001100";
			  return (map);
		  }
		  temp_piece = ft_shift_piece(temp_piece, 1, 0);//2 0
		  x++;
	  }
	  x = 0;
	  y++;
	  temp_piece = ft_shift_piece(tetri->id_int, 0, y);//2 0
  }
  return (map);
}

int	main(void)
{
/*
	pieceA = 61440;//1111000000000000;
	pieceB = 35008;//1000100011000000;
	pieceC = 52224;//1100110000000000;
	pieceD = 275;//0001000100110000;
	//pieceD = ft_move_piece(pieceD);
	//	pieceD = 4400;//0001000100110000;
	map = 0;
	//46, 71, 39, 275, not valid but good test 19
*/

	t_tetri	A;
	uint16_t	map[13];
	uint16_t	num_tetriminos;//get from Daniel

  num_tetriminos = 1;
  A.id_char = 'A';
  A.string = "1111000000000000";
  A.id_int = 61440;
  A.id_int0 = A.id_int & 61440;//F000
  A.id_int1 = A.id_int & 3840;//F00
  A.id_int2 = A.id_int & 240;//F0
  A.id_int3 = A.id_int & 15;//F
  A.pos_x = 0;
  A.pos_y = 0;
//  char	*char_map;
//  char_map = ft_strnew(15);
//  memset(char_map, '.', 16);

//  printf("\nPrint char_ map\n");
//  ft_print_map(char_map);
//  printf("\n");

  ft_init_map(map, ft_map_size(num_tetriminos));
  printf("\nft_print_bin_map of desired size\n\n");
  ft_print_bin_map(map);

//  free(char_map);
  return (0);
}
