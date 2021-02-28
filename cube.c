/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 11:27:38 by murachid          #+#    #+#             */
/*   Updated: 2021/02/26 11:27:41 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"

void	save_cordinate(int i, int j, int id)
{
	g_sprites[id].x = j * TILE_SIZE + 30;
	g_sprites[id].y = i * TILE_SIZE + 30;
	g_spriteone[id].dst = (float)sqrt((g_spriteone[id].x - g_ply.x) *
	(g_spriteone[id].x - g_ply.x) +
	(g_spriteone[id].y - g_ply.y) *
	(g_spriteone[id].y - g_ply.y));
}

void	get_sprite_pos(void)
{
	int	i;
	int	j;
	int	id;

	i = 0;
	id = 0;
	while (i < g_data.vert)
	{
		j = 0;
		while (j < g_data.horz)
		{
			if (g_data.map[i][j] == '2')
			{
				if (id > 3500)
					error_msg_1();
				g_sprites[id].y = j * TILE_SIZE + 32;
				g_sprites[id].x = i * TILE_SIZE + 32;
				save_cordinate(i, j, id);
				id++;
			}
			j++;
		}
		i++;
	}
}

void	ft_draw(t_data *data)
{
	int	i;

	i = 0;
	ft_update(data);
	ft_ray_cast(data);
	get_sprite_pos();
	renderspriteprojection(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

void	main_util(t_data *data)
{
	read_file();
	ft_initialize_player();
	all_errors();
	data->width = g_data.w;
	data->height = g_data.h;
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx,
	data->width, data->height, "cub3D");
	data->img = mlx_new_image(data->mlx, data->width, data->height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
	&data->line_length, &data->endian);
	init_texture(data);
	g_textures_sprite.ptr1 = mlx_xpm_file_to_image(data->mlx, g_data.s,
	&g_textures_sprite.width1, &g_textures_sprite.height1);
	if (g_textures_sprite.ptr1 == NULL)
		error_msg_1();
	g_textures_sprite.data1 = (int *)mlx_get_data_addr(
	g_textures_sprite.ptr1,
	&g_textures_sprite.bpp1, &g_textures_sprite.line1,
	&g_textures_sprite.endian1);
	ft_draw(data);
}

int		main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2 || argc == 3)
	{
		main_util(&data);
		arg_check(argv[1]);
		checkpathvalid(argv[1]);
		if (argc == 3)
			arg_save_check(argv[2]);
		if (argc == 3)
			utile(&data);
		if (g_ply.saved == 0)
			mlx_hook(data.mlx_win, KEY_PRESS, 0, ft_key_press, &data);
		mlx_loop(data.mlx);
		main_util(&data);
		if (argc == 3)
			utile(&data);
		if (g_ply.saved == 0)
			mlx_hook(data.mlx_win, KEY_PRESS, 0, ft_key_press, &data);
		mlx_loop(data.mlx);
	}
	else
		printf("error\nPlease insert the map's name.");
}
