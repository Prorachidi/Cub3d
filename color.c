/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:26:40 by murachid          #+#    #+#             */
/*   Updated: 2021/02/11 15:26:51 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"

void	color_green(char **tab, int b, int i, int ab)
{
	char	*s;

	s = ft_substr(tab[ab], b, i);
	if (!ft_all_digit(s))
		error_color_masseg();
	g_color.g = ft_atoi(s);
	free(s);
}

int		space_color(char **tab, int i)
{
	int		a;

	a = 1;
	if (tab[i][1] != ' ')
	{
		printf("Error\nin color");
		exit(1);
	}
	while (tab[i][a] == ' ')
		a++;
	if (tab[i][a] < 48 || tab[i][a] > 57)
	{
		printf("Error\nEmpty Settings");
		exit(1);
	}
	return (a);
}

void	color_red(char **tab, int b, int i, int ab)
{
	char	*s;

	s = ft_substr(tab[ab], b, i);
	if (!ft_all_digit(s))
		error_color_masseg();
	g_color.r = ft_atoi(s);
	free(s);
}

void	fi(int a, int i1, char **tab)
{
	int		i;
	int		b;

	i = 0;
	b = a;
	while (tab[i1][a] != ',')
	{
		i++;
		a++;
	}
	color_red(tab, b, i, i1);
	b = a + 1;
	a++;
	i = 0;
	while (tab[i1][a] != ',')
	{
		i++;
		a++;
	}
	color_green(tab, b, i, i1);
	fonction(i1, a, tab);
}

int		color(char **tab, int i1)
{
	int		a;

	a = space_color(tab, i1);
	fi(a, i1, tab);
	return (g_color.bb + g_color.g * 256 + g_color.r * 65536);
}
