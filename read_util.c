/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 17:10:09 by murachid          #+#    #+#             */
/*   Updated: 2021/02/25 17:10:11 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"

void	read_map_util(char **tab)
{
	int	a;
	int	i;
	int	b;

	a = g_data.mapstart;
	b = 0;
	i = 0;
	while (tab[a] != NULL)
	{
		if (tab[a][0] == '\0')
			error_msg();
		while (tab[a][i] != '\0')
		{
			g_data.map[b][i] = tab[a][i];
			i++;
		}
		while (i < g_data.horz)
		{
			g_data.map[b][i++] = ' ';
		}
		g_data.map[b][i] = 0;
		a++;
		b++;
		i = 0;
	}
}

void	read_map(char **tab)
{
	ft_error_1(tab);
	ft_error_(tab);
	if (g_check_color.set != 8)
	{
		printf("Error\nsome missing settings");
		exit(1);
	}
	read_map_util(tab);
}

void	check_cub_utile1(char **tab, int i)
{
	if (tab[i][0] == 'R')
	{
		ft_resolution(tab, i);
		g_check_color.res++;
	}
	if (tab[i][0] == 'F')
	{
		g_color.f = color(tab, i);
		g_check_color.floor++;
	}
	else if (tab[i][0] == 'C')
	{
		g_color.c = color(tab, i);
		g_check_color.ceilling++;
	}
}

void	check_cub_y(char **tab, int i)
{
	int	c;
	int	j;

	c = 0;
	j = 0;
	while (tab[i] != NULL)
	{
		check_cub_utile1(tab, i);
		test_texture(tab, i);
		while (tab[i][c] == ' ')
		{
			c++;
			if (tab[i][c] == '1' || tab[i][c] == ' ')
				j = array_map(tab, i, j);
			if (tab[i][c] != '1' && tab[i][c] != ' ')
			{
				c = 0;
				break ;
			}
		}
		if (tab[i][c] == '1' || tab[i][c] == ' ')
			j = array_map(tab, i, j);
		i++;
	}
}

char	**check_cub(char **tab)
{
	int	i;

	i = 0;
	check_cub_y(tab, i);
	return (tab);
}
