/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_binary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:59:49 by dpalacio          #+#    #+#             */
/*   Updated: 2022/02/25 15:29:12 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	str_to_int(char **file, int n_tet)
{
	int	*pieces;
	int	i;

	i = 0;
	while (i < n_tet)
	{
		*pieces = ft_bittoint_base(*file, 2);
		pieces++;
		*file++;
	}
}
