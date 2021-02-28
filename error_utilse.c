/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utilse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:58:58 by murachid          #+#    #+#             */
/*   Updated: 2021/02/23 11:59:02 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"

int		ft_all_digit(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	array_free(char **tab)
{
	int ab;

	ab = 0;
	while (tab[ab] != NULL)
	{
		free(tab[ab]);
		ab++;
	}
	free(tab);
}

void	espac(int a, int i)
{
	if ((g_data.map[i][a] == '0'
	&& g_data.map[i][a + 1] == 32) ||
	(g_data.map[i][a] == '2'
	&& g_data.map[i][a + 1] == 32)
	|| (g_data.map[i][a] == g_ply.pos
	&& g_data.map[i][a + 1] == 32))
		error_msg();
	if ((g_data.map[i][a] == '0'
	&& g_data.map[i][a - 1] == 32) ||
	(g_data.map[i][a] == '2'
	&& g_data.map[i][a - 1] == 32)
	|| (g_data.map[i][a] == g_ply.pos
	&& g_data.map[i][a - 1] == 32))
		error_msg();
}

void	espace_2(int a, int i, int b)
{
	if ((g_data.map[i + 1] != NULL
	&& g_data.map[i + 1][a] == 32)
	&& (g_data.map[i][a] == '0' ||
	g_data.map[i][a] == g_ply.pos
	|| g_data.map[i][a] == '2'))
		error_msg();
	if (g_data.map[i] != NULL
	&& g_data.map[i - b][a] == 32
	&& (g_data.map[i][a] == '0'
	|| g_data.map[i][a] == g_ply.pos
	|| g_data.map[i][a] == '2'))
		error_msg();
}

void	open_txt(char *txt)
{
	int fd;

	fd = open(txt, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nTexture cannot be found");
		exit(-1);
	}
	close(fd);
}
