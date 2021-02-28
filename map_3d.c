/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:27:43 by murachid          #+#    #+#             */
/*   Updated: 2021/02/11 15:27:45 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"

void	array_map1(char **tab, int x, int i)
{
	while (tab[x] != NULL)
	{
		i = 0;
		while (tab[x][i] != '\0')
			i++;
		if (i > g_data.horz)
			g_data.horz = i;
		x++;
	}
}

int		array_map(char **tab, int ab, int aa)
{
	int		plus_c;
	int		i;
	int		x;

	if (aa == 1)
		return (1);
	g_data.mapstart = ab;
	i = 0;
	plus_c = ab;
	while (tab[plus_c] != NULL)
		plus_c++;
	plus_c = plus_c - ab;
	g_data.vert = plus_c;
	if (!(g_data.map = malloc((plus_c + 1) * sizeof(char *))))
		return (0);
	g_data.map[plus_c] = NULL;
	x = ab;
	array_map1(tab, x, i);
	i = 0;
	while (i < plus_c)
	{
		if (!(g_data.map[i++] = ft_calloc((g_data.horz + 1), sizeof(char))))
			return (0);
	}
	return (1);
}
