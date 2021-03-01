/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap_utilse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 10:11:58 by murachid          #+#    #+#             */
/*   Updated: 2021/02/23 11:08:19 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"

void		file_header(int fd, int file_size, int info)
{
	char header[54];

	ft_bzero(header, 54);
	header[0] = (unsigned int)('B');
	header[1] = (unsigned int)('M');
	header[2] = (unsigned int)(file_size);
	header[3] = (unsigned int)(file_size >> 8);
	header[4] = (unsigned int)(file_size >> 16);
	header[5] = (unsigned int)(file_size >> 24);
	header[10] = (54);
	header[14] = (40);
	header[18] = (unsigned int)(info);
	header[19] = (unsigned int)(info >> 8);
	header[20] = (unsigned int)(info >> 16);
	header[21] = (unsigned int)(info >> 24);
	info = -g_data.w;
	header[22] = (unsigned int)(info);
	header[23] = (unsigned int)(info >> 8);
	header[24] = (unsigned int)(info >> 16);
	header[25] = (unsigned int)(info >> 24);
	header[26] = (1);
	header[28] = (32);
	write(fd, header, 54);
}

void		write_info(int fd, t_data *data)
{
	char	*data1;

	data1 = (char *)data->addr;
	write(fd, data1, (4 * g_data.w * g_data.h));
}

void		screen_shot(t_data *data)
{
	int	fd;
	int	file_size;
	int	info;

	info = g_data.w;
	file_size = 14 + 40 * (g_data.w * g_data.h) * 4;
	fd = open("screenshot.bmp", O_RDWR | O_CREAT, S_IRWXU);
	file_header(fd, file_size, info);
	write_info(fd, data);
	close(fd);
}
