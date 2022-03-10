/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:48:28 by dpalacio          #+#    #+#             */
/*   Updated: 2022/03/10 13:42:47 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*validate_format(char *file, int tetriminos);
static int	check_tet(char *file_str, int i);
static char	**store_pieces(char *file_str, int tetriminos);
static char	*isolate_piece(char *file_str, int tetriminos);

/*
 * read_file() takes the file's name given to the program.
 * Opens the file, reads it and checks everything is correct(except piece)
 * Returns the string containing the file once it has been validated.
 */

char	**read_file(char *file, int *n_tet)
{
	int		fd;
	ssize_t	r_bytes;
	int		tetriminos;
	char	buff[547];
	char	*file_str;

	fd = open(file, O_RDONLY);
	r_bytes = read(fd, buff, 547);
	if (fd == -1 || r_bytes < 0)
		error(1);
	close(fd);
	buff[r_bytes] = '\0';
	if ((r_bytes + 1) % 21 != 0 || r_bytes == 0)
		error(2);
	tetriminos = (r_bytes + 1) / 21;
	*n_tet = tetriminos;
	file_str = ft_strdup(buff);
	validate_format(file_str, tetriminos);
	return (store_pieces(file_str, tetriminos));
}

/*
 * validate_format() takes the str with the file and the n of tetriminos read.
 * Checks \n after each tetrimino.
 * Returns the string with the file.
 */

static char	*validate_format(char *file_str, int tetriminos)
{
	int	i;

	i = 0;
	while (file_str[i] != '\0' && tetriminos > 0)
	{
		i = check_tet(file_str, i);
		if (file_str[i] != '\n' && file_str[i] != '\0')
			error(3);
		tetriminos--;
		i++;
	}
	return (file_str);
}

/*
 * check_tet() takes the str and the index we currently are in.
 * It checks that only valid characters exist and \n are in place.
 * Returns the index where validate_format() can continue.
 */

static int	check_tet(char *file_str, int i)
{
	int	lines;
	int	columns;

	lines = 0;
	columns = 0;
	while (lines < 4)
	{
		while (columns < 4)
		{
			if (file_str[i] != '.' && file_str[i] != '#')
				error(4);
			columns++;
			i++;
		}
		if (file_str[i] != '\n')
			error(5);
		columns = 0;
		i++;
		lines++;
	}
	return (i);
}

/*
 * store_pieces() takes the str that holds the file and the number of tetriminos.
 * It stores each piece individually in an array of str.
 * Returns said array.
 */

static char	**store_pieces(char *file_str, int tetriminos)
{
	char	**file_pieces;

	file_pieces = (char **)ft_memalloc((sizeof(char *)) * tetriminos + 1);
	while (tetriminos > 0)
	{
		file_pieces[tetriminos - 1] = isolate_piece(file_str, tetriminos);
		tetriminos--;
	}
	return (file_pieces);
}

/*
 * isolate_pieces() takes the str that holds the file and the No of tetriminos.
 * It creates a str for the current array element in store_pieces.
 * Returns said str.
 */

static char	*isolate_piece(char *file_str, int tetriminos)
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
			if (*file_str == '.')
				*piece = '0';
			if (*file_str == '#')
				*piece = '1';
			file_str++;
			piece++;
			i++;
		}
	}
	piece = piece - 16;
	return (piece);
}
