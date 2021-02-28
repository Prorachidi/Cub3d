/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Building_3D.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:46:32 by murachid          #+#    #+#             */
/*   Updated: 2021/02/11 15:46:35 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"

int		direction(int i)
{
	int		nb;

	nb = 0;
	if (g_ray[i].washitvertical == 1)
	{
		if (g_ray[i].israyfacingleft == 1)
			nb = 0;
		if (g_ray[i].israyfacingright == 1)
			nb = 1;
	}
	if (g_ray[i].washitvertical == 0)
	{
		if (g_ray[i].israyfacingup == 1)
			nb = 2;
		if (g_ray[i].israyfacingdown == 1)
			nb = 3;
	}
	return (nb);
}

void	function_diretion(t_data *data, int x, int y, int textureffsety)
{
	int	texelcolor;

	if (direction(x) == 0)
		texelcolor = g_texture.data[0][(TEXTURE_WIDTH *
		textureffsety) + g_cube.textureoffsetx];
	if (direction(x) == 1)
		texelcolor = g_texture.data[1][(TEXTURE_WIDTH *
		textureffsety) + g_cube.textureoffsetx];
	if (direction(x) == 2)
		texelcolor = g_texture.data[2][(TEXTURE_WIDTH *
		textureffsety) + g_cube.textureoffsetx];
	if (direction(x) == 3)
		texelcolor = g_texture.data[3][(TEXTURE_WIDTH *
		textureffsety) + g_cube.textureoffsetx];
	my_mlx_pixel_put(data, x, y, texelcolor);
}
