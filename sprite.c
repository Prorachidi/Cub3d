/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 10:37:08 by murachid          #+#    #+#             */
/*   Updated: 2021/02/26 10:37:30 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"

void	sprite_one(int i, t_sprite *visiblesprites)
{
	g_sp.angle = g_ply.rotationangle - atan2(g_sprites[i].y -
	g_ply.y, g_sprites[i].x - g_ply.x);
	if (g_sp.angle > PI)
		g_sp.angle -= TWO_PI;
	if (g_sp.angle < -PI)
		g_sp.angle += TWO_PI;
	g_sp.angle = fabs(g_sp.angle);
	if (g_sp.angle < (FOV_ANGLE / 2) + 0.2)
	{
		g_sprites[i].visible = 1;
		g_sprites[i].angle = g_sp.angle;
		g_sprites[i].distance = distancebetweenpoints(g_sprites[i].x,
		g_sprites[i].y, g_ply.x, g_ply.y);
		visiblesprites[g_sp.numvisiblesprites] = g_sprites[i];
		g_sp.numvisiblesprites++;
	}
	else
		g_sprites[i].visible = 0;
}

void	sprite_tow(t_sprite *visiblesprites)
{
	int			j;
	int			i;

	i = 0;
	while (i < g_nsprite)
	{
		sprite_one(i, visiblesprites);
		i++;
	}
	i = 0;
	while (i < g_sp.numvisiblesprites - 1)
	{
		j = i + 1;
		while (j < g_sp.numvisiblesprites)
		{
			if (visiblesprites[i].distance < visiblesprites[j].distance)
				sprite_util_one(i, j, visiblesprites);
			j++;
		}
		i++;
	}
}

int		sprite_three(t_sprite *sprite)
{
	int	x;

	g_sp.w = ((g_data.w / 2) / tan(FOV_ANGLE / 2));
	g_sp.perp_distance = sprite->distance * cos(sprite->angle);
	g_sp.sprite_height = (TILE_SIZE / g_sp.perp_distance) * g_sp.w;
	g_sp.sprite_width = g_sp.sprite_height;
	g_sp.sprite_top_y = (g_data.h / 2) - (g_sp.sprite_height / 2);
	g_sp.sprite_top_y = (g_sp.sprite_top_y < 0) ? 0 : g_sp.sprite_top_y;
	g_sp.sprite_bottom_y = (g_data.h / 2) + (g_sp.sprite_height / 2);
	g_sp.sprite_bottom_y = (g_sp.sprite_bottom_y > g_data.h)
	? g_data.h : g_sp.sprite_bottom_y;
	g_sp.sprite_angle = atan2(sprite->y - g_ply.y, sprite->x
	- g_ply.x) - g_ply.rotationangle;
	g_sp.sprite_screen_pos_x = tan(g_sp.sprite_angle) * g_sp.w;
	g_sp.sprite_left_x = (g_data.w / 2) +
	g_sp.sprite_screen_pos_x - (g_sp.sprite_width / 2);
	g_sp.sprite_right_x = g_sp.sprite_left_x + g_sp.sprite_width;
	x = g_sp.sprite_left_x;
	return (x);
}

void	sprite_fore(t_sprite sprite, t_data *data)
{
	int x;
	int y;

	x = sprite_three(&sprite);
	while (x < g_sp.sprite_right_x)
	{
		g_sp.texel_width = (64 / g_sp.sprite_width);
		g_sp.textureffset_x = (x - g_sp.sprite_left_x) * g_sp.texel_width;
		y = g_sp.sprite_top_y;
		while (y < g_sp.sprite_bottom_y)
		{
			if (x > 0 && x < g_data.w && y > 0 && y < g_data.h)
			{
				sprite_util(x, y, &sprite, data);
			}
			y++;
		}
		x++;
	}
}

void	renderspriteprojection(t_data *data)
{
	t_sprite	visiblesprites[g_nsprite];
	int			i;
	t_sprite	sprite;

	i = 0;
	g_sp.numvisiblesprites = 0;
	sprite_tow(visiblesprites);
	while (i < g_sp.numvisiblesprites)
	{
		sprite = visiblesprites[i];
		sprite_fore(sprite, data);
		i++;
	}
}
