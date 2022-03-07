/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:41:26 by dpalacio          #+#    #+#             */
/*   Updated: 2022/03/07 17:38:00 by acastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	valid_tet(uint16_t tetri_id);

void	build_struct(int n_tet, char **file,
		uint16_t *piece_id, t_tetri *tetri)
{
	int	i;

	i = 0;
	while (i < n_tet)
	{
		(*tetri).id_int = *piece_id;
		(*tetri).id_int0 = *piece_id & 61440;
		(*tetri).id_int1 = (*piece_id << 4) & 61440;
		(*tetri).id_int2 = (*piece_id << 8) & 61440;
		(*tetri).id_int3 = (*piece_id << 12) & 61440;
		(*tetri).string = file[i];
		(*tetri).id_char = 'A' + i;
		valid_tet((*tetri).id_int);
		piece_id++;
		tetri++;
		i++;
	}
}

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

void	valid_tet(uint16_t tetri_id)
{
	int				i;
	static uint16_t	valid_tet[19] = {8800, 11776, 19520, 19584, 19968,
		27648, 34952, 35008, 35904, 35968, 36352, 50240,
		50688, 51328, 52224, 57856, 58368, 59392, 61440};

	i = 0;
	while (i < 19)
	{
		if (valid_tet[i] == tetri_id)
			break ;
		i++;
	}
	if (valid_tet[i] != tetri_id)
		error(0);
}

//changed to print with tetris, not ints
void	ft_print_tetri(t_tetri tetri, u_int16_t bit_size)//TO DO: erase
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

void	ft_print_tetri_16(t_tetri tetri)//TO DO: erase
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
