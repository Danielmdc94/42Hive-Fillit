/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placealgo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:00:00 by acastano          #+#    #+#             */
/*   Updated: 2022/02/22 20:30:30 by acastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

//so far same as in binary.c
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
int	ft_placepiece(int piece, int map)
{
  int	i;
  int	j;
  int	temp_piece;
  
  i = 0;
  j = 0;
  temp_piece = piece;
  while (j < 4)
    {
      while (i < 4)
	{
	  if (!(temp_piece & map))
	    {
	      map = map | temp_piece;
	      return (map);
	    }
	  temp_piece = ft_shift_piece(temp_piece, 1, 0);//2 0
	  i++;
	}
      i = 0;
      j++;
      temp_piece = ft_shift_piece(piece, 0, j);//2 0
    }
  return (map);
}

int	main(void)
{
	int	pieceA;
	int	pieceB;
	int	pieceC;
	int	pieceD;
	int	map;

	pieceA = 61440;//1111000000000000;
	pieceB = 35008;//1000100011000000;
	pieceC = 52224;//1100110000000000;
	pieceD = 275;//0001000100110000;
	//pieceD = ft_move_piece(pieceD);
	//	pieceD = 4400;//0001000100110000;
	map = 0;
	//46, 71, 39, 275, not valid but good test 19
	printf("\nLets print the pieces A B C D\n");
	ft_print_bin(pieceA, 16);
	printf("\n");
	ft_print_bin(pieceB, 16);
	printf("\n");
	ft_print_bin(pieceC, 16);
	printf("\n");
	ft_print_bin(pieceD, 16);
	printf("\n");
	//	printf("\nLets boogie the piece to the top corner\n");
	//	piece = ft_move_piece(piece);
	//	ft_print_bin(piece, 16);
	printf("\nNow place pieceA in map and print it \n");
	map = ft_placepiece(pieceA, map);
	ft_print_bin(map, 16);
	printf("\n");
	printf("\nNow place pieceB in map and print it \n");
	map = ft_placepiece(pieceB, map);
	ft_print_bin(map, 16);
	printf("\n");
	printf("\nNow place pieceC in map and print it \n");
	map = ft_placepiece(pieceC, map);
	ft_print_bin(map, 16);
	printf("\n");
	printf("\nNow place pieceD in map and print it \n");
	map = ft_placepiece(pieceD, map);
	ft_print_bin(map, 16);
	printf("\n");
	return (0);
}
