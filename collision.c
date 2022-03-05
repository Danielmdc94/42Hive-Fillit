
#include "fillit.h"
#include <stdio.h>
#include <stdlib.h>//libft strnew and memalloc
#include <string.h>//memset

/*
//moves piece x. OLD
u_int16_t	ft_shift_piece_x(t_tetri piece, u_int16_t x)
{
  while (x > 0)
    {
      if (piece & 4369)//0001000100010001
	return (1);
      piece = piece >> 1;
      x--;
    }
  return (1);
}
*/

//works
u_int16_t	ft_line_collision(u_int16_t map_line, u_int16_t tetri_line)
{
  if (map_line & tetri_line)
    return (1);
  return (0);//no collision
}

//works
u_int16_t	ft_tetri_collision_y(u_int16_t *map, t_tetri tetri, u_int16_t pos_y)
{
  if (ft_line_collision(map[pos_y], tetri.id_int0) || ft_line_collision(map[(pos_y + 1)], tetri.id_int1) || ft_line_collision(map[pos_y + 2], tetri.id_int2) || ft_line_collision(map[pos_y + 3], tetri.id_int3))
    return (1);
  return (0);
}

//NOT WORKING
//moves piece as many positions as x says
//ret: 0 if no shift, 1 if shift
u_int16_t	ft_shift_line(u_int16_t *tetri_line, u_int16_t x)
{
  u_int16_t	temp;

  temp = *tetri_line;
  if (x > 0)
    {
      temp = temp >> x;
      if ((temp & 4095))//0000 1111 1111 1111
	return (0);
    }
  *tetri_line = temp;
  //  printf("tetri_line %d\n", *tetri_line);
  return (1);
}

/*compiler complain
u_int16_t	ft_shift_piece_x(u_int16_t *tetri, u_int16_t x)
{
  //  u_int16_t	*temp;

  //  temp = *tetri_line;
  if ((tetri.id_int & 4369) == 0)//0001000100010001
  if (ft_shift_line(tetri.id_int0, x) && ft_shift_line(tetri.id_int1, x) && ft_shift_line(tetri.id_int2, x) && ft_shift_line(tetri.id_int3, x))
    {
      temp = temp >> x;
      if ((temp & 4095))//0000 1111 1111 1111
	return (0);
    }
  *tetri_line = temp;
  printf("tetri_line %d\n", *tetri_line);
  return (1);
}
*/

u_int16_t	ft_collision_xy(u_int16_t *map, t_tetri tetri, u_int16_t pos_x, u_int16_t pos_y)
{
  //  u_int16_t	x;
  //  u_int16_t	y;
  /*  t_tetri	temp;//tetri

  temp.id_char = tetri.id_char;
  temp.string = strdup(tetri.string);
  temp.id_int = tetri.id_int;
  temp.id_int0 = tetri.id_int0;
  temp.id_int1 = tetri.id_int1;
  temp.id_int2 = tetri.id_int2;
  temp.id_int3 = tetri.id_int3;
  temp.pos_x = tetri.pos_x;
  temp.pos_y = tetri.pos_y;*/
  //  temp_piece = ft_shift_piece(tetri->id_int, pos_x, 0);
  /*  if (ft_tetri_collision_y(map, temp, pos_y))
    {
      free(temp.string);
      return (1);
    }
    free(temp.string);*/
  //  ft_print_tetri_16(tetri);
  if (pos_x > 0)
    {
      tetri.id_int0 = (tetri.id_int0 >> pos_x);
      tetri.id_int1 = (tetri.id_int1 >> pos_x);
      tetri.id_int2 = (tetri.id_int2 >> pos_x);
      tetri.id_int3 = (tetri.id_int3 >> pos_x);
      //      ft_print_tetri_16(tetri);
    }
  if (ft_tetri_collision_y(map, tetri, pos_y) == 0)
    return (0);
  return (1);
}

