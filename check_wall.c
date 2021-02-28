/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 16:12:52 by murachid          #+#    #+#             */
/*   Updated: 2021/02/11 16:12:55 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"

int	check_wall(float x, float y)
{
	int mapx;
	int mapy;

	mapx = (int)floor(x / TILE_SIZE);
	mapy = (int)floor(y / TILE_SIZE);
	if (mapx >= 0 && mapy >= 0 && mapy
	< g_data.vert && mapx < len(g_data.map[mapy]))
	{
		if (g_data.map[mapy][mapx] == '1' || g_data.map[mapy][mapx] == ' ')
			return (1);
	}
	return (0);
}
