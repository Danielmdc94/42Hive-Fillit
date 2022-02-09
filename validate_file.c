/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:46:01 by dpalacio          #+#    #+#             */
/*   Updated: 2022/02/09 19:38:51 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	validate_file(char *file)
{
	int		fd;
	int		ret;
	int		pieces;
	char	buff[547];

	fd = open(file, O_RDONLY);
	ret = read(fd, buff, 547);
	if (fd == -1 || ret < 0)
		error_manager(0);
	close(fd);
	buff[ret] = '\0';
	if ((ret + 1) % 21 != 0 || ret == 0)
		error_manager(0);
	pieces = (ret + 1) / 21;
	return (1);
}
