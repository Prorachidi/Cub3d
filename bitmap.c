/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 10:05:31 by murachid          #+#    #+#             */
/*   Updated: 2021/02/20 10:05:35 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"

void	massege_error_one(void)
{
	printf("error\nduplicate dot\n");
	exit(1);
}

void	massege_error_two(void)
{
	perror("Error\nPlease insert the correct map that ends with .cub");
	exit(1);
}

void	arg_check2(char *s1, char **s2)
{
	int		i;

	i = 0;
	while ("cub"[i] != '\0')
	{
		if (s2[1][i] != "cub"[i] || ft_strlen(s2[1]) != 3)
		{
			perror("Error\nPlease Insert the correct map using .cub");
			exit(1);
		}
		i++;
	}
	g_data.mapname = s1;
	i = 0;
	while (s2[i] != NULL)
	{
		free(s2[i]);
		i++;
	}
	free(s2);
}

void	arg_check(char *s1)
{
	char	**s2;
	int		a;
	int		i;
	int		len;

	a = 0;
	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == '.' && s1[i + 1] != '\0' && s1[i + 1] == 'c')
		{
			a = 1;
			s2 = ft_split(s1, '.');
			len = check_len(s2);
			if (len != 2)
				massege_error_one();
		}
		i++;
	}
	if (a == 0)
		massege_error_two();
	if (s2[1] != NULL)
		arg_check2(s1, s2);
	else
		error_msg();
}

void	arg_save_check(char *save)
{
	int i;

	i = 0;
	while ("--save"[i] != '\0')
	{
		if (save[i] != "--save"[i] || ft_strlen(save) != 6)
		{
			perror("Error\nWrong flag");
			exit(1);
		}
		i++;
	}
	g_ply.saved = 1;
}
