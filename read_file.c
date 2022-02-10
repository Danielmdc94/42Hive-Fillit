/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:48:28 by dpalacio          #+#    #+#             */
/*   Updated: 2022/02/10 19:30:04 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*validate_format(char *file, int tetriminos);

char	*read_file(char *file)
{
	int		fd;
	size_t	r_bytes;
	int		tetriminos;
	char	buff[547];
	char	*file_str;

	fd = open(file, O_RDONLY);
	r_bytes = read(fd, buff, 547);
	if (fd == -1 || r_bytes < 0)
		error(0);
	close(fd);
	buff[r_bytes] = '\0';
	if ((r_bytes + 1) % 21 != 0 || r_bytes == 0)
		error(0);
	tetriminos = (r_bytes + 1) / 21;
	file_str = ft_strdup(buff);
	return (validate_format(file_str, tetriminos));
}

char	*validate_format(char *file_str, int tetriminos)
{
	int	i;

	tetriminos = 0;
	i = 0;
	while (file_str[i] != '\0')
	{
		if ((i + 1) % 21 == 0 && file_str[i] != '\n')
			error(0);
		if (file_str[i] == '\n')
			i++;
		if (file_str[i] == '\n')
			i++;
		if (file_str[i] != '.' && file_str[i] != '#')
			error(0);
		ft_putchar(file_str[i]);
		i++;
	}


	return (file_str);
}
