/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 14:45:40 by murachid          #+#    #+#             */
/*   Updated: 2021/02/26 14:45:42 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"

void	fonction(int i1, int a, char **tab)
{
	int		i;
	int		b;

	i = 0;
	b = a + 1;
	a++;
	while (tab[i1][a] != '\0')
	{
		i++;
		a++;
	}
	color_error_1(tab, b, i, i1);
}
