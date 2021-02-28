/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 10:56:29 by murachid          #+#    #+#             */
/*   Updated: 2021/02/24 10:56:32 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"

void	ft_tt(char **tab, int ab)
{
	int		len;
	char	**t;

	t = ft_split(tab[ab], ' ');
	len = check_len(t);
	array_free(t);
	if (len != 2)
		error_color_masseg();
}

void	ft_yah(char **tab, int ab)
{
	int		len;
	char	**t;
	int		i;
	int		c;

	i = -1;
	c = 0;
	while (tab[ab][++i])
		if (tab[ab][i] == ',')
			c += 1;
	if (c != 2)
		error_color_masseg();
	t = ft_split(tab[ab], ',');
	len = check_len(t);
	array_free(t);
	if (len != 3)
		error_color_masseg();
}

void	color_error_2(char **tab, int ab)
{
	int	a;
	int	c;

	c = 0;
	a = 2;
	if (tab[ab][1] != ' ')
		error_color_masseg();
	ft_tt(tab, ab);
	ft_yah(tab, ab);
	error_msg_2();
}

void	color_error_1(char **tab, int b, int i, int ab)
{
	char	*s;

	s = ft_substr(tab[ab], b, i);
	if (!ft_all_digit(s))
		error_color_masseg();
	g_color.bb = ft_atoi(s);
	free(s);
	color_error_2(tab, ab);
}
