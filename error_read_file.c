/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_read_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:49:45 by murachid          #+#    #+#             */
/*   Updated: 2021/02/25 16:49:48 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"

void		ft_error_1(char **tab)
{
	int i;
	int j;

	i = 0;
	while (tab[i] != NULL)
	{
		j = 0;
		while (tab[i][j] == ' ')
			j++;
		if (tab[i][j] != '1' && tab[i][j] != 'R' &&
		tab[i][j] != '\0' && tab[i][j] != 'F'
		&& tab[i][j] != 'C'
		&& tab[i][j] != 'S' && (tab[i][j] != 'W' &&
		tab[i][j + 1] != 'E') && (tab[i][j] != 'E'
		&& tab[i][j + 1] != 'A') && (tab[i][j] != 'S' &&
		tab[i][j + 1] != 'O')
		&& (tab[i][j] != 'N' && tab[i][j + 1] != 'O'))
		{
			printf("Error\ncharacter not in setting");
			exit(1);
		}
		i++;
	}
}

void		ft_error_(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
	{
		if (tab[i][0] == 'R' || tab[i][0] == 'F' ||
		tab[i][0] == 'C' || tab[i][0] == 'S'
		|| (tab[i][0] == 'W' && tab[i][1] == 'E') ||
		(tab[i][0] == 'E' && tab[i][1] == 'A') ||
		(tab[i][0] == 'S' && tab[i][1] == 'O') ||
		(tab[i][0] == 'N' && tab[i][1] == 'O'))
		{
			g_check_color.set++;
		}
		i++;
	}
}
