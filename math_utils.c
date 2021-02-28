/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:27:54 by murachid          #+#    #+#             */
/*   Updated: 2021/02/11 15:27:58 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"

float	normalizeangle(float angle)
{
	angle = fmodf(angle, (float)TOW_PI);
	if (angle < 0)
		angle = TOW_PI + angle;
	return (angle);
}

float	distancebetweenpoints(float x1, float y1, float x2, float y2)
{
	float a;

	a = sqrtf((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	return (a);
}

int		len(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
