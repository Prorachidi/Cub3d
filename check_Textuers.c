/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textuers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:27:10 by murachid          #+#    #+#             */
/*   Updated: 2021/02/11 15:27:13 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"

void	check_tex(char **text2, int check)
{
	int		i;

	i = 0;
	while ("xpm"[i] != '\0' && check == 1)
	{
		if (text2[1][i] != "xpm"[i] || ft_strlen(text2[1]) != 3)
		{
			printf("Error\nin textures");
			exit(1);
		}
		i++;
	}
	i = 0;
	if (check == 1)
	{
		while (text2[i] != NULL)
		{
			free(text2[i]);
			i++;
		}
		free(text2);
	}
}

void	get_texture_error(char *text)
{
	char	**text2;
	int		i;
	int		check;

	i = 1;
	check = 0;
	while (text[i] != '\0')
	{
		if (text[i] == '.' && text[i + 1] != '\0' && text[i + 1] == 'x')
		{
			check = 1;
		}
		i++;
	}
	if (check == 1)
		text2 = ft_split(text, '.');
	if (check != 1)
		text2 = NULL;
	check_tex(text2, check);
}

char	*read_textures(char **tab, int i, int a, int ab)
{
	char	*text1;
	char	*text;

	text = ft_substr(tab[ab], i, a);
	text1 = ft_strtrim1(text, " ");
	get_texture_error(text1);
	return (text1);
}

char	*texture(char **tab, int ab)
{
	char	*text1;
	int		i;
	int		a;

	a = 0;
	if (tab[ab][0] == 'S' && tab[ab][1] == ' ')
		i = 2;
	else
		i = 3;
	while (tab[ab][a] != '\0')
		a++;
	text1 = read_textures(tab, i, a, ab);
	return (text1);
}

void	test_texture(char **tab, int ab)
{
	if (tab[ab][0] == 'N' && tab[ab][1] == 'O')
	{
		g_data.so = texture(tab, ab);
		g_check_color.north++;
	}
	else if (tab[ab][0] == 'S' && tab[ab][1] == 'O')
	{
		g_data.no = texture(tab, ab);
		g_check_color.south++;
	}
	else if (tab[ab][0] == 'W' && tab[ab][1] == 'E')
	{
		g_data.ea = texture(tab, ab);
		g_check_color.west++;
	}
	else if (tab[ab][0] == 'E' && tab[ab][1] == 'A')
	{
		g_data.we = texture(tab, ab);
		g_check_color.east++;
	}
	else if (tab[ab][0] == 'S' && tab[ab][1] == ' ')
	{
		g_data.s = texture(tab, ab);
		g_check_color.sprite++;
	}
}
