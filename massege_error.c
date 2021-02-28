/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   massege_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 11:12:54 by murachid          #+#    #+#             */
/*   Updated: 2021/02/27 11:12:59 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"

void	error_msg(void)
{
	printf("Error\n in the map");
	exit(1);
}

void	error_msg_1(void)
{
	printf("Error\n in textuer");
	exit(1);
}

void	error_color_masseg(void)
{
	perror("Error : RGB > 255 or RGB < 0 or character");
	exit(-1);
}

void	error_msg_2(void)
{
	if (g_color.bb > 255 || g_color.g > 255 || g_color.r > 255)
		error_color_masseg();
	if (g_color.bb < 0 || g_color.g < 0 || g_color.r < 0)
		error_color_masseg();
}