/*
int	main(void)
{
  //	t_tetri	A;
  t_tetri	E;
  u_int16_t	map[13];
  u_int16_t	num_tetriminos;//get from Daniel

  num_tetriminos = 2;
*/
  /*
  A.id_char = 'A';
  A.string = "1111000000000000";
  A.id_int = 61440;
  A.id_int0 = A.id_int & 61440;//F000
  A.id_int1 = A.id_int & 3840;//F00
  A.id_int2 = A.id_int & 240;//F0
  A.id_int3 = A.id_int & 15;//F
  A.pos_x = 0;
  A.pos_y = 0;
  */
/*
  E.id_char = 'E';
  E.string = "1000100010001000";
  E.id_int = 34952;
  E.id_int0 = E.id_int & 61440;//F000
  E.id_int1 = E.id_int & 3840;//F00
  E.id_int2 = E.id_int & 240;//F0
  E.id_int3 = E.id_int & 15;//F
  E.pos_x = 0;
  E.pos_y = 0;
*/
  /*
  ft_print_tetri(A, 16);
  u_int16_t	x = 0;
  ft_init_map(map, ft_map_size(num_tetriminos));
  printf("\nft_print_bin_map of desired size\n\n");
  ft_print_bin_map(map);
  x = ft_line_collision(map[0], A.id_int0);
  printf("line collision map0 A0 should be 0, is: %d\n", x);
  x = ft_line_collision(map[1], A.id_int1);
  printf("line collision map1 A1 should be 0, is: %d\n", x);
  x = ft_line_collision(map[2], A.id_int2);
  printf("line collision map2 A2 should be 0, is: %d\n", x);
  x = ft_line_collision(map[3], A.id_int3);
  printf("line collision map3 A3 should be 0, is: %d\n", x);
  x = ft_line_collision(map[4], A.id_int0);
  printf("line collision map4 A0 should be 1, is: %d\n", x);
  x = ft_line_collision(map[4], A.id_int1);
  printf("line collision map4 A1 should be 0, is: %d\n", x);

  x = 3;
  printf("\nx reset to 3, x is: %d\n", x);

  x = ft_tetri_collision_y(map, A, 1);
  printf("\nSo tetri_collision map A, pos_y = 1 should be 0, is: %d\n", x);
  x = ft_tetri_collision_y(map, A, 4);
  printf("\nSo tetri_collision map A, pos_y = 4 should be 1, is: %d\n", x);
  x = ft_collision_xy(map, A, 0, 0);
  printf("A.id_char is %c, collision_xy 0,0 should be 0 is %d\n", A.id_char, x);
  x = ft_collision_xy(map, A, 1, 0);
  printf("A.id_char is %c, collision_xy 1,0 should be 1 is %d\n", A.id_char, x);
  x = ft_collision_xy(map, A, 0, 1);
  printf("A.id_char is %c, collision_xy 0,1 should be 0 is %d\n", A.id_char, x);
  x = ft_collision_xy(map, A, 0, 4);
  printf("A.id_char is %c, collision_xy 0,4 should be 1 is %d\n\n", A.id_char, x);
  */

//ft_print_tetri(E, 16);

/*
  x = ft_collision_xy(map, E, 0, 0);
  printf("E.id_char is %c, collision_xy 0,0 should be 0 is %d\n", E.id_char, x);
  x = ft_collision_xy(map, E, 1, 0);
  printf("E.id_char is %c, collision_xy 1,0 should be 0 is %d\n", E.id_char, x);
  x = ft_collision_xy(map, E, 0, 1);
  printf("E.id_char is %c, collision_xy 0,1 should be 1 is %d\n\n", E.id_char, x);
  */
/*
  printf("E.id_int0 is %d\n", E.id_int0);
  ft_shift_line(&(E.id_int0), 4);
  printf("E.id_int0 is %d\n", E.id_int0);
  ft_print_tetri(E, 16);
  
  return (0);
}
*/
