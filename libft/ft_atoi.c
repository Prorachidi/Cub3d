/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:36:24 by murachid          #+#    #+#             */
/*   Updated: 2019/10/30 15:03:30 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
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
	if (nbr < 0)
		return (abs > 0 ? -1 : 0);
	return (abs * nbr);
}
