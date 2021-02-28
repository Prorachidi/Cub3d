/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 11:16:42 by murachid          #+#    #+#             */
/*   Updated: 2021/02/26 11:16:45 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"

void	sprite_util_one(int i, int j, t_sprite *visiblesprites)
{
	t_sprite	temp;

	temp = visiblesprites[i];
	visiblesprites[i] = visiblesprites[j];
	visiblesprites[j] = temp;
}

void	sprite_util(int x, int y, t_sprite *sprite, t_data *data)
{
	g_sp.distance_fromt_top = y +
	(g_sp.sprite_height / 2) - (g_data.h / 2);
	g_sp.textureffset_y = g_sp.distance_fromt_top
	* (64 / g_sp.sprite_height);
	if (g_sp.textureffset_y <= 64 && g_sp.textureffset_x
	>= 0 && g_sp.textureffset_y >= 0 && g_sp.textureffset_x <= 64)
		g_sp.texel_color = g_textures_sprite.data1[(TEXTURE_WIDTH
		* g_sp.textureffset_y) + g_sp.textureffset_x];
	if (sprite->distance < g_ray[x].distance
	&& g_sp.texel_color != 0)
		my_mlx_pixel_put(data, x, y, g_sp.texel_color);
}
