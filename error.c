/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 12:00:10 by murachid          #+#    #+#             */
/*   Updated: 2021/02/23 12:00:11 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"

void	error_six(void)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (g_data.map[i] != NULL)
	{
		error_six_1(a, i);
		i++;
		a = 0;
	}
}

void	error_five(void)
{
	int i;
	int a;
	int b;

	a = 0;
	i = 0;
	b = 0;
	while (g_data.map[i] != NULL)
	{
		error_five_1(a, i, b);
		b = 1;
		a = 0;
		i++;
	}
}

void	error_other(void)
{
	int i;
	int a;

	i = 0;
	a = 0;
	while (g_data.map[i] != NULL)
	{
		while (g_data.map[i][a] != '\0')
		{
			if (g_data.map[i][a] != ' ' && g_data.map[i][a] != '1'
			&& g_data.map[i][a] != '0'
			&& g_data.map[i][a] != '2' && g_data.map[i][a] != 'N'
			&& g_data.map[i][a] != 'S'
			&& g_data.map[i][a] != 'W' && g_data.map[i][a] != 'E')
			{
				printf("Error\n Wrong Character in map");
				exit(1);
			}
			a++;
		}
		a = 0;
		i++;
	}
}

void	error_one(void)
{
	int i;

	i = 0;
	while (g_data.map[0][i] != '\0')
	{
		if (g_data.map[0][i] != '1' && g_data.map[0][i] != 32)
			error_msg();
		i++;
	}
	i = 0;
	while (g_data.map[g_data.vert - 1][i] != '\0')
	{
		if (g_data.map[g_data.vert - 1][i] != '1'
		&& g_data.map[g_data.vert - 1][i] != 32)
			error_msg();
		i++;
	}
	if (g_check_color.res > 1 || g_check_color.north > 1
	|| g_check_color.sprite > 1 || g_check_color.east > 1
	|| g_check_color.west > 1 || g_check_color.south > 1
	|| g_check_color.floor > 1 || g_check_color.ceilling > 1)
	{
		printf("Error\nDuplicate Settings");
		exit(1);
	}
}

void	error_three(void)
{
	int i;
	int a;

	i = 0;
	a = 0;
	while (g_data.map[i] != NULL)
	{
		if (g_data.map[i][a] == 32)
		{
			while (g_data.map[i][a] == 32)
				a++;
		}
		if (g_data.map[i][a] != '1')
		{
			if (g_data.map[i][a] == '\0')
				error_msg();
			printf("Error\nFirst Col doesn't start with 1");
			exit(-1);
		}
		i++;
		a = 0;
	}
}
