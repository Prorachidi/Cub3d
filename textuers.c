/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textuers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:28:33 by murachid          #+#    #+#             */
/*   Updated: 2021/02/11 15:28:35 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"

void	init_texture2(t_data *data)
{
	open_txt(g_data.so);
	open_txt(g_data.no);
	open_txt(g_data.we);
	open_txt(g_data.ea);
	open_txt(g_data.s);
	g_texture.ptr[0] = mlx_xpm_file_to_image(data->mlx, g_data.we,
	&g_texture.width[0], &g_texture.height[0]);
	g_texture.ptr[1] = mlx_xpm_file_to_image(data->mlx, g_data.ea,
	&g_texture.width[1], &g_texture.height[1]);
	g_texture.ptr[2] = mlx_xpm_file_to_image(data->mlx, g_data.no,
	&g_texture.width[2], &g_texture.height[2]);
	g_texture.ptr[3] = mlx_xpm_file_to_image(data->mlx, g_data.so,
	&g_texture.width[3], &g_texture.height[3]);
	if (g_texture.ptr[0] == NULL || g_texture.ptr[1] == NULL ||
	g_texture.ptr[2] == NULL || g_texture.ptr[3] == NULL)
	{
		printf("Error\n In texture File");
		exit(1);
	}
}

void	init_texture(t_data *data)
{
	init_texture2(data);
	g_texture.data[0] = (int *)mlx_get_data_addr(g_texture.ptr[0],
	&g_texture.bpp, &g_texture.line, &g_texture.endian);
	g_texture.data[1] = (int *)mlx_get_data_addr(g_texture.ptr[1],
	&g_texture.bpp, &g_texture.line, &g_texture.endian);
	g_texture.data[2] = (int *)mlx_get_data_addr(g_texture.ptr[2],
	&g_texture.bpp, &g_texture.line, &g_texture.endian);
	g_texture.data[3] = (int *)mlx_get_data_addr(g_texture.ptr[3],
	&g_texture.bpp, &g_texture.line, &g_texture.endian);
}
