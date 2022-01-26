/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:47:42 by dpalacio          #+#    #+#             */
/*   Updated: 2022/01/26 14:28:43 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error_manager(int error_code)
{
	if (error_code == 0)
		ft_putstr("error\n");
	if (error_code == 1)
		ft_putstr("usage: Number of arguments should be 1 (one) -> ./fillit <filename>\n");
	exit(-1);
}
