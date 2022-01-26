/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:46:01 by dpalacio          #+#    #+#             */
/*   Updated: 2022/01/26 15:53:57 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	validate_file(char *buff, int pieces)
{
	buff = NULL;
	pieces =0;
	return (1);
}

int	convert_file(char *file)
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
	validate_file(buff, pieces);
	return (1);
}
