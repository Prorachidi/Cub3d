/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:28:19 by murachid          #+#    #+#             */
/*   Updated: 2021/02/11 15:28:21 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"

void	resolution_error(char **tab, int ab)
{
	int		i;

	i = 1;
	if (tab[ab][1] != ' ')
	{
		printf("Error\nin resolution");
		exit(1);
	}
	while (tab[ab][i] != '\0')
	{
		if (tab[ab][i] >= 58 && tab[ab][i] <= 126)
		{
			printf("Error\ncharacter In resolution");
			exit(1);
		}
		i++;
	}
}

int		check_len(char **s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft(char **tab, int ab)
{
	char	**t;
	int		len;

	t = ft_split(tab[ab], ' ');
	len = check_len(t);
	array_free(t);
	if (len != 3)
	{
		printf("error\nin resolutionn\n");
		exit(1);
	}
}

void	tet(char *r_one, char *r_two)
{
	g_data.w = ft_atoi_res(r_one);
	g_data.h = ft_atoi_res(r_two);
	free(r_one);
	free(r_two);
}

void	ft_resolution(char **tab, int i1)
{
	int		i;
	int		a;
	int		b;
	char	*r_one;
	char	*r_two;

	ft(tab, i1);
	resolution_error(tab, i1);
	i = 1;
	a = 0;
	while (tab[i1][i] == ' ')
		i++;
	b = i;
	while (tab[i1][b] != ' ')
	{
		b++;
		a++;
	}
	r_one = ft_substr(tab[i1], i, a);
	while (tab[i1][i++] != '\0')
		a++;
	a -= b;
	r_two = ft_substr(tab[i1], b, a);
	tet(r_one, r_two);
}
