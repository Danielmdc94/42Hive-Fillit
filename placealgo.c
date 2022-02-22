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

//checks for collision and places piece. under construction
int	ft_placepiece(int piece, int map)
{
  if (!(piece & map))
    {
      map = map | piece; 
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
	printf("\nNow place piece in map and print it \n");
	map = ft_placepiece(pieceA, map);
	ft_print_bin(map, 16);
	printf("\n");
	return (0);
}
