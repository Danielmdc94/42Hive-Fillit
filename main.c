/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:59:00 by dpalacio          #+#    #+#             */
/*   Updated: 2022/02/09 19:38:23 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		error_manager(1);
	if (validate_file(argv[1]) != 1)
		error_manager(0);
	else
		ft_putstr("It kinda works\n");
/*
	steps:
		- check if file is valid
		- extract all tetriminos
		- arrange in smallest square
		- izi pz
*/
	return (1);
}
