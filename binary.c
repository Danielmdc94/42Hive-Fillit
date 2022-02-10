/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:00:03 by acastano          #+#    #+#             */
/*   Updated: 2022/02/10 21:04:59 by acastano         ###   ########.fr       */
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
	number = 0;
	while (exponent >= 0)
	{
		number += (*binary_string - 48) * ft_positive_pow(base, exponent);
		exponent--;
		binary_string++;
	}
	return (number);
}

int	main(void)
{
	printf("Base 2 \"0\" is %d\n", ft_bitoint_base("0", 2));
	printf("Base 2 \"101100\" is %d\n", ft_bitoint_base("101100", 2));
	printf("Base 10 \"0\" is %d\n", ft_bitoint_base("0", 10));
	printf("Base 10 \"101100\" is %d\n", ft_bitoint_base("101100", 10));
	printf("Base 10 \"0\" is %d\n", ft_bitoint_base("0", 10));
	printf("Base 10 \"0101100\" is %d\n", ft_bitoint_base("0101100", 10));
	return (0);
}
