/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:59:00 by dpalacio          #+#    #+#             */
/*   Updated: 2022/03/11 18:50:27 by dpalacio         ###   ########.fr       */
/*   Updated: 2022/03/07 12:29:37 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
  char		**file;
  int			i; //only for printing tests
  int			n_tetris;
  t_tetri		*tetri_array;
  u_int16_t	map_size;
  u_int16_t	map[13];

  i = 0;
  n_tetris = 0;
  map_size = 0;
  if (argc != 2)
    error(0);
  file = read_file(argv[1], &n_tetris);
  tetri_array = (t_tetri *)ft_memalloc(sizeof(t_tetri) * n_tetris + sizeof(t_tetri *));
  build_struct(n_tetris, file, str_to_int(file, n_tetris), tetri_array);
  map_size = ft_map_size(n_tetris);
//  map_gen(map, n_tetris);
  ft_init_map(map, map_size);
  printf("\nInitialized map\n");
  ft_print_bin_map(map);
  printf("\nPieces:\n");
  while (i < n_tetris)
    {
      ft_print_tetri_64(tetri_array[i]);
      printf("\n");
      i++;
    }
  //ft_print64(tetri_array[0].id_int64);
  //  printf("IN MAIN\n");
  while (map_size < 13)
    {
      if (ft_placealgo(map, tetri_array, n_tetris, map_size) == 1)
	{
	  //	  printf("\nSolved\n");
	  break;
	}
      else
	{
	  return(0);
	  //map_size++;
	  //ft_init_map(map, map_size);
	}
    }
  printf("\nMap after placealgo, map size is %d\n", map_size);
  ft_print_bin_map(map);
  printf("Coordinates of\nA: %d, %d\nB: %d, %d\nC: %d, %d\nD: %d, %d\n", tetri_array[0].pos_x, tetri_array[0].pos_y, tetri_array[1].pos_x, tetri_array[1].pos_y, tetri_array[2].pos_x, tetri_array[2].pos_y, tetri_array[3].pos_x, tetri_array[3].pos_y);
  //ft_print64(tetri_array[0].id_int64);
  ft_print_map(n_tetris, tetri_array, map_size);
  //  ft_putstr("It kinda works\n");
  return (0);
}
