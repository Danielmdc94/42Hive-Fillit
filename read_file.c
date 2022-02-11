/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:48:28 by dpalacio          #+#    #+#             */
/*   Updated: 2022/02/11 13:34:32 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*validate_format(char *file, int tetriminos);
int		check_tet(char *file_str, int i);

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

	i = 0;
	while (file_str[i] != '\0' && tetriminos > 0)
	{
		i = check_tet(file_str, i);
		if (file_str[i] != '\n' && file_str[i] != '\0')
			error(0);
		tetriminos--;
		i++;
//		ft_putchar('\n');
	}
	return (file_str);
}

int	check_tet(char *file_str, int i)
{
	int	lines;
	int	columns;

	lines = 0;
	columns = 0;
	while (lines < 4)
	{
		while (columns < 4)
		{
//			ft_putchar(file_str[i]);
			if (file_str[i] != '.' && file_str[i] != '#')
				error(0);
			columns++;
			i++;
		}
		if (file_str[i] != '\n')
			error(0);
		columns = 0;
		i++;
		lines++;
//		ft_putchar('\n');
	}
	return (i);
}
