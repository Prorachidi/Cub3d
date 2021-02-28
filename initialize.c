/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 16:08:41 by murachid          #+#    #+#             */
/*   Updated: 2021/02/11 16:08:43 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"

void	ft_initialize_player(void)
{
	check_map();
	g_ply.rotationspeed = PI / 20;
	g_ply.movespeed = 20;
	g_ply.turndirection = 0;
	g_ply.walkdirection = 0;
	g_ply.nx = 0;
	g_ply.ny = 0;
	if (g_data.w > WIN_WMAX)
		g_data.w = WIN_WMAX;
	if (g_data.h > WIN_HMAX)
		g_data.h = WIN_HMAX;
	if (g_data.h < 0 || g_data.w < 0)
	{
		printf("Error\nin resolution");
		exit(1);
	}
}

void	ft_initialize_ray(int i)
{
	g_ray[i].angle = normalizeangle(g_ray[i].angle);
	g_ray[i].israyfacingdown = g_ray[i].angle > 0 && g_ray[i].angle < PI;
	g_ray[i].israyfacingup = !g_ray[i].israyfacingdown;
	g_ray[i].israyfacingright = g_ray[i].angle < (PI / 2)
	|| g_ray[i].angle > 1.5 * PI;
	g_ray[i].israyfacingleft = !g_ray[i].israyfacingright;
}
