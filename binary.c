
//#include "./libft/libft.h"
#include <stdio.h>
#include <string.h>//strlen
#include <stdlib.h>//atoi

//TODO protect functions: valid input, max min values

//helper for ft_bitoi_base
int	ft_positive_pow(int x, int y)
{
	int	res;

	res = 1;
	if (x < 0 || y < 0)
		return (-1);
	while (y > 0)
	{
		res *= x;
		y--;
	}
	return (res);
}

//Converts a string to int, taking into account the base.
//101 base 10 is 101, 101 base 2 is 5.
int	ft_bitoi_base(char *binary_string, int base)
{
	int	exponent;
	int	number;

	if (!binary_string)
		return (-1);
	exponent = strlen(binary_string) - 1;
//	exponent = 16 - 1;
	number = 0;
	while (exponent >= 0)
	{
		number += (*binary_string - 48) * ft_positive_pow(base, exponent);
		exponent--;
		binary_string++;
	}
	return (number);
}

//Prints binary representation of int. bit_size to print 4 lines of 4bits (tetriminos)
//46 prints 0000\n0000\n0010\n1110\n
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

//changes piece into most upper left position/representation
//0000 0000 0010 0111 becomes 0100 1110 0000 0000
int	ft_move_piece(int piece)
{
  while (!(piece & 61440))//1111000000000000
    piece = piece << 4;
  while (!(piece & 34952))//1000100010001000
    piece = (piece << 1);
  return (piece);
}

int	main(void)
{
	uint	pieceA;
	uint	pieceB;
	uint	pieceC;
	uint	pieceD;

	pieceA = 61440;//1111000000000000;
	pieceB = 35008;//1000100011000000;
	pieceC = 52224;//1100110000000000;
	pieceD = 4400;//0001000100110000;
	/*
	//46, 71, 39, 275, not valid but good test 19
	printf("Base 2 \"0\" is %d\tatoi says \"%d\"\n", ft_bitoint_base("0", 2), atoi("0"));
	printf("Base 2 \"101100\" is %d\tatoi says \"%d\"\n", ft_bitoint_base("101100", 2), atoi("101100"));
	printf("Base 10 \"0\" is %d\tatoi says \"%d\"\n", ft_bitoint_base("0", 10), atoi("0"));
	printf("Base 10 \"101100\" is %d\tatoi says \"%d\"\n", ft_bitoint_base("101100", 10), atoi("101100"));
	printf("Base 10 \"0\" is %d\tatoi says \"%d\"\n", ft_bitoint_base("0", 10), atoi("0"));
	printf("Base 10 \"0101100\" is %d\tatoi says \"%d\"\n", ft_bitoint_base("0101100", 10), atoi("0101100"));
	*/
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
	return (0);
}

//struct
//char *string;
//int num;
//int height;
//int width;
//int pos_x;
//int pos_y;
//char id;
