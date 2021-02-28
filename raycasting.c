/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:31:37 by murachid          #+#    #+#             */
/*   Updated: 2021/02/11 15:31:40 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"

void	ft_ray(int i)
{
	ft_initialize_ray(i);
	ft_hort(i);
	ft_vert(i);
	ft_check_distence(i);
}

void	ft_ray_cast(t_data *data)
{
	int i;

	i = 0;
	g_ray[i].angle = g_ply.rotationangle - (PI / 6);
	while (i < g_data.w)
	{
		ft_ray(i);
		render3dprojectedwalls(data, i);
		g_ray[i + 1].angle = g_ray[i].angle + (FOV_ANGLE / g_data.w);
		i++;
	}
}
