/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:35:55 by acastano          #+#    #+#             */
/*   Updated: 2022/03/21 18:31:31 by acastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 * NORM VERSION - only error or usage message.
 * error() takes an error code depending on where it was called
 * exits the program with a message corresponding the error code
 */
void	error(int error_code)
{
	if (error_code == 0)
		ft_putstr("usage: ./fillit <filename>\n");
	else
		ft_putstr("error\n");
	exit(-1);
}
