/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 16:15:11 by murachid          #+#    #+#             */
/*   Updated: 2021/02/11 16:15:13 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"

void	ft_test(void)
{
	if (!check_wall(g_ply.nx, g_ply.ny))
	{
		g_ply.x = g_ply.nx;
		g_ply.y = g_ply.ny;
	}
}

void	ft_update(t_data *data)
{
	float	movestep;

	mlx_destroy_image(data->mlx, data->img);
	mlx_clear_window(data->mlx, data->mlx_win);
	data->img = mlx_new_image(data->mlx, data->width, data->height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
	&data->line_length, &data->endian);
	g_ply.nx = g_ply.x + g_ply.i * g_ply.movespeed *
	cos((PI / 2) - g_ply.rotationangle);
	g_ply.ny = g_ply.y + g_ply.j * g_ply.movespeed *
	sin((PI / 2) - g_ply.rotationangle);
	ft_test();
	g_ply.rotationangle += g_ply.turndirection * g_ply.rotationspeed;
	g_ply.rotationangle = normalizeangle(g_ply.rotationangle);
	movestep = g_ply.walkdirection * g_ply.movespeed;
	g_ply.nx = g_ply.x + movestep * cos(g_ply.rotationangle);
	g_ply.ny = g_ply.y + movestep * sin(g_ply.rotationangle);
	ft_test();
}

void	ft_key_relese(void)
{
	g_ply.turndirection = 0;
	g_ply.turndirection = 0;
	g_ply.walkdirection = 0;
	g_ply.walkdirection = 0;
	g_ply.i = 0;
	g_ply.j = 0;
}

void	ft_testt(int keycode)
{
	if (keycode == W)
		g_ply.walkdirection = 1;
	if (keycode == S)
		g_ply.walkdirection = -1;
	if (keycode == A)
	{
		g_ply.i = 1;
		g_ply.j = -1;
	}
	if (keycode == D)
	{
		g_ply.i = -1;
		g_ply.j = +1;
	}
}

int		ft_key_press(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit(0);
	}
	if (keycode == LEFT)
		g_ply.turndirection = -1;
	if (keycode == RIGHT)
		g_ply.turndirection = 1;
	ft_testt(keycode);
	ft_draw(data);
	ft_key_relese();
	return (0);
}
