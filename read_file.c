/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:48:28 by dpalacio          #+#    #+#             */
/*   Updated: 2022/02/22 17:13:05 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*validate_format(char *file, int tetriminos);
int		check_tet(char *file_str, int i);
char	*isolate_piece(char *file_str, int tetriminos);

/*
 * read_file() takes the file's name given to the program.
 * Opens the file, reads it and checks characters read.
 * Returns the string containing the file once it has been validated.
 */

char	**read_file(char *file)
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
	validate_format(file_str, tetriminos);
	while (tetriminos > 0)
	{
		//isolate piece and store it somewhere = isolate_piece(file_str, tetriminos);
		tetriminos--;
	}
	return (/*Whatever we store the tetriminos in*/);
}

/*
 * validate_format() takes the str with the file and the n of tetriminos read.
 * Checks \n after each tetrimino.
 * Returns the string with the file.
 */

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

/*
 * check_tet() takes the str and the index we currently are.
 * It checks that only valid characters exist and \n are in place.
 * Returns the index where validate_format() can continue.
 */

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

char	*isolate_piece(char *file_str, int tetriminos)
{
	char	*piece;
	int		i;

	i = 0;
	piece = ft_strnew(16);
	file_str = file_str + ((tetriminos - 1) * 21);
	while (i < 16)
	{
		if (*file_str == '\n')
			file_str++;
		else
		{
			*piece = *file_str;
			file_str++;
			piece++;
			i++;
		}
	}
	piece = piece - 16;
//	ft_putstr(piece);
//	ft_putchar('\n');
	return (piece);
}
