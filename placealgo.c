/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placealgo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:00:00 by acastano          #+#    #+#             */
/*   Updated: 2022/03/01 16:56:32 by acastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>//libft strnew and memalloc
#include <string.h>//memset

int	ft_abs(int n)//satu
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

static int	is_negative(int value)//satu
{
	if (value < 0)
		return (1);
	else
		return (0);
}

char	*ft_itoa_base(int value, int base)//satu
{
	char	*result;
	char	*digits;
	char	temp[32 + 1];
	int		i;

	if (base < 2 || base > 16)
		return (NULL);
	digits = "0123456789ABCDEF";
	i = 32;
	temp[i--] = '\0';
	if (value == 0)
		temp[i--] = '0';
	while (value != 0)
	{
		temp[i--] = digits[ft_abs(value % base)];
		value = value / base;
	}
	if (is_negative(value) && base == 10)
		temp[i--] = '-';
	result = (char *)malloc(32 - i + 1);
	if (result == NULL)
		return (NULL);
	return (strcpy(result, &temp[i + 1]));
}

typedef struct	s_tetri{
  char	*string;
  int	id_int;
  char	id_char;
  int	pos_x;
  int	pos_y;
}		t_tetri;

void	*ft_memalloc(size_t size)//libft
{
  void	*p;

  if (size == 0)
    return (NULL);
  p = malloc(size);
  if (p == NULL)
    return (NULL);
  memset(p, 0, size);
  return (p);
}

char	*ft_strnew(size_t size)//libft
{
  return ((char *)ft_memalloc(size));
}

int ft_print_map(char *map)
{
//0123 4567 8901 2345
//AAAA 0000 0000 0000
//AAAA B000 B000 BB00
  int i;

  i = 0;
  while (i < 16)
  {
	  printf("%c", map[i]);
	  if (i != 0 && (i % 4 == 3))
		  printf("\n");
      i++;
  }
  return (0);
/*
  int i;

  i = 16 - 1;
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
  return (0);*/
}

int ft_print_bin(int int_piece, int bit_size)
{
  int i;
  
  i = bit_size - 1;
  while (i >= 0)
    {
      if (int_piece & (1UL << i))
	printf("1");
      else
	printf("0");
      if ((bit_size == 16) && (i % 4 == 0))
	printf("\n");
      i--;
    }
  return (0);
}

//changed to print with tetris, not ints
int ft_print_tetri(t_tetri tetri, int bit_size)
{
  int i;

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
int	ft_move_piece(int piece)
{
  while (!(piece & 61440))//1111000000000000
    piece = piece << 4;
  while (!(piece & 34952))//1000100010001000
    piece = (piece << 1);
  return (piece);
}

//moves piece as many positions as x and y say
int	ft_shift_piece(int piece, int x, int y)
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

//checks for collision and places piece. under construction.
//Works if map is 4x4 and pieces fit in order
int	ft_placepiece(t_tetri *tetri, int map)
{
  int	i;
  int	j;
  int	temp_piece;
  
  i = 0;
  j = 0;
  temp_piece = tetri->id_int;
  while (j < 4)
  {
	  while (i < 4)
	  {
		  if (!(temp_piece & map))
		  {
			  map = map | temp_piece;
			  tetri->pos_x = i;
			  tetri->pos_y = j;
			  tetri->id_int = temp_piece;//---| x 0 y 0
			  /*		  printf("\nHere inside B is\n");
						  ft_print_bin(temp_piece, 16);
						  printf("\n");		  
						  tetri->string = strdup(ft_itoa_base(temp_piece, 2));*/
			  if (tetri->id_int == 'B')//hardcode to see if logic works FAIL
				  tetri->string = "0000100010001100";
			  return (map);
		  }
		  temp_piece = ft_shift_piece(temp_piece, 1, 0);//2 0
		  i++;
	  }
	  i = 0;
	  j++;
	  temp_piece = ft_shift_piece(tetri->id_int, 0, j);//2 0
  }
  return (map);
}

/*
t_tetri ft_stotetri(char *string, t_tetri tetri;)
{
  tetri.string = string;
  tetri.id_int = ft_bitoi_base(string, 2);
  return (tetri);
}
*/

char	*maptoletters(char *char_map, t_tetri tetri)
{
  int	i = 0;
  //what if no map string yet, does it come for sure,
  //or do we make it here?  if (*letter_map == NULL)
//AAAA .... .... ....
//B... B... BB.. ....
  char	*tetri_pos;

  tetri_pos = ft_itoa_base(tetri.id_int, 2);
  while (tetri_pos[i])
  {
      if (tetri_pos[i] == '1')
		  (char_map)[i] = tetri.id_char;
      i++;
  }
  free(tetri_pos);
  return (char_map);
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

  int	map;
  char	*char_map;
  t_tetri	A;
  t_tetri	B;
  //  t_tetri	C;t_tetri	D;
  map = 0;
  char_map = ft_strnew(15);
  memset(char_map, '.', 16);
  A.string = "1111000000000000";//make function that creates/updates all struct info?
  A.id_int = 61440;
  A.id_char = 'A';
  B.string = "1000100011000000";
  B.id_int = 35008;
  B.id_char = 'B';
  ft_print_tetri(A, 16);
  printf("\n");
  ft_print_tetri(B, 16);

//  printf("\nNow place A in map and print it \n");
  map = ft_placepiece(&A, map);
//  ft_print_map(char_map);
//  printf("\n");
//  printf("\nNow place B in map\n");
  map = ft_placepiece(&B, map);
//  printf("The value of B after placing in map is for string %s and for id_int %d\n", B.string, B.id_int);
  printf("The bit map after placing A and B:\n");
  ft_print_bin(map, 16);
  printf("\n");

  printf("The char_map after placing A:\n");
  char_map = maptoletters(char_map, A);
//  printf("\n%s\n", char_map);
  ft_print_map(char_map);
//  printf("\nB piece is %s\n", B.string);
//  printf("\nThe char_map after placing A and B:\n");
//  char_map = maptoletters(char_map, B);     TO DO PROBLEM
  printf("Char map printf\n%s\ncharmap printmap\n", char_map);
  ft_print_map(char_map);
  printf("\nft_print_bin map\n");
  ft_print_bin(map, 16);
  free(char_map);
  return (0);
}
