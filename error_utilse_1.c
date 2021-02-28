/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utilse_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 12:20:02 by murachid          #+#    #+#             */
/*   Updated: 2021/02/23 12:20:03 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"

void	all_errors(void)
{
	error_one();
	error_three();
	error_other();
	error_six();
	error_five();
}

void	error_five_1(int a, int i, int b)
{
	while (g_data.map[i][a] != '\0')
	{
		espace_2(a, i, b);
		if ((g_data.map[i + 1] != NULL &&
		g_data.map[i + 1][a] == 0)
		&& (g_data.map[i][a] == '0' ||
		g_data.map[i][a] == g_ply.pos
		|| g_data.map[i][a] == '2'))
			error_msg();
		if (g_data.map[i] != NULL &&
		g_data.map[i - b][a] == 0
		&& (g_data.map[i][a] == '0'
		|| g_data.map[i][a] == g_ply.pos
		|| g_data.map[i][a] == '2'))
			error_msg();
		a++;
	}
}

void	error_six_1(int a, int i)
{
	while (g_data.map[i][a] != '\0')
	{
		espac(a, i);
		if ((g_data.map[i][a] == '0' &&
		g_data.map[i][a + 1] == 0) ||
		(g_data.map[i][a] == '2' &&
		g_data.map[i][a + 1] == 0)
		|| (g_data.map[i][a] == g_ply.pos &&
		g_data.map[i][a + 1] == 0))
			error_msg();
		if ((g_data.map[i][a] == '0' &&
		g_data.map[i][a - 1] == 0) ||
		(g_data.map[i][a] == '2' &&
		g_data.map[i][a - 1] == 0)
		|| (g_data.map[i][a] == g_ply.pos
		&& g_data.map[i][a - 1] == 0))
			error_msg();
		a++;
	}
}
