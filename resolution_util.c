/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:15:33 by murachid          #+#    #+#             */
/*   Updated: 2021/02/25 16:15:37 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"

int		ft_atoi_res(const char *str)
{
	int		abs;
	long	nbr;

	abs = 1;
	nbr = 0;
	while (*str == ' ' || *str == '\n' || *str == '\f'
			|| *str == '\r' || *str == '\t' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			abs = -1;
		str++;
	}
	while (ft_isdigit((int)*str))
	{
		nbr = nbr * 10 + *str - '0';
		str++;
	}
	if (nbr <= 10000 && nbr >= 0)
		return (abs * nbr);
	else
		return (10000);
}
