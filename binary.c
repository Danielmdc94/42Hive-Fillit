/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:00:03 by acastano          #+#    #+#             */
/*   Updated: 2022/02/21 21:37:33 by acastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdio.h>

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

int	ft_bitoint_base(char *binary_string, int base)
{
	int	exponent;
	int	number;

	if (!binary_string)
		return (-1);
	exponent = ft_strlen(binary_string) - 1;
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

int ft_print_bin(int int_piece)
{
    int i;

    i = 15;//0000 0000 0010 1110 is 46
    while (i >= 0)
    {
        if (int_piece & (1UL << i))
            printf("1");
        else
            printf("0");
		if (i % 4 == 0)
			printf("\n");
        i--;
    }
//....
//....
//..#.
//###.
    return (0);
}

int	ft_move_piece(int piece)
{
	while (!(piece & 1111000000000000))//if nothing in top line, shift up
		piece = piece << 4;
//	ft_print_bin(piece);
//	if (!(piece & 1000100010001000))//if nothing in left line, shift left. NOT WORKING
	if (!(piece & (1UL << 3) & (1UL << 7) && (1UL << 11) & (1UL << 15)))//if nothing in left line, shift left. IF IN WHILE LOOP, infinite loop >.< WHYYY
		piece = piece << 1;
	if (!(piece & (1UL << 3) & (1UL << 7) && (1UL << 11) & (1UL << 15)))//if nothing in left line, shift left
		piece = piece << 1;
	return (piece);
}

/*
int	ft_is_collision(int piece, int map)
{
	if ()
	return (0);
}
*/

int	main(void)
{
	int	piece;

	piece = 275;//46, 71, 39, 275
	printf("Base 2 \"0\" is %d\tatoi says \"%d\"\n", ft_bitoint_base("0", 2), ft_atoi("0"));
	printf("Base 2 \"101100\" is %d\tatoi says \"%d\"\n", ft_bitoint_base("101100", 2), ft_atoi("101100"));
	printf("Base 10 \"0\" is %d\tatoi says \"%d\"\n", ft_bitoint_base("0", 10), ft_atoi("0"));
	printf("Base 10 \"101100\" is %d\tatoi says \"%d\"\n", ft_bitoint_base("101100", 10), ft_atoi("101100"));
	printf("Base 10 \"0\" is %d\tatoi says \"%d\"\n", ft_bitoint_base("0", 10), ft_atoi("0"));
	printf("Base 10 \"0101100\" is %d\tatoi says \"%d\"\n", ft_bitoint_base("0101100", 10), ft_atoi("0101100"));
	printf("\nLets try to print those binary numbers\n");

	ft_print_bin(piece);
	printf("\n");
	printf("\nLets boogie the piece to the top corner\n");
	piece = ft_move_piece(piece);
	ft_print_bin(piece);
	printf("\n");
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
