/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 12:36:08 by murachid          #+#    #+#             */
/*   Updated: 2021/02/24 12:36:10 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"

void	ft_squart_wall_down(t_data *data, int x, int y, int tile_down)
{
	int i;
	int j;

	i = x;
	while (i < x + 1)
	{
		j = y;
		while (j < y + tile_down)
		{
			my_mlx_pixel_put(data, i, j, g_color.f);
			j++;
		}
		i++;
	}
}

void	ft_squart_wall_up(t_data *data, int i, int tile_up)
{
	int j;

	j = 0;
	while (j < tile_up)
	{
		my_mlx_pixel_put(data, i, j, g_color.c);
		j++;
	}
}

void	ft_squart_wall(t_data *data, int x)
{
	int	distancefromtop;
	int	textureffsety;
	int	y;

	y = g_cube.walltoppixel;
	while (y < g_cube.wallbottompixel)
	{
		distancefromtop = y + (g_cube.wallstripheight
		/ 2) - (g_data.h / 2);
		textureffsety = distancefromtop *
		((float)TEXTURE_HEIGHT /
		g_cube.wallstripheight);
		function_diretion(data, x, y, textureffsety);
		y++;
	}
}

void	render3dprojectedwalls(t_data *data, int i)
{
	g_cube.perpdistance = g_ray[i].distance *
	cos(g_ray[i].angle - g_ply.rotationangle);
	g_cube.distanceprojplane = ((g_data.w) / 2) / tan(FOV_ANGLE / 2);
	g_cube.projectedwallheight = (TILE_SIZE /
	g_cube.perpdistance) * g_cube.distanceprojplane;
	g_cube.wallstripheight = (int)g_cube.projectedwallheight;
	g_cube.walltoppixel = (g_data.h / 2) - (g_cube.wallstripheight / 2);
	g_cube.walltoppixel = g_cube.walltoppixel < 0 ? 0 : g_cube.walltoppixel;
	g_cube.wallbottompixel = (g_data.h / 2) + (g_cube.wallstripheight / 2);
	g_cube.wallbottompixel = g_cube.wallbottompixel >
	g_data.h ? g_data.h : g_cube.wallbottompixel;
	if (g_ray[i].washitvertical)
		g_cube.textureoffsetx = (int)g_ray[i].wallhity % TILE_SIZE;
	else
		g_cube.textureoffsetx = (int)g_ray[i].wallhitx % TILE_SIZE;
	ft_squart_wall(data, i);
	ft_squart_wall_up(data, i, g_cube.walltoppixel);
	ft_squart_wall_down(data, i, g_cube.wallbottompixel,
	(g_data.h - g_cube.wallbottompixel));
}
