/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_Map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 16:07:28 by murachid          #+#    #+#             */
/*   Updated: 2021/02/11 16:07:31 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"

void	checkpathvalid(char *s1)
{
	int fd;

	fd = open(s1, O_RDONLY);
	if (fd == -1)
	{
		printf("path not valid");
		exit(1);
	}
}

void	player_int(int i, int j)
{
	if (g_data.map[i][j] == 'N')
		g_ply.pos = 'N';
	else if (g_data.map[i][j] == 'W')
		g_ply.pos = 'W';
	else if (g_data.map[i][j] == 'S')
		g_ply.pos = 'S';
	else if (g_data.map[i][j] == 'E')
		g_ply.pos = 'E';
}

void	check_map2(int i, int j, double tile_i, double tile_j)
{
	if (g_data.map[i][j] == 'N' | g_data.map[i][j] == 'W'
	|| g_data.map[i][j] == 'S' || g_data.map[i][j] == 'E')
	{
		player_int(i, j);
		if (g_data.map[i][j] == '2')
			g_nsprite++;
		g_ply.found_player++;
		if (g_data.map[i][j] == 'N')
			g_ply.rotationangle = (1.5 * PI);
		else if (g_data.map[i][j] == 'W')
			g_ply.rotationangle = PI;
		else if (g_data.map[i][j] == 'S')
			g_ply.rotationangle = (PI / 2);
		else if (g_data.map[i][j] == 'E')
			g_ply.rotationangle = 0;
		g_ply.y = tile_i;
		g_ply.x = tile_j;
	}
	else if (g_data.map[i][j] == '2')
		g_nsprite++;
}

void	check_map(void)
{
	int		i;
	int		j;
	double	tile_i;
	double	tile_j;

	j = 0;
	i = 0;
	while (i < g_data.vert)
	{
		while (j < g_data.horz)
		{
			tile_i = ((double)i + 0.5) * TILE_SIZE;
			tile_j = ((double)j + 0.5) * TILE_SIZE;
			check_map2(i, j, tile_i, tile_j);
			j++;
		}
		j = 0;
		i++;
	}
	if (g_ply.found_player != 1)
	{
		printf("error\nplayer");
		exit(1);
	}
}
