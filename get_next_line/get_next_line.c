/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:01:51 by murachid          #+#    #+#             */
/*   Updated: 2019/12/14 14:12:14 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_error(int res, char **line, char **s)
{
	if (res < 0)
		return (-1);
	else if (res == 0 && *s == NULL)
	{
		*line = ft_strdup("");
		free(*line);
		return (0);
	}
	else
		return (1);
}

static int	ft_line(char **s, char **line, int res)
{
	int		i;
	char	*ptr;

	i = 0;
	if (ft_error(res, line, s) != 1)
		return (ft_error(res, line, s));
	while ((*s)[i] != '\n' && (*s)[i] != '\0')
		i++;
	if ((*s)[i] == '\n')
	{
		*line = ft_substr(*s, 0, i);
		ptr = ft_strdup(&((*s)[i + 1]));
		free(*s);
		*s = ptr;
	}
	else
	{
		*line = ft_strdup(*s);
		free(*s);
		*s = NULL;
		return (0);
	}
	return (1);
}

int			get_next_line(int fd, char **line)
{
	int				res;
	static	char	*s;
	char			*buff;
	char			*ptr1;

	if (fd < 0 || line == NULL || 32 <= 0)
		return (-1);
	if (!(buff = malloc(32 + 1 * sizeof(char*))))
		return (-1);
	while ((res = read(fd, buff, 32)) > 0)
	{
		buff[res] = '\0';
		if (s == NULL)
			s = ft_strdup(buff);
		else
		{
			ptr1 = ft_strjoin(s, buff);
			free(s);
			s = ptr1;
		}
		if (ft_strchr(s, '\n'))
			break ;
	}
	free(buff);
	return (ft_line(&s, line, res));
}
