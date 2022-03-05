
#include "fillit.h"

int	main(void)
{
  t_tetri	A;
  t_tetri	E;
  u_int16_t	map[13];
  u_int16_t	num_tetriminos = 2;//get from Daniel

  
  A.id_char = 'A';
  A.string = "1111000000000000";
  A.id_int = 61440;
  A.id_int0 = A.id_int & 61440;//F000
  A.id_int1 = (A.id_int & 3840) << 4;//F00
  A.id_int2 = (A.id_int & 240) << 8;//F0
  A.id_int3 = (A.id_int & 15) << 12;//F
  A.pos_x = 0;
  A.pos_y = 0;
  
  E.id_char = 'E';
  E.string = "1000100010001000";
  E.id_int = 34952;
  E.id_int0 = (E.id_int & 61440);//F000
  E.id_int1 = (E.id_int & 3840) << 4;//F00
  E.id_int2 = (E.id_int & 240) << 8;//F0
  E.id_int3 = (E.id_int & 15) << 12;//F
  E.pos_x = 0;
  E.pos_y = 0;
  
  ft_print_tetri(A, 16);
  ft_print_tetri(E, 16);
  
  //  u_int16_t	x = 0;
  ft_init_map(map, ft_map_size(num_tetriminos));
  printf("\nft_print_bin_map of desired size: %d\n\n", num_tetriminos);
  ft_print_bin_map(map);
  /*
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
  //  ft_print_tetri(E, 16);
  /*
  x = ft_collision_xy(map, E, 0, 0);
  printf("E.id_char is %c, collision_xy 0,0 should be 0 is %d\n", E.id_char, x);
  x = ft_collision_xy(map, E, 1, 0);
  printf("E.id_char is %c, collision_xy 1,0 should be 0 is %d\n", E.id_char, x);
  x = ft_collision_xy(map, E, 0, 1);
  printf("E.id_char is %c, collision_xy 0,1 should be 1 is %d\n\n", E.id_char, x);
  */
  //  printf("E.id_int0 is %d\n", E.id_int0);
  //  ft_shift_line(&(E.id_int0), 4);
  //  printf("E.id_int0 is %d\n", E.id_int0);
  //  ft_print_tetri(E, 16);

  printf("\nCollisions for A at y is expect : result\n");
  printf("Collision at 0 is 0 : %d\n", ft_tetri_collision_y(map, A, 0));
  printf("Collision at 1 is 0 : %d\n", ft_tetri_collision_y(map, A, 1));
  printf("Collision at 2 is 0 : %d\n", ft_tetri_collision_y(map, A, 2));
  printf("Collision at 3 is 0 : %d\n", ft_tetri_collision_y(map, A, 3));
  printf("Collision at 4 is 1 : %d\n", ft_tetri_collision_y(map, A, 4));
  printf("Collision at 12 is 1 : %d\n", ft_tetri_collision_y(map, A, 12));
  printf("Collision at 13 is 1 : %d\n", ft_tetri_collision_y(map, A, 13));
  printf("Collision at 14 is 1 : %d\n", ft_tetri_collision_y(map, A, 14));

  printf("E.id_int0-3 are %d, %d, %d, %d.\n", E.id_int0, E.id_int1, E.id_int2, E.id_int3);
  printf("\nCollisions for E at y is expect : result\n");
  printf("Collision at 0 is 0 : %d\n", ft_tetri_collision_y(map, E, 0));
  printf("Collision at 1 is 1 : %d\n", ft_tetri_collision_y(map, E, 1));
  printf("Collision at 2 is 1 : %d\n", ft_tetri_collision_y(map, E, 2));
  printf("Collision at 3 is 1 : %d\n", ft_tetri_collision_y(map, E, 3));
  printf("Collision at 4 is 1 : %d\n", ft_tetri_collision_y(map, E, 4));
  printf("Collision at 12 is 1 : %d\n", ft_tetri_collision_y(map, E, 12));
  printf("Collision at 13 is 1 : %d\n", ft_tetri_collision_y(map, E, 13));
  printf("Collision at 14 is 1 : %d\n", ft_tetri_collision_y(map, E, 14));

  printf("\nCollisions for E at x,y is expect : result\n");
  
  printf("Collision at 0,0 is 0 : %d\n", ft_collision_xy(map, E, 0, 0));
  printf("Collision at 1,0 is 0 : %d\n", ft_collision_xy(map, E, 1, 0));
  printf("Collision at 2,0 is 0 : %d\n", ft_collision_xy(map, E, 2, 0));
  
  printf("Collision at 3,0 is 0 : %d\n", ft_collision_xy(map, E, 3, 0));
  printf("Collision at 4,0 is 1 : %d\n", ft_collision_xy(map, E, 4, 0));
  
  printf("Collision at 0,1 is 1 : %d\n", ft_collision_xy(map, E, 0, 1));
  printf("Collision at 1,1 is 1 : %d\n", ft_collision_xy(map, E, 1, 1));
  printf("Collision at 4,1 is 1 : %d\n", ft_collision_xy(map, E, 4, 1));
  printf("Collision at 2 is 1 : %d\n", ft_tetri_collision_y(map, E, 2));
  printf("Collision at 3 is 1 : %d\n", ft_tetri_collision_y(map, E, 3));
  printf("Collision at 4 is 1 : %d\n", ft_tetri_collision_y(map, E, 4));
  printf("Collision at 12 is 1 : %d\n", ft_tetri_collision_y(map, E, 12));
  printf("Collision at 12,12 is 1 : %d\n", ft_collision_xy(map, E, 12, 12));
  printf("Collision at 13 is 1 : %d\n", ft_tetri_collision_y(map, E, 13));
  printf("Collision at 14 is 1 : %d\n", ft_tetri_collision_y(map, E, 14));
  
  return (0);
}
