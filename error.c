/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:47:42 by dpalacio          #+#    #+#             */
/*   Updated: 2022/02/10 13:28:12 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error(int error_code)
{
	if (error_code == 0)
		ft_putstr("error\n");
	if (error_code == 1)
		ft_putstr("usage: ./fillit <filename>\n");
	exit(-1);
}
