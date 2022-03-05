
#include "fillit.h"
#include <stdio.h>
#include <stdlib.h>//libft strnew and memalloc
#include <string.h>//memset

void	ft_update_tetri(t_tetri *tetri, u_int16_t new_id)
{
  //  tetri.id_char = 'E';
  //  tetri.string = "1000100010001000";
  tetri->id_int = new_id;
  tetri->id_int0 = new_id & 61440;//F000
  tetri->id_int1 = (new_id & 3840) << 4;//F00
  tetri->id_int2 = (new_id & 240) << 8;//F0
  tetri->id_int3 = (new_id & 15) << 12;//F
  //  tetri.pos_x = 0;
  //  tetri.pos_y = 0;
}

//changed to print with tetris, not ints
void	ft_print_tetri(t_tetri tetri, u_int16_t bit_size)
{
  int i;

  i = bit_size - 1;
  while (i >= 0)
    {
      if (tetri.id_int & (1UL << i))
	printf("%c", tetri.id_char);
      else
	printf(".");
      if ((bit_size == 16) && (i % 4 == 0))
	printf("\n");
      i--;
    }
}

void	ft_print_tetri_16(t_tetri tetri)
{
  int i;

  i = 15;
  while (i >= 0)
    {
      if (tetri.id_int0 & (1UL << i))
	printf("%c", tetri.id_char);
      else
	printf(".");
      if (i % 16 == 0)
	printf("\n");
      i--;
    }
  i = 15;
  while (i >= 0)
    {
      if (tetri.id_int1 & (1UL << i))
	printf("%c", tetri.id_char);
      else
	printf(".");
      if (i % 16 == 0)
	printf("\n");
      i--;
    }
  i = 15;
  while (i >= 0)
    {
      if (tetri.id_int2 & (1UL << i))
	printf("%c", tetri.id_char);
      else
	printf(".");
      if (i % 16 == 0)
	printf("\n");
      i--;
    }
  i = 15;
  while (i >= 0)
    {
      if (tetri.id_int3 & (1UL << i))
	printf("%c", tetri.id_char);
      else
	printf(".");
      if (i % 16 == 0)
	printf("\n");
      i--;
    }
}

/*
int	main(void)
{

	pieceA = 61440;//1111000000000000;
	pieceB = 35008;//1000100011000000;
	pieceC = 52224;//1100110000000000;
	pieceD = 275;//0001000100110000;
	//pieceD = ft_move_piece(pieceD);
	//	pieceD = 4400;//0001000100110000;
	map = 0;
	//46, 71, 39, 275, not valid but good test 19


  //	t_tetri	A;
  t_tetri	E;

  
  A.id_char = 'A';
  A.string = "1111000000000000";
  A.id_int = 61440;
  A.id_int0 = A.id_int & 61440;//F000
  A.id_int1 = A.id_int & 3840;//F00
  A.id_int2 = A.id_int & 240;//F0
  A.id_int3 = A.id_int & 15;//F
  A.pos_x = 0;
  A.pos_y = 0;
  
  E.id_char = 'E';
  E.string = "1000100010001000";
  E.id_int = 34952;
  E.id_int0 = E.id_int & 61440;//F000
  E.id_int1 = E.id_int & 3840;//F00
  E.id_int2 = E.id_int & 240;//F0
  E.id_int3 = E.id_int & 15;//F
  E.pos_x = 0;
  E.pos_y = 0;

  //  ft_print_tetri(A, 16);
  ft_print_tetri(E, 16);

  printf("E.id_int is %d\n", E.id_int);
  printf("E.id_int0 is %d\n", E.id_int0);
  printf("E.id_int1 is %d\n", E.id_int1);
  printf("E.id_int2 is %d\n", E.id_int2);
  printf("E.id_int3 is %d\n\n", E.id_int3);
  //  ft_shift_line(&(E.id_int0), 4);
  //  printf("E.id_int0 is %d\n", E.id_int0);
  //  ft_print_tetri(E, 16);

  ft_update_tetri(&E, 17476);
  printf("E.id_int is %d\n", E.id_int);
  printf("E.id_int0 is %d\n", E.id_int0);
  printf("E.id_int1 is %d\n", E.id_int1);
  printf("E.id_int2 is %d\n", E.id_int2);
  printf("E.id_int3 is %d\n", E.id_int3);
  ft_print_tetri(E, 16);
  return (0);
}
*/
