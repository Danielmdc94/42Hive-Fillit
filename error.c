/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:47:42 by dpalacio          #+#    #+#             */
/*   Updated: 2022/03/15 12:56:13 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error(int error_code)
{
	if (error_code == 0)
		ft_putstr("usage: ./fillit <filename>\n");
	if (error_code == 1)
		ft_putstr("error(1): Failed to read\n");
	if (error_code == 2)
		ft_putstr("error(2): Invalid format -> number of characters\n");
	if (error_code == 3)
		ft_putstr("error(3): Invalid format -> no newlines or EOF\n");
	if (error_code == 4)
		ft_putstr("error(4): Invalid format -> extraneous character\n");
	if (error_code == 5)
		ft_putstr("error(5): Invalid Format -> no newline separator\n");
	if (error_code == 6)
		ft_putstr("error(6): Invalid tetrimino\n");
	if (error_code == 7)
		ft_putstr("error(7): Minimum map size is too big\n");
	if (error_code == 8)
		ft_putstr("error(8): Could not fit all pieces in maximum map size\n");
	exit(-1);
}
