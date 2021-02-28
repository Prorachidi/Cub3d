/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:28:06 by murachid          #+#    #+#             */
/*   Updated: 2021/02/11 15:28:08 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"

int		fuu(void)
{
	int		ii;
	int		fd;
	char	*line;
	int		j;

	j = 1;
	ii = 0;
	fd = open("map.cub", O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nin fd");
		exit(1);
	}
	while (j > 0)
	{
		j = get_next_line(fd, &line);
		if (j == 0 && ii == 0)
		{
			printf("error\nempty file");
			exit(1);
		}
		free(line);
		ii++;
	}
	return (ii);
}

char	**read_line(void)
{
	char	*line;
	char	**p_line;
	int		fd;
	int		i;
	int		oo;

	oo = fuu() + 2;
	i = 0;
	fd = open("map.cub", O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nin fd");
		exit(1);
	}
	if (!(p_line = malloc(oo * sizeof(char *))))
		return (NULL);
	while (get_next_line(fd, &line))
	{
		if (line != '\0')
			p_line[i++] = line;
	}
	p_line[i] = line;
	i++;
	p_line[i] = NULL;
	return (p_line);
}

int		read_file(void)
{
	int		i;
	int		j;
	int		ab;
	char	**tab;

	i = 0;
	j = 0;
	ab = 0;
	tab = read_line();
	check_cub(tab);
	read_map(tab);
	array_free(tab);
	return (0);
}
