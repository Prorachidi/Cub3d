/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_raycasting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:33:33 by murachid          #+#    #+#             */
/*   Updated: 2021/02/11 15:33:35 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"

void	function2(int i)
{
	float y_tocheck;

	while (g_verthorz.next_horz_touch_x >= 0 && g_verthorz.next_horz_touch_x
	<= (TILE_SIZE * g_data.horz) && g_verthorz.nexthorztouchy >=
	0 && g_verthorz.nexthorztouchy <= (TILE_SIZE * g_data.vert))
	{
		y_tocheck = g_verthorz.nexthorztouchy -
		(g_ray[i].israyfacingup ? 1 : 0);
		if (check_wall(g_verthorz.next_horz_touch_x, y_tocheck))
		{
			g_verthorz.foundhorzwallhit = 1;
			g_verthorz.horzwallhitx = g_verthorz.next_horz_touch_x;
			g_verthorz.horzwallhity = g_verthorz.nexthorztouchy;
			break ;
		}
		else
		{
			g_verthorz.next_horz_touch_x += g_verthorz.xstep;
			g_verthorz.nexthorztouchy += g_verthorz.ystep;
		}
	}
}

void	ft_vert(int i)
{
	g_verthorz.foundhorzwallhit = 0;
	g_verthorz.horzwallhitx = 0;
	g_verthorz.horzwallhity = 0;
	g_verthorz.yintercept = floorf(g_ply.y / (float)TILE_SIZE) * TILE_SIZE;
	g_verthorz.yintercept += g_ray[i].israyfacingdown ? TILE_SIZE : 0;
	g_verthorz.xintercept = g_ply.x + (g_verthorz.yintercept
	- g_ply.y) / tan(g_ray[i].angle);
	g_verthorz.ystep = TILE_SIZE;
	g_verthorz.ystep *= g_ray[i].israyfacingup ? -1 : 1;
	g_verthorz.xstep = TILE_SIZE / tan(g_ray[i].angle);
	g_verthorz.xstep *= (g_ray[i].israyfacingleft &&
	g_verthorz.xstep > 0) ? -1 : 1;
	g_verthorz.xstep *= (g_ray[i].israyfacingright &&
	g_verthorz.xstep < 0) ? -1 : 1;
	g_verthorz.next_horz_touch_x = g_verthorz.xintercept;
	g_verthorz.nexthorztouchy = g_verthorz.yintercept;
	function2(i);
}

void	function(int i)
{
	float	x_tocheck;

	while (g_verthorz.nextverttouchx >= 0 &&
	g_verthorz.nextverttouchx <= (TILE_SIZE * g_data.horz)
	&& g_verthorz.nextverttouchy >= 0 && g_verthorz.nextverttouchy
	<= (TILE_SIZE * g_data.vert))
	{
		x_tocheck = g_verthorz.nextverttouchx -
			(g_ray[i].israyfacingleft ? 1 : 0);
		if (check_wall(x_tocheck, g_verthorz.nextverttouchy))
		{
			g_verthorz.foundvertwallhit = 1;
			g_verthorz.vertwallhitx = g_verthorz.nextverttouchx;
			g_verthorz.vertwallhity = g_verthorz.nextverttouchy;
			break ;
		}
		else
		{
			g_verthorz.nextverttouchx += g_verthorz.xstep;
			g_verthorz.nextverttouchy += g_verthorz.ystep;
		}
	}
}

void	ft_hort(int i)
{
	g_verthorz.foundvertwallhit = 0;
	g_verthorz.vertwallhitx = 0;
	g_verthorz.vertwallhity = 0;
	g_verthorz.xintercept = floorf(g_ply.x / (float)TILE_SIZE) * TILE_SIZE;
	g_verthorz.xintercept += g_ray[i].israyfacingright ? TILE_SIZE : 0;
	g_verthorz.yintercept = g_ply.y +
	((g_verthorz.xintercept - g_ply.x) * tan(g_ray[i].angle));
	g_verthorz.xstep = TILE_SIZE;
	g_verthorz.xstep *= g_ray[i].israyfacingleft ? -1 : 1;
	g_verthorz.ystep = TILE_SIZE * tan(g_ray[i].angle);
	g_verthorz.ystep *= (g_ray[i].israyfacingup &&
	g_verthorz.ystep > 0) ? -1 : 1;
	g_verthorz.ystep *= (g_ray[i].israyfacingdown
	&& g_verthorz.ystep < 0) ? -1 : 1;
	g_verthorz.nextverttouchx = g_verthorz.xintercept;
	g_verthorz.nextverttouchy = g_verthorz.yintercept;
	function(i);
}

void	ft_check_distence(int i)
{
	if (g_verthorz.foundhorzwallhit == 1)
		g_verthorz.horzhitdistance = distancebetweenpoints(g_ply.x, g_ply.y,
		g_verthorz.horzwallhitx, g_verthorz.horzwallhity);
	else
		g_verthorz.horzhitdistance = INT_MAX;
	if (g_verthorz.foundvertwallhit == 1)
		g_verthorz.verthitdistance = distancebetweenpoints(g_ply.x,
		g_ply.y, g_verthorz.vertwallhitx, g_verthorz.vertwallhity);
	else
		g_verthorz.verthitdistance = INT_MAX;
	if (g_verthorz.horzhitdistance < g_verthorz.verthitdistance)
	{
		g_ray[i].wallhitx = g_verthorz.horzwallhitx;
		g_ray[i].wallhity = g_verthorz.horzwallhity;
		g_ray[i].distance = g_verthorz.horzhitdistance;
		g_ray[i].washitvertical = 0;
	}
	else
	{
		g_ray[i].wallhitx = g_verthorz.vertwallhitx;
		g_ray[i].wallhity = g_verthorz.vertwallhity;
		g_ray[i].washitvertical = 1;
		g_ray[i].distance = g_verthorz.verthitdistance;
	}
}
